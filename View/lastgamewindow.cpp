#include "Header/lastgamewindow.h"

#include <QDebug>

LastGameWindow::LastGameWindow(QDialog *parent): QDialog(parent){
    hide();
    QVBoxLayout * vl= new QVBoxLayout(this);
    ultimaP = new QLabel("Ecco i risultati dell'ultima partita: ");
    grid = new QGridLayout();

    vl->addWidget(ultimaP);
    vl->addLayout(grid);

}

void LastGameWindow::saveLastGame(){

    QFile file("lastgameboard.txt");

    file.open(QIODevice::ReadWrite);

    if(!file.isOpen()){
        qDebug() <<  "- Error, unable to open"  << "for output";
    }

    qDebug() <<  "Victory!" ;
    file.write("c");

    file.close();
}

void LastGameWindow::getLastGame(){
    //salvare numero di celle
    //array con i vari caratteri
    new QFile("lastgameboard.txt");


}
