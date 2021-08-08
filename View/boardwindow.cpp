#include "View/Header/boardwindow.h"

#include <QDebug>

BoardWindow::BoardWindow(QWidget *p, nat num) : QWidget(p), celle(num)
{
    setWindowTitle(tr("Qtminer"));
    resize(1280, 720);

    b = new view::Board(celle);
    m = new view::Mano(7);
    connect(b, &view::Board::numCasellaCliccataBoard, this, &BoardWindow::rimbalzoSegnaleCasellaSelezionataBoard);
    connect(m, &view::Mano::numCasellaCliccataMano, this, &BoardWindow::rimbalzoSegnaleCasellaSelezionataMano);

    mosse = new QLCDNumber(3);
    mosse->setSegmentStyle(QLCDNumber::Filled);


    //LAYOUT
    QVBoxLayout *Vlayout = new QVBoxLayout(this);
    //layout board
    GBLayout = new QGridLayout();
    //layout mano
    GMLayout = new QGridLayout();

    Vlayout->addLayout(GBLayout);
    Vlayout->addLayout(GMLayout);


    for(nat counter=0; counter<celle; counter++){
        b->vettoreCaselleBoard.push_back(new view::Casella(counter));
    }

    for(nat counter=0; counter<7; counter++){
        m->vettoreCaselleMano.push_back(new view::Casella(counter));
    }

    show();
}

void BoardWindow::aggiornamentoView(nat posMano, nat PosBoard, QString CartaBoard, QString CartaMano){

    // mettere carta CartaBoard in posizione posBoard in b+ù
    b->addCardBoard(PosBoard,CartaBoard);

    // mettere carta CartaMano in posizione posMano in m
    m->addCardMano(posMano,CartaMano);
}


void BoardWindow::aggiornamentoCartaMano(nat a, QString c){
    qDebug()<<"BoardWindow: arrivato aggiornamento mano";
    m->addCardMano(a,c);
}

void BoardWindow::addElVectors(){

    for(nat counter=0; counter<celle; counter++){
        connect(b->vettoreCaselleBoard[counter],SIGNAL(casellaCliccata(nat)), b, SLOT(selectCardBoard(nat)));
        GBLayout->addWidget(b->vettoreCaselleBoard[counter],counter/5,counter%5);
    }

    for(nat counter=0; counter<7; counter++){
        connect(m->vettoreCaselleMano[counter],SIGNAL(casellaCliccata(nat)), m, SLOT(selectCardMano(nat)));
        GMLayout->addWidget(m->vettoreCaselleMano[counter],1,counter);
        qDebug()<<"BoardWindow: sto per emettere il segnale "<<counter;
        emit cheImmagineHo(counter);
    }
}
