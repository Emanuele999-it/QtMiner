﻿
#include "Header/controller.h"

Controller::Controller(QObject* parent): QObject(parent), MainW(new MainWindow()) {
    //costruire controller
    MainW->show();
=======
    //MainW = new MainWindow();

    /*
     * -Vecchio modo connessione segnali, funziona ma se possibile da evitare
     * connect(MainW, SIGNAL(OpenSettingsRequest()), this, SLOT(openSettings()));
     * -nuova modalità connessione qt5, consigliata*/

    connect(MainW, &MainWindow::SettingsRequest, this, &Controller::openSettings);
    connect(MainW, &MainWindow::TutorialRequest, this, &Controller::openTutorial);

    //connect(MainW, &MainWindow::OpenSettingsRequest, this, &Controller::openSettings);
}

//void controller::Controller::ShowMainWindow() const {MainW->show();}

}

<<<<<<< HEAD
void Controller::openSettings() {
    emit MainW->OpenSettingsWindow();
}

void Controller::openTutorial(){
    emit MainW->OpenTutorialWindow();
}
=======
//void controller::Controller::openSettings(){
    //emit MainW->OpenSettingsWindow();
//}
>>>>>>> ale
