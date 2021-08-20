#include "View/Header/boardwindow.h"

#include <QDebug>

BoardWindow::BoardWindow(nat num, QWidget *p) : QWidget(p), celle(num), mano(false), board(false)
{
    setWindowTitle(tr("Qtminer"));
    resize(750, 720);

    b = new view::Board(celle);
    m = new view::Mano(7);

    scambioMB = new QPushButton("Scambia");
    scarta = new QPushButton ("Scarta");
    scambioMB->setDisabled(true);
    scarta->setDisabled(true);

    mosse = new QLCDNumber();
    //mosse->setSegmentStyle(QLCDNumber::Filled);

    //LAYOUT
    QVBoxLayout *Vlayout = new QVBoxLayout(this);
    QHBoxLayout *h = new QHBoxLayout();

    Vlayout->addLayout(h);

    h->addWidget(b);

    QHBoxLayout *Hh=new QHBoxLayout();
    Vlayout->addLayout(Hh);
    Hh->addWidget(m);
    v = new QVBoxLayout();
    Hh->addLayout(v);
    v->addWidget(scambioMB);
    v->addWidget(scarta);
    Hh->addWidget(mosse);

    b->addelVec(celle);

    m->addelVec(7);

    show();

    connect(b, &view::Board::numCasellaCliccataBoard, this, &BoardWindow::cellaSelezionata);
    connect(m, &view::Mano::numCasellaCliccataBoard, this, &BoardWindow::cellaSelezionata);
    connect(b, &view::Board::numCasellaCliccataBoard, this, &BoardWindow::activateButton);
    connect(m, &view::Mano::numCasellaCliccataBoard, this, &BoardWindow::activateButton);
    connect(scambioMB, &QPushButton::clicked, this ,&BoardWindow::controlloCarteDaScambiare );
    connect(scambioMB, &QPushButton::clicked, m, &view::Mano::removeStylesheetButton);
    connect(scambioMB, &QPushButton::clicked, b, &view::Board::removeStylesheetButton);
    connect(scarta, &QPushButton::clicked, this, &BoardWindow::scartaCarta);
    connect(scarta, &QPushButton::clicked, b, &view::Board::removeStylesheetButton);
    connect(scarta, &QPushButton::clicked, m, &view::Mano::removeStylesheetButton);

}

void BoardWindow::cellaSelezionata(nat p){

    QObject* obj= sender();
    nat funcSender=0;
    if(dynamic_cast<view::Mano*>(obj)){
        funcSender=1;
    }
    emit rimbalzoSegnaleCasellaSelezionataBoard(p,funcSender);
}

void BoardWindow::activateButton(nat i){
    Q_UNUSED(i)
    QObject* obj = sender();
    if(dynamic_cast<view::Mano*>(obj)){
        mano=true;
        scarta->setDisabled(false);
    }

    else{
        board=true;
    }

    if(mano && board)
        scambioMB->setDisabled(false);
}

void BoardWindow::disableButton(){
    scambioMB->setDisabled(true);
    scarta->setDisabled(true);
    mano=false;
    board=false;
}

void BoardWindow::aggiornamentoView(nat posMano, nat PosBoard, QString CartaMano, QString CartaBoard, nat behaviour){

    disableButton();

    // quando riceve carta tunnel o blocco
    if(behaviour == 0){
        b->addCardBoard(PosBoard,CartaBoard);
        m->addCardBoard(posMano,CartaMano);
    }
    //quando riceve carta CloneCards
    else if(behaviour == 1){
        m->addCardBoard(posMano,CartaMano);
    }
    //quando riceve carta Crollo
    else{
        m->addCardBoard(posMano,CartaMano);
        b->addCardBoard(PosBoard,b->getImage(PosBoard));
    }

    //Turno avversario:
    avviaMossaAI();
}

void BoardWindow::closeEvent(QCloseEvent *event){
    Q_UNUSED(event)
    emit chiusuraBoardW();
}

void BoardWindow::aggiornamentoCartaMano(nat a, QString c, nat i){
    if(i==1){
        disableButton();
        //Turno avversario:
        avviaMossaAI();
    }
    m->addCardBoard(a,c);

}

void BoardWindow::addElVectors(){

    b->addElGrid(celle);
    m->addElGrid(7);
    for(nat counter=0; counter<7; counter++){
        emit cheImmagineHo(counter);
    }
}

void BoardWindow::controlloCarteDaScambiare(){
    //controllo che posizione non sia una cella di arrivo
    emit scambiaScarte(m->getPosizione(),b->getPosizione());
}

void BoardWindow::avviaMossaAI(){
    //controllo che posizione non sia una cella di arrivo
    mosse->display((mosse->value())+1);
    emit mossaAI();
}

void BoardWindow::aggiornamentoBoardAI(nat posAI, QString imgAI){
    b->addCardBoard(posAI,imgAI);
}

