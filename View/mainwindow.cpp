#include "Header\mainwindow.h"

//test
#include <QVBoxLayout>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent): QWidget(parent){
    //settaggio proprietà finestra
    setWindowTitle ("QtMiner");
    setMinimumSize(350,300);

    startGame = new QPushButton(tr("Inizia a giocare!"), this);

    settings = new QPushButton(this);
    settings->setIcon(QIcon(":/Img/settings.png"));
    settings->setIconSize(QSize(65, 65));
    settings->setFixedSize(70,70);

    QVBoxLayout *Vl= new QVBoxLayout(this);

    Vl->addWidget(settings,Qt::AlignRight);
    Vl->addWidget(startGame,Qt::AlignBottom);

    connect(settings, SIGNAL(clicked()), this, SLOT(OpenSettings()));

}

void MainWindow::OpenSettings() const{
    QFile file("readme2.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }



    file.close();

}
