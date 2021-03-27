#include "Header\mainwindow.h"

//test
#include <QVBoxLayout>


MainWindow::MainWindow(QWidget *parent): QWidget(parent){
    //settaggio proprietà finestra
    setWindowTitle ("QtMiner");
    setMinimumSize(350,300);

    startGame = new QPushButton(tr("Inizia a giocare!"), this);
    settings = new QPushButton(tr("Impostazioni"),this);
    settings->setFixedSize(70,70);

    QVBoxLayout *Vl= new QVBoxLayout(this);

    Vl->addWidget(settings,Qt::AlignRight);
    Vl->addWidget(startGame,Qt::AlignBottom);
}
