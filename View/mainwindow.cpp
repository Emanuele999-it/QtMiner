#include "Header\mainwindow.h"

//test
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent): QWidget(parent){

    //settaggio proprietà finestra
    setWindowTitle ("QtMiner");
    setMinimumSize(350,300);

    //creazione bottoni impostazioni / inizio gioco
    startGame = new QPushButton(tr("Inizia a giocare!"), this);
    tutorial = new QPushButton(tr("Tutorial"), this);
    lastGame = new QPushButton(tr("Ultima partita"), this);

    settings = new QPushButton(this);
    settings->setIcon(QIcon(":/Img/settings.png"));
    settings->setIconSize(QSize(40, 40));
    settings->setFixedSize(48,48);

    // set layout visualizzazione
    Vl= new QVBoxLayout(this);

    QHBoxLayout *Hl1=new QHBoxLayout();
    QHBoxLayout *Hl2=new QHBoxLayout();
    Vl->addLayout(Hl1);
    Vl->addLayout(Hl2);

    stackedWidget = new QStackedWidget(this);

    Hl1->addWidget(settings);
    Hl1->setAlignment(Qt::AlignRight | Qt::AlignTop);

    Hl2->addWidget(tutorial);
    Hl2->addWidget(startGame);
    Hl2->addWidget(lastGame);
    Hl2->setAlignment(Qt::AlignCenter);

    connect(settings,&QPushButton::clicked, this, &MainWindow::SettingsRequest);
    connect(tutorial,&QPushButton::clicked, this, &MainWindow::TutorialRequest);
}


void MainWindow::OpenSettingsWindow(){
    //hide();
    settWindow = new SettingsWindow();
    settWindow->show();
}

void MainWindow::OpenTutorialWindow(){

    tWindow = new Tutorialwindow();
    tWindow->exec();
}

