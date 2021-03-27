#include "Header/controller.h"

Controller::Controller(QObject* parent): QObject(parent){
    //costruire controller
    MainW = new MainWindow();

}

void Controller::ShowMainWindow() const {MainW->show();}
