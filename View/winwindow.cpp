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
    image = new QImage(QString("Img/gold.jpg"), 0);// controllare uso di QImage

    // set layout visualizzazione
    Vl= new QVBoxLayout(this);

    //proviamo un layout simile al mainwindow, ma con l'immmagine gold al posto delle impostazioni
    QHBoxLayout *Hl1=new QHBoxLayout();
    QHBoxLayout *Hl2=new QHBoxLayout();
    QHBoxLayout *Hinfo=new QHBoxLayout();

    // aggiungiamo le box alla visualizzazione
    Vl->addLayout(Hl1);
    Vl->addLayout(Hinfo);
    Vl->addLayout(Hl2);

    //aggiungiamo i widget ai box
    //Hl1->addWidget(image);
    Hl1->setAlignment(Qt::AlignTop);// lo voglio grande, vedere misure

    //forma layout, immmutata da mainwindow
    QLabel* text = new QLabel();
    text -> setText("Vittoria");
    text->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    text->setAlignment(Qt::AlignLeft);

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
    //emit MainWindow::OpenGameWindow;
}

/**
 * @brief NewCheckRequest: mandero' un segnale a boardWindow per il controllo del terreno
 */
void WinWindow::NewCheckRequest(){
    //emit MainWindow::OpenGameWindow;
}

/**
 * @brief NewMenuRequest: si chiude la finestra e si riapre mainWindow
 */
void WinWindow::NewMenuRequest(){
    hide();
    //emit MainWindow::show();
}
