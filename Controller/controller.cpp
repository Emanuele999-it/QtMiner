
#include "Header/controller.h"

controller::Controller::Controller(QObject* parent): QObject(parent){
    //costruire controller
    //MainW = new MainWindow();

    /*
     * -Vecchio modo connessione segnali, funziona ma se possibile da evitare
     * connect(MainW, SIGNAL(OpenSettingsRequest()), this, SLOT(openSettings()));
     * -nuova modalità connessione qt5, consigliata*/
    //connect(MainW, &MainWindow::OpenSettingsRequest, this, &Controller::openSettings);
}

//void controller::Controller::ShowMainWindow() const {MainW->show();}


//void controller::Controller::openSettings(){
    //emit MainW->OpenSettingsWindow();
//}
