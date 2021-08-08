
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
    qDebug()<<"Controller: sto per collegare cheImmagineHo nel Controller";
    connect(MainW, &MainWindow::RimbalzoCheImmagineHo, modelBoard, &model::ModelBoard::getHandImage);
    qDebug()<<"Controller: collegamento Controller riuscito";
    connect(modelBoard, &model::ModelBoard::CambiaImmagineMano, MainW, &MainWindow::UpdateCardMano);

    MainW->show();
    //MainW->createObjVectors();
    //qDebug()<<"inizializzazione da Controller vettore riuscita";
}

void Controller::openSettings() {
    emit MainW->OpenSettingsWindow();
}

void Controller::openTutorial(){
    emit MainW->OpenTutorialWindow();
}

void Controller::openBoardWindow(){
    //elimina tutte le carte per permettere di giocare una nuova partita
    modelBoard->addCardtoVectors();
    //modelBoard->deleteAllCards();  QUESTO CAUSARE SEG. FAULT
    emit MainW->OpenGameWindow();  
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

