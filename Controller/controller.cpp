#include "Header/controller.h"


Controller::Controller(QObject* parent): QObject(parent){
    //costruire controller
    MainW = new MainWindow();

    /*
     * -Vecchio modo connessione segnali, funziona ma se possibile da evitare
     * connect(MainW, SIGNAL(OpenSettingsRequest()), this, SLOT(openSettings()));
     * -nuova modalità connessione qt5, consigliata*/
    connect(MainW, &MainWindow::OpenSettingsRequest, this, &Controller::openSettings);
}

void Controller::ShowMainWindow() const {MainW->show();}


void Controller::openSettings(){
    emit MainW->OpenSettingsWindow();
}
