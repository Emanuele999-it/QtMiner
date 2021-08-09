
#include "Header/controller.h"

#include <QDebug>

Controller::Controller(QObject* parent): QObject(parent), MainW(new MainWindow()) {
    //costruire controller

    // qui in modelBoard possiamo mettere la grandezza della board che si preferisce
    // e lo si può fare con una variabile data dall'utente dalle impostazioni
    modelBoard = new model::ModelBoard(7,40);



    //MainW = new MainWindow();

    /*
     * -Vecchio modo connessione segnali, funziona ma se possibile da evitare
     * connect(MainW, SIGNAL(OpenSettingsRequest()), this, SLOT(openSettings()));
     * -nuova modalità connessione qt5, consigliata*/

    connect(MainW, &MainWindow::SettingsRequest, this, &Controller::openSettings);
    connect(MainW, &MainWindow::TutorialRequest, this, &Controller::openTutorial);
    connect(MainW, &MainWindow::GameRequest, this, &Controller::openBoardWindow);
    //da controllare potrebbero essere sbagliati
    connect(MainW, &MainWindow::casellaBoardSelezionata, this, &Controller::cambiaCellaBoard);
    connect(MainW, &MainWindow::casellaManoSelezionata, this, &Controller::cambiaCellaMano);

    //connessione tra model e view (aggiornamento carta)
    connect(modelBoard, &model::ModelBoard::CambiaPosizioneManoBoard, MainW, &MainWindow::UpdateViewfromModel);
    connect(MainW, &MainWindow::RimbalzoCheImmagineHo, modelBoard, &model::ModelBoard::getHandImage);
    connect(modelBoard, &model::ModelBoard::CambiaImmagineMano, MainW, &MainWindow::UpdateCardMano);

    //connect(modelBoard, &model::ModelBoard::closeSignal, this, &Controller::chiusuraGame);
    connect(MainW,&MainWindow::chiusuraBoardWRimbalzo, modelBoard,&model::ModelBoard::deleteAllCards);
    MainW->show();
    //MainW->createObjVectors();
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
    //elimina tutte le carte per permettere di giocare una nuova partita
    modelBoard->deleteAllCards();
}

void Controller::cambiaCellaBoard(nat y){
    emit modelBoard->evidenziaCellaBoard(y);
}

void Controller::cambiaCellaMano(nat y){
    emit modelBoard->evidenziaCellaMano(y);
}

//void controller::Controller::openSettings(){
    //emit MainW->OpenSettingsWindow();
//}

