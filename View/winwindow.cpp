#include "Header/winwindow.h"

WinWindow::~WinWindow(){
    if(newgame) delete newgame;
    if(checkboard) delete checkboard;
    if(menu) delete menu;
    if(text) delete text;
    if(image) delete image;
}

WinWindow::WinWindow(QString i){
    nome = i;
    setWindowFlag(Qt::Dialog);
    //settaggio proprietà finestra, come mainwindow per consistency
    setWindowTitle("QtMiner - Vincitore");
    setMinimumSize(350,300);
    setMaximumSize(600,500);

    newgame = new QPushButton(tr("Nuovo gioco"), this);
    checkboard = new QPushButton(tr("Riguarda board"), this);
    menu = new QPushButton(tr("Torna al menu"), this);
    QImage* Img = new QImage(":/Img/gold.jpg");
    QLabel* l  = new QLabel("");
    l->setPixmap(QPixmap::fromImage(*Img).scaled(100,150));

    // set layout visualizzazione
    Vl= new QVBoxLayout(this);

    //proviamo un layout simile al mainwindow, ma con l'immmagine gold al posto delle impostazioni
    QGridLayout *Hl1=new QGridLayout();
    QHBoxLayout *Hl2=new QHBoxLayout();
    QHBoxLayout *Hinfo=new QHBoxLayout();

    // aggiungiamo le box alla visualizzazione
    Vl->addLayout(Hl1);
    Vl->addLayout(Hinfo);
    Vl->addLayout(Hl2);

    //aggiungiamo i widget ai box
    //Hl1->addWidget(image);
    Hl1->setAlignment(Qt::AlignTop | Qt::AlignCenter);// lo voglio grande, vedere misure
    Hl1->addWidget(l);

    //forma layout, immmutata da mainwindow
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
    //text -> setText("Ha vinto "+ (temp==""?(i=="Winner"?"Utente":i):temp));
    text->setAlignment(Qt::AlignHCenter);

    //Scrivo info
    Hinfo->addWidget(text);

    Hl2->addWidget(newgame);
    Hl2->addWidget(checkboard);
    Hl2->addWidget(menu);
    Hl2->setAlignment(Qt::AlignCenter);

    connect(newgame,&QPushButton::clicked, this, &WinWindow::NewBoardRequest);
    connect(checkboard,&QPushButton::clicked, this, &WinWindow::NewCheckRequest);//Chiudere Win
    connect(menu,&QPushButton::clicked, this, &WinWindow::chiusuraWinWindow);//Chiudere Win & Board
    //La "x" e "torna al menu" devono fare la stessa cosa
}
/**
* costruttore di copia
*/
WinWindow::WinWindow(const WinWindow& t){
    nome = t.nome;
    setWindowFlag(Qt::Dialog);
    //settaggio proprietà finestra, come mainwindow per consistency
    setWindowTitle("QtMiner - Vincitore");
    setMinimumSize(350,300);
    setMaximumSize(600,500);

    newgame = new QPushButton(tr("Nuovo gioco"), this);
    checkboard = new QPushButton(tr("Riguarda board"), this);
    menu = new QPushButton(tr("Torna al menu"), this);
    QImage* Img = new QImage(":/Img/gold.jpg");
    QLabel* l  = new QLabel("");
    l->setPixmap(QPixmap::fromImage(*Img).scaled(100,150));

    // set layout visualizzazione
    Vl= new QVBoxLayout(this);

    //proviamo un layout simile al mainwindow, ma con l'immmagine gold al posto delle impostazioni
    QGridLayout *Hl1=new QGridLayout();
    QHBoxLayout *Hl2=new QHBoxLayout();
    QHBoxLayout *Hinfo=new QHBoxLayout();

    // aggiungiamo le box alla visualizzazione
    Vl->addLayout(Hl1);
    Vl->addLayout(Hinfo);
    Vl->addLayout(Hl2);

    //aggiungiamo i widget ai box
    //Hl1->addWidget(image);
    Hl1->setAlignment(Qt::AlignTop | Qt::AlignCenter);// lo voglio grande, vedere misure
    Hl1->addWidget(l);

    //forma layout, immmutata da mainwindow
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
    //text -> setText("Ha vinto "+ (temp==""?(i=="Winner"?"Utente":i):temp));
    text->setAlignment(Qt::AlignHCenter);

    //Scrivo info
    Hinfo->addWidget(text);

    Hl2->addWidget(newgame);
    Hl2->addWidget(checkboard);
    Hl2->addWidget(menu);
    Hl2->setAlignment(Qt::AlignCenter);

    connect(newgame,&QPushButton::clicked, this, &WinWindow::NewBoardRequest);
    connect(checkboard,&QPushButton::clicked, this, &WinWindow::NewCheckRequest);//Chiudere Win
    connect(menu,&QPushButton::clicked, this, &WinWindow::chiusuraWinWindow);//Chiudere Win & Board
    //La "x" e "torna al menu" devono fare la stessa cosa
}

