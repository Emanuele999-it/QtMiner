#include "Header/winwindow.h"

WinWindow::~WinWindow(){
    if(newgame) delete newgame;
    if(checkboard) delete checkboard;
    if(menu) delete menu;
    if(text) delete text;
}

WinWindow::WinWindow(QString i): newgame(nullptr), checkboard(nullptr), menu(nullptr), text(nullptr), Vl(nullptr){
    nome = i;
    setWindowFlag(Qt::Dialog);
    setWindowTitle("QtMiner - Vincitore");
    setMinimumSize(350,300);
    setMaximumSize(600,500);

    newgame = new QPushButton(tr("Nuovo gioco"), this);
    checkboard = new QPushButton(tr("Riguarda board"), this);
    menu = new QPushButton(tr("Torna al menu"), this);
    QImage* Img = new QImage(":/Img/gold.jpg");
    QLabel* l  = new QLabel("");
    l->setPixmap(QPixmap::fromImage(*Img).scaled(100,150));

    Vl= new QVBoxLayout(this);

    QGridLayout *Hl1=new QGridLayout();
    QHBoxLayout *Hl2=new QHBoxLayout();
    QHBoxLayout *Hinfo=new QHBoxLayout();

    Vl->addLayout(Hl1);
    Vl->addLayout(Hinfo);
    Vl->addLayout(Hl2);

    Hl1->setAlignment(Qt::AlignTop | Qt::AlignCenter);
    Hl1->addWidget(l);

    QLabel* text = new QLabel();
    if(!nome.contains("Winner")){
        text -> setText("Il vincitore è la "+(i));
    }
    else{
        nome.remove("Winner");
        if(nome == ""){
            text -> setText("Il vincitore è l'utente ");
        }
        else
        {
            text -> setText("Il vincitore è: "+(nome));
        }
    }
    text->setAlignment(Qt::AlignHCenter);

    Hinfo->addWidget(text);

    Hl2->addWidget(newgame);
    Hl2->addWidget(checkboard);
    Hl2->addWidget(menu);
    Hl2->setAlignment(Qt::AlignCenter);

    connect(newgame,&QPushButton::clicked, this, &WinWindow::NewBoardRequest);
    connect(checkboard,&QPushButton::clicked, this, &WinWindow::NewCheckRequest);
    connect(menu,&QPushButton::clicked, this, &WinWindow::chiusuraWinWindow);
}

WinWindow::WinWindow(const WinWindow& t){
    nome = t.nome;
    setWindowFlag(Qt::Dialog);
    setWindowTitle("QtMiner - Vincitore");
    setMinimumSize(350,300);
    setMaximumSize(600,500);

    newgame = new QPushButton(tr("Nuovo gioco"), this);
    checkboard = new QPushButton(tr("Riguarda board"), this);
    menu = new QPushButton(tr("Torna al menu"), this);
    QImage* Img = new QImage(":/Img/gold.jpg");
    QLabel* l  = new QLabel("");
    l->setPixmap(QPixmap::fromImage(*Img).scaled(100,150));

    Vl= new QVBoxLayout(this);

    QGridLayout *Hl1=new QGridLayout();
    QHBoxLayout *Hl2=new QHBoxLayout();
    QHBoxLayout *Hinfo=new QHBoxLayout();

    Vl->addLayout(Hl1);
    Vl->addLayout(Hinfo);
    Vl->addLayout(Hl2);

    Hl1->setAlignment(Qt::AlignTop | Qt::AlignCenter);// lo voglio grande, vedere misure
    Hl1->addWidget(l);

    QLabel* text = t.text;
    if(!nome.contains("Winner")){
        text -> setText("Il vincitore è la "+(nome));
    }
    else{
        nome.remove("Winner");
        if(nome == ""){
            text -> setText("Il vincitore è l'utente ");
        }
        else
        {
            text -> setText("Il vincitore è: "+(nome));
        }
    }
    text->setAlignment(Qt::AlignHCenter);

    Hinfo->addWidget(text);

    Hl2->addWidget(newgame);
    Hl2->addWidget(checkboard);
    Hl2->addWidget(menu);
    Hl2->setAlignment(Qt::AlignCenter);

    connect(newgame,&QPushButton::clicked, this, &WinWindow::NewBoardRequest);
    connect(checkboard,&QPushButton::clicked, this, &WinWindow::NewCheckRequest);
    connect(menu,&QPushButton::clicked, this, &WinWindow::chiusuraWinWindow);
}

WinWindow& WinWindow::operator=(const WinWindow& t){
    if(this != &t){
        nome = t.nome;
        setWindowFlag(Qt::Dialog);
        setWindowTitle("QtMiner - Vincitore");
        setMinimumSize(350,300);
        setMaximumSize(600,500);

        newgame = new QPushButton(tr("Nuovo gioco"), this);
        checkboard = new QPushButton(tr("Riguarda board"), this);
        menu = new QPushButton(tr("Torna al menu"), this);
        QImage* Img = new QImage(":/Img/gold.jpg");
        QLabel* l  = new QLabel("");
        l->setPixmap(QPixmap::fromImage(*Img).scaled(100,150));

        Vl= new QVBoxLayout(this);

        QGridLayout *Hl1=new QGridLayout();
        QHBoxLayout *Hl2=new QHBoxLayout();
        QHBoxLayout *Hinfo=new QHBoxLayout();

        Vl->addLayout(Hl1);
        Vl->addLayout(Hinfo);
        Vl->addLayout(Hl2);

        Hl1->setAlignment(Qt::AlignTop | Qt::AlignCenter);
        Hl1->addWidget(l);

        QLabel* text = t.text;
        if(!nome.contains("Winner")){
            text -> setText("Il vincitore è la "+(nome));
        }
        else{
            nome.remove("Winner");
            if(nome == ""){
                text -> setText("Il vincitore è l'utente ");
            }
            else
            {
                text -> setText("Il vincitore è: "+(nome));
            }
        }
        text->setAlignment(Qt::AlignHCenter);

        Hinfo->addWidget(text);

        Hl2->addWidget(newgame);
        Hl2->addWidget(checkboard);
        Hl2->addWidget(menu);
        Hl2->setAlignment(Qt::AlignCenter);

        connect(newgame,&QPushButton::clicked, this, &WinWindow::NewBoardRequest);
        connect(checkboard,&QPushButton::clicked, this, &WinWindow::NewCheckRequest);
        connect(menu,&QPushButton::clicked, this, &WinWindow::chiusuraWinWindow);
    }

    return *this;
}

void WinWindow::NewBoardRequest(){
    hide();
    emit newgamesignal();
    close();
}

void WinWindow::NewCheckRequest(){
    close();
}


