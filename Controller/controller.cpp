
#include "Header/controller.h"

Controller::Controller(QObject* parent): QObject(parent), MainW(new MainWindow()) {
    //costruire controller
    MainW->show();

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
}

void Controller::openSettings() {
    emit MainW->OpenSettingsWindow();
}

void Controller::openTutorial(){
    emit MainW->OpenTutorialWindow();
}

void Controller::openBoardWindow(){
    //elimina tutte le carte per permettere di giocare una nuova partita
    modelBoard->deleteAllCards();
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