/**
* operatore di assegnazione
*/
WinWindow& WinWindow::operator=(const WinWindow& t){
    if(this != &t){
        nome = t.nome;
        setWindowFlag(Qt::Dialog);
        //settaggio proprietà finestra, come mainwindow per consistency
        setWindowTitle("QtMiner - Vincitore");
        setMinimumSize(350,300);
        setMaximumSize(600,500);

        newgame = new QPushButton(tr("Nuovo gioco"), this);
        checkboard = new QPushButton(tr("Riguarda board"), this);
        menu = new QPushButton(tr("Torna al menu"), this);
        QImage* Img = new QImage(":/Img/gold.jpg");
        QLabel* l  = new QLabel("");
        l->setPixmap(QPixmap::fromImage(*Img).scaled(100,150));

        // set layout visualizzazione
        Vl= new QVBoxLayout(this);

        //proviamo un layout simile al mainwindow, ma con l'immmagine gold al posto delle impostazioni
        QGridLayout *Hl1=new QGridLayout();
        QHBoxLayout *Hl2=new QHBoxLayout();
        QHBoxLayout *Hinfo=new QHBoxLayout();

        // aggiungiamo le box alla visualizzazione
        Vl->addLayout(Hl1);
        Vl->addLayout(Hinfo);
        Vl->addLayout(Hl2);

        //aggiungiamo i widget ai box
        //Hl1->addWidget(image);
        Hl1->setAlignment(Qt::AlignTop | Qt::AlignCenter);// lo voglio grande, vedere misure
        Hl1->addWidget(l);

        //forma layout, immmutata da mainwindow
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
        //text -> setText("Ha vinto "+ (temp==""?(i=="Winner"?"Utente":i):temp));
        text->setAlignment(Qt::AlignHCenter);

        //Scrivo info
        Hinfo->addWidget(text);

        Hl2->addWidget(newgame);
        Hl2->addWidget(checkboard);
        Hl2->addWidget(menu);
        Hl2->setAlignment(Qt::AlignCenter);

        connect(newgame,&QPushButton::clicked, this, &WinWindow::NewBoardRequest);
        connect(checkboard,&QPushButton::clicked, this, &WinWindow::NewCheckRequest);//Chiudere Win
        connect(menu,&QPushButton::clicked, this, &WinWindow::chiusuraWinWindow);//Chiudere Win & Board
        //La "x" e "torna al menu" devono fare la stessa cosa
    }

    return *this;
}


/**
 * @brief NewBoardRequest: mandero' una segnale a mainwindow per una nuova board
 */

void WinWindow::NewBoardRequest(){
    hide();
    emit newgamesignal();
    close();
}

/**
 * @brief NewCheckRequest: mandero' un segnale a boardWindow per il controllo del terreno
 */
void WinWindow::NewCheckRequest(){
    close();
}


