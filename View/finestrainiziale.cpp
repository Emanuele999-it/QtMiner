#include "View/Header/finestrainiziale.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QWidget>

FinestraIniziale::FinestraIniziale()
{
    // scene="Hello, world!";

}

void FinestraIniziale::visualizza(){

    QWidget q;

    QLabel f;
    f.setText("ciao");


    QHBoxLayout d=new QHBoxLayout(this);
    d.add
    //d.addItem(f);

    this->setLayout(d);
    this->show();
}
