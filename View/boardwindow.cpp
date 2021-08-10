#include "View/Header/boardwindow.h"

#include <QDebug>

BoardWindow::BoardWindow(QWidget *p, nat num) : QWidget(p), celle(num)
{
    setWindowTitle(tr("Qtminer"));
    resize(1280, 720);

    b = new view::Board(celle);
    m = new view::Mano(7);

    scambioMB = new QPushButton("Scambia");
    prossimo = new QPushButton ("Prossimo Turno");

    mosse = new QLCDNumber();
    mosse->setSegmentStyle(QLCDNumber::Filled);

    connect(b, &view::Board::numCasellaCliccataBoard, this, &BoardWindow::rimbalzoSegnaleCasellaSelezionataBoard);
    connect(m, &view::Mano::numCasellaCliccataMano, this, &BoardWindow::rimbalzoSegnaleCasellaSelezionataMano);

    //connect(scambioMB, &QPushButton::clicked,);


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

void BoardWindow::aggiornamentoView(nat posMano, nat PosBoard, QString CartaMano, QString CartaBoard){

    // mettere carta CartaBoard in posizione posBoard in b+ù
    b->addCardBoard(PosBoard,CartaBoard);

    // mettere carta CartaMano in posizione posMano in m
    m->addCardMano(posMano,CartaMano);
}

void BoardWindow::closeEvent(QCloseEvent *event){
    Q_UNUSED(event)
    emit chiusuraBoardW();
}

void BoardWindow::aggiornamentoCartaMano(nat a, QString c){
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
        emit cheImmagineHo(counter);
    }

    GMLayout->addWidget(scambioMB,1,8);
    GMLayout->addWidget(prossimo,1,9);
    GMLayout->addWidget(mosse,2,9);
    connect(scambioMB, &QPushButton::clicked, this ,&BoardWindow::controlloCarteDaScambiare );
    connect(prossimo, &QPushButton::clicked, this, &BoardWindow::avviaMossaAI);
}

void BoardWindow::controlloCarteDaScambiare(){
    //controllo che posizione non sia una cella di arrivo
    emit scambiaScarte(m->getPosizione(),b->getPosizione());
}

void BoardWindow::avviaMossaAI(){
    //controllo che posizione non sia una cella di arrivo
    mosse->display((mosse->value())+1);
    emit mossaAI(mosse->value());
}

