#include "View/Header/boardwindow.h"

BoardWindow::~BoardWindow(){
    if(b) delete b;
    if(m) delete m;
    if(mosse) delete mosse;
    if(v) delete v;
    if(scambioMB) delete scambioMB;
    if(scarta) delete scarta;
}

BoardWindow::BoardWindow(const BoardWindow &Board){
    celle=Board.celle;
    mano=Board.mano;
    board=Board.board;

    setScreenGeometry();

    setWindowTitle ("QtMiner - Giochiamo!!!");
    setFixedSize(720, 800);
    setWindowFlag(Qt::Dialog);
    setMaximumSize(800,950);

    b = Board.b;
    m = Board.m;

    nome=Board.nome;
    scambioMB = Board.scambioMB;
    scarta = Board.scarta;
    scambioMB->setDisabled(true);
    scarta->setDisabled(true);

    mosse = Board.mosse;

    QVBoxLayout *Vlayout = new QVBoxLayout(this);
    QHBoxLayout *h = new QHBoxLayout();

    Vlayout->addLayout(h);

    h->addWidget(b);

    QHBoxLayout *Hh=new QHBoxLayout();
    Vlayout->addLayout(Hh);
    Hh->addItem(new QSpacerItem(1,0,QSizePolicy::Maximum));
    Hh->addWidget(m);
    v = new QVBoxLayout();
    Hh->addLayout(v);
    v->addWidget(scambioMB);
    v->addWidget(scarta);
    Hh->addWidget(mosse);
    Hh->addItem(new QSpacerItem(1,0,QSizePolicy::Maximum));

    b->addelVec(celle);
    b->setStart(celle);
    b->setWin(celle);

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

BoardWindow& BoardWindow::operator =(const BoardWindow& Board){
    if(this != &Board){
        delete b;
        delete m;
        delete mosse;
        delete v;
        delete scambioMB;
        delete scarta;

        nome=Board.nome;
        celle=Board.celle;
        mano=Board.mano;
        board=Board.board;

        setScreenGeometry();

        setWindowTitle ("QtMiner - Giochiamo!!!");
        setFixedSize(720, 800);
        setWindowFlag(Qt::Dialog);
        setMaximumSize(800,950);

        b = Board.b;
        m = Board.m;

        scambioMB = Board.scambioMB;
        scarta = Board.scarta;
        scambioMB->setDisabled(true);
        scarta->setDisabled(true);

        mosse = Board.mosse;

        QVBoxLayout *Vlayout = new QVBoxLayout(this);
        QHBoxLayout *h = new QHBoxLayout();

        Vlayout->addLayout(h);

        h->addWidget(b);

        QHBoxLayout *Hh=new QHBoxLayout();
        Vlayout->addLayout(Hh);
        Hh->addItem(new QSpacerItem(1,0,QSizePolicy::Maximum));
        Hh->addWidget(m);
        v = new QVBoxLayout();
        Hh->addLayout(v);
        v->addWidget(scambioMB);
        v->addWidget(scarta);
        Hh->addWidget(mosse);
        Hh->addItem(new QSpacerItem(1,0,QSizePolicy::Maximum));

        b->addelVec(celle);
        b->setStart(celle);
        b->setWin(celle);

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
    return *this;
}

BoardWindow::BoardWindow(nat num, QString n) : celle(num), mano(false), board(false),
                    m(nullptr), b(nullptr), v(nullptr), scarta(nullptr), scambioMB(nullptr){

    setScreenGeometry();
    nome=n;

    setWindowTitle ("QtMiner - Giochiamo "+nome+"!!!");
    setFixedSize(720, 800);
    setWindowFlag(Qt::Dialog);
    setMaximumSize(800,950);

    b = new view::Board(celle);
    m = new view::Mano(7);

    scambioMB = new QPushButton("Posiziona");
    scambioMB->setMaximumSize(200,50);
    scarta = new QPushButton ("Scarta");
    scarta->setMaximumSize(200,50);
    scambioMB->setDisabled(true);
    scarta->setDisabled(true);

    mosse = new QLCDNumber();
    mosse->setMaximumSize(200,200);

    QVBoxLayout *Vlayout = new QVBoxLayout(this);

    Vlayout->addWidget(b);

    QHBoxLayout *Hh=new QHBoxLayout();
    Vlayout->addLayout(Hh);
    Hh->addItem(new QSpacerItem(150,0,QSizePolicy::Maximum));
    Hh->addWidget(m);
    v = new QVBoxLayout();
    Hh->addLayout(v);
    v->addWidget(scambioMB);
    v->addWidget(scarta);
    Hh->addWidget(mosse);
    Hh->addItem(new QSpacerItem(125,0,QSizePolicy::Maximum));

    b->addelVec(celle);
    b->setStart(celle);
    b->setWin(celle);

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
    m->addCardBoard(a,c);
    if(i==1){
        disableButton();
        //Turno avversario:
        avviaMossaAI();
    }
}

void BoardWindow::addElVectors(){

    b->addElGrid(celle);
    m->addElGrid(7);
    for(nat counter=0; counter<7; counter++){
        emit cheImmagineHo(counter);
    }
}

void BoardWindow::controlloCarteDaScambiare(){
    emit scambiaScarte();
}

void BoardWindow::avviaMossaAI(){
    mosse->display((mosse->value())+1);
    emit mossaAI();
}

void BoardWindow::aggiornamentoBoardAI(nat posAI, QString imgAI){
    b->addCardBoard(posAI,imgAI);
}

void BoardWindow::CardError(QString i){
    QErrorMessage* error= new QErrorMessage(this);
    error->showMessage(i);
    error->exec();
}

void BoardWindow::setScreenGeometry(){
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    screenGeometry.moveCenter(QPoint(((screenGeometry.width()- width()) / 2),((screenGeometry.height()- height()) / 2)));
}

void BoardWindow::GameOver(){
    disconnect(b, &view::Board::numCasellaCliccataBoard, this, &BoardWindow::cellaSelezionata);
    disconnect(m, &view::Mano::numCasellaCliccataBoard, this, &BoardWindow::cellaSelezionata);
    disconnect(b, &view::Board::numCasellaCliccataBoard, this, &BoardWindow::activateButton);
    disconnect(m, &view::Mano::numCasellaCliccataBoard, this, &BoardWindow::activateButton);
    disconnect(scambioMB, &QPushButton::clicked, this ,&BoardWindow::controlloCarteDaScambiare );
    disconnect(scambioMB, &QPushButton::clicked, m, &view::Mano::removeStylesheetButton);
    disconnect(scambioMB, &QPushButton::clicked, b, &view::Board::removeStylesheetButton);
    disconnect(scarta, &QPushButton::clicked, this, &BoardWindow::scartaCarta);
    disconnect(scarta, &QPushButton::clicked, b, &view::Board::removeStylesheetButton);
    disconnect(scarta, &QPushButton::clicked, m, &view::Mano::removeStylesheetButton);
}

