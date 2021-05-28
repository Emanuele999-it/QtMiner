#include "Header/tutorialwindow.h"

#include <QHBoxLayout>

#include <QFile>
#include <QTextStream>

#include <QFileDialog>
#include <QString>
#include <QTextStream>


Tutorialwindow::Tutorialwindow(QWidget*parent): QDialog(parent)
{

    setMinimumSize(350,300);
    setMaximumSize(1280,960);

    l= new QVBoxLayout(this);
    QHBoxLayout *h = new QHBoxLayout();

    text = new QLabel();
    l->addWidget(text);
    l->addLayout(h);

    indietro = new QPushButton(tr("Indietro"));
    avanti = new QPushButton(tr("Avanti"));
    menu = new QPushButton(tr("Finestra principale"));

    h->addWidget(indietro);
    h->addWidget(avanti);
    h->addWidget(menu);

    QFile file(":/readme2.txt");
    QString line;
    if (file.open(QIODevice::ReadOnly)){
        QTextStream stream(&file);
        while (!stream.atEnd()){
            line.append(stream.readLine()+"\n");
        }
       text->setText(line);
    }
    else{
        this->close();
    }
    file.close();



    h->addWidget(indietro);
    h->addWidget(avanti);
    h->addWidget(menu);


    connect(menu,&QPushButton::clicked,this,&Tutorialwindow::CloseWindow);
}

void Tutorialwindow::CloseWindow(){
    close();
}
