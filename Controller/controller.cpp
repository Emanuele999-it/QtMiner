
#include "Header/controller.h"

#include <QDebug>

Controller::Controller(QObject* parent): QObject(parent), MainW(new MainWindow()) {

    // qui in modelBoard possiamo mettere la grandezza della board che si preferisce
    // e lo si può fare con una variabile data dall'utente dalle impostazioni


    buildAndConnectModelView();

    connect(MainW, &MainWindow::SettingsRequest, this, &Controller::openSettings);
    connect(MainW, &MainWindow::TutorialRequest, this, &Controller::openTutorial);
    connect(MainW, &MainWindow::GameRequest, this, &Controller::openBoardWindow);
    //da controllare potrebbero essere sbagliati
    connect(MainW, &MainWindow::casellaBoardSelezionata, this, &Controller::cambiaCellaBoard);

    connect(MainW,&MainWindow::chiusuraBoardWRimbalzo, this, &Controller::chiusuraGame);
    MainW->show();
    //MainW->createObjVectors();
}

void Controller::buildAndConnectModelView(){
    modelBoard = new model::ModelBoard(7,40);
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
    modelBoard->addCardtoVectors();
    emit MainW->OpenGameWindow();  
}

void Controller::chiusuraGame(){
    delete modelBoard;
    buildAndConnectModelView();
}

void Controller::cambiaCellaBoard(nat x, nat y){
    emit modelBoard->evidenziaCellaBoard(x,y);
}


//void controller::Controller::openSettings(){
    //emit MainW->OpenSettingsWindow();
//}

