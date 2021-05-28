#include "Header/controller.h"

Controller::Controller(QObject* parent): QObject(parent), MainW(new MainWindow()) {
    //costruire controller
    MainW->show();
    /*
     * -Vecchio modo connessione segnali, funziona ma se possibile da evitare
     * connect(MainW, SIGNAL(OpenSettingsRequest()), this, SLOT(openSettings()));
     * -nuova modalità connessione qt5, consigliata*/
    connect(MainW, &MainWindow::SettingsRequest, this, &Controller::openSettings);
    connect(MainW, &MainWindow::TutorialRequest, this, &Controller::openTutorial);

}

void Controller::openSettings() {
    emit MainW->OpenSettingsWindow();
}

void Controller::openTutorial(){
    emit MainW->OpenTutorialWindow();
}
