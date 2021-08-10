#include "View/Header/boardwindow.h"

#include <QDebug>

BoardWindow::BoardWindow(QWidget *p, nat num) : QWidget(p), celle(num)
{
    setWindowTitle(tr("Qtminer"));
    resize(1280, 720);

    b = new view::Board(celle);
    m = new view::Mano(7);

    scambioMB = new QPushButton("Scambia");

    mosse = new QLCDNumber(3);
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

void BoardWindow::aggiornamentoView(nat posMano, nat PosBoard, QString CartaMano, QString CartaBoard, nat behaviour){
    // quando riceve carta tunnel o blocco
    if(behaviour == 0){
        b->addCardBoard(PosBoard,CartaBoard);
        m->addCardMano(posMano,CartaMano);
    }
    //quando riceve carta CloneCards
    else if(behaviour == 1){
        m->addCardMano(posMano,CartaMano);
    }
    //quando riceve carta Crollo
    else{
        m->addCardMano(posMano,CartaMano);
        b->addCardBoard(PosBoard,b->vettoreCaselleBoard[0]->getDefautImage());
    }
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
    connect(scambioMB, &QPushButton::clicked, this ,&BoardWindow::controlloCarteDaScambiare );
}

void BoardWindow::controlloCarteDaScambiare(){
    //controllo che posizione non sia una cella di arrivo
    emit scambiaScarte(m->getPosizione(),b->getPosizione());
}
