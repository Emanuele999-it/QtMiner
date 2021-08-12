
#include "Header/controller.h"

#include <QDebug>

Controller::Controller(QObject* parent): QObject(parent) {

    // qui in modelBoard possiamo mettere la grandezza della board che si preferisce
    // e lo si può fare con una variabile data dall'utente dalle impostazioni

    boardDimension=40;
    MainW = new MainWindow();


    connect(MainW, &MainWindow::SettingsRequest, this, &Controller::openSettings);
    connect(MainW, &MainWindow::TutorialRequest, this, &Controller::openTutorial);
    connect(MainW, &MainWindow::GameRequest, this, &Controller::openBoardWindow);
    //da controllare potrebbero essere sbagliati
    connect(MainW, &MainWindow::casellaBoardSelezionata, this, &Controller::cambiaCellaBoard);

    connect(MainW, &MainWindow::chiusuraBoardWRimbalzo, this, &Controller::chiusuraGame);
    connect(MainW, &MainWindow::changeBoardDimension, this, &Controller::cambioDimensioniBoard);
    MainW->show();
    //MainW->createObjVectors();
}

void Controller::buildAndConnectModelView(){
    qDebug()<<"Controller: model con dim: "<<boardDimension;
    modelBoard = new model::ModelBoard(7,boardDimension);
    //connessione tra model e view (aggiornamento carta)
    connect(modelBoard, &model::ModelBoard::CambiaPosizioneManoBoard, MainW, &MainWindow::UpdateViewfromModel);
    connect(MainW, &MainWindow::rimbalzoScambioCarteMB, modelBoard, &model::ModelBoard::posiziona);
    connect(MainW, &MainWindow::RimbalzoCheImmagineHo, modelBoard, &model::ModelBoard::getHandImage);
    connect(modelBoard, &model::ModelBoard::CambiaImmagineMano, MainW, &MainWindow::UpdateCardMano);
    connect(modelBoard, &model::ModelBoard::changeCardsfailed, MainW, &MainWindow::changeCardsFailed);
}

void Controller::openSettings() {
    emit MainW->OpenSettingsWindow();
}

void Controller::openTutorial(){
    emit MainW->OpenTutorialWindow();
}

void Controller::openBoardWindow(){
    buildAndConnectModelView();
    modelBoard->addCardtoVectors();
    emit MainW->OpenGameWindow(boardDimension);
}

void Controller::chiusuraGame(){
    delete modelBoard;
}

void Controller::cambiaCellaBoard(nat x, nat y){
    emit modelBoard->evidenziaCellaBoard(x,y);
}

void Controller::cambioDimensioniBoard(nat i){
    boardDimension=i;
}

//void controller::Controller::openSettings(){
    //emit MainW->OpenSettingsWindow();
//}

