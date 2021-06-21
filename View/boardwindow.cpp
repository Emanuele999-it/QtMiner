include "View/Header/finestrainiziale.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QWidget>
#include <QLCDNumber>
#include "View/Header/board.h"

FinestraIniziale:: FinestraIniziale(QWidget *p) : QWidget(p), b(new Board) //Lo devo creare sullo stack o sparisce
{
    mosse = new QLCDNumber(5);
    mosse->setSegmentStyle(QLCDNumber::Filled);

    QGridLayout *layout = new QGridLayout;
    //layout->addWidget(End, 4, 0);
    layout->addWidget(b, 0, 1, 6, 1); //la cosa che voglio io, la board
    setLayout(layout);

    setWindowTitle(tr("Qtminer"));
    resize(1920, 720);

}

void FinestraIniziale::visualizza(){

}
