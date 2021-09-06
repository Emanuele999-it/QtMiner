#include "Header/winwindow.h"


WinWindow::~WinWindow(){
    if(newgame) delete newgame;
    if(checkboard) delete checkboard;
    if(menu) delete menu;
    if(text) delete text;
    if(image) delete image;
}

WinWindow::WinWindow(QString i){

    setWindowFlag(Qt::Dialog);

    //settaggio proprietà finestra, come mainwindow per consistency
    setWindowTitle ("hai vinto "+i);
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
    text -> setText("Ha vinto "+i);
    text->setAlignment(Qt::AlignHCenter);

    //Scrivo info
    Hinfo->addWidget(text);

    Hl2->addWidget(newgame);
    Hl2->addWidget(checkboard);
    Hl2->addWidget(menu);
    Hl2->setAlignment(Qt::AlignCenter);

    connect(newgame,&QPushButton::clicked, this, &WinWindow::NewBoardRequest);
    connect(checkboard,&QPushButton::clicked, this, &WinWindow::NewCheckRequest);
    connect(menu,&QPushButton::clicked, this, &WinWindow::NewMenuRequest);

}


/**
 * @brief NewBoardRequest: mandero' una segnale a mainwindow per una nuova board
 */

void WinWindow::NewBoardRequest(){
    hide();
    emit newgamesignal();
}

/**
 * @brief NewCheckRequest: mandero' un segnale a boardWindow per il controllo del terreno
 */
void WinWindow::NewCheckRequest(){
    close();
    emit NewCheckRequest();
}


