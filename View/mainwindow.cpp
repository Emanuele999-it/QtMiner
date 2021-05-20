#include "Header\mainwindow.h"

//test
#include <QVBoxLayout>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent): QWidget(parent){

    //settaggio proprietà finestra
    setWindowTitle ("QtMiner");
    setMinimumSize(350,300);

    //creazione bottoni impostazioni / inizio gioco
    startGame = new QPushButton(tr("Inizia a giocare!"), this);

    settings = new QPushButton(this);
    settings->setIcon(QIcon(":/Img/settings.png"));
    settings->setIconSize(QSize(40, 40));
    settings->setFixedSize(48,48);

    // set layout visualizzazione
    QVBoxLayout *Vl= new QVBoxLayout(this);

    QHBoxLayout *Hl1=new QHBoxLayout(this);
    QHBoxLayout *Hl2=new QHBoxLayout(this);
    Vl->addLayout(Hl1);
    Vl->addLayout(Hl2);

    Hl1->addWidget(settings);
    Hl1->setAlignment(Qt::AlignRight | Qt::AlignTop);


    Hl2->addWidget(startGame);
    Hl2->setAlignment(Qt::AlignCenter);

    connect(settings, SIGNAL(clicked()), this, SIGNAL(OpenSettingsRequest()));

}

//void MainWindow::OpenSettingsRequest(){
//    emit OpenSettingsWindow();
//}


//void MainWindow::OpenSettingsWindow(){
//    settWindow = new MainSettingsWindow(this);
//    settWindow->show();
//}
