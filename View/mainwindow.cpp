#include "Header/mainwindow.h"
#include <QHBoxLayout>
#include <QErrorMessage>
#include <QRect>
#include <QDesktopWidget>
#include <QFormLayout>

#include <QDebug>

MainWindow::~MainWindow(){
    if(lineE) delete lineE;
    if(settings) delete settings;
    if(settWindow) delete settWindow;
    if(tutorial) delete tutorial;
    if(tWindow) delete tWindow;
    if(startGame) delete startGame;
    if(boardWindoW) delete boardWindoW;
    if(lastGame) delete lastGame;
    if(LGWindow) delete LGWindow;
    if(Vl) delete Vl;
}

MainWindow::MainWindow(const MainWindow &m){

    setWindowFlag(Qt::Dialog);

    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()- width()) / 2;
    int y = (screenGeometry.height()- height()) / 2;
    move(x, y);

    //settaggio proprietà finestra
    setWindowTitle ("QtMiner");
    setMinimumSize(350,300);
    setMaximumSize(600,500);

    //creazione bottoni impostazioni / inizio gioco
    startGame = new QPushButton(tr("Inizia a giocare!"), this);
    tutorial = new QPushButton(tr("Tutorial"), this);
    lastGame = new QPushButton(tr("Ultima partita"), this);

    settings = new SettingsButton();

    // set layout visualizzazione
    Vl= new QVBoxLayout(this);

    QHBoxLayout *Hl1=new QHBoxLayout();
    QHBoxLayout *Hl2=new QHBoxLayout();
    QHBoxLayout *Hname=new QHBoxLayout();
    Vl->addLayout(Hl1);
    Vl->addLayout(Hname);
    Vl->addLayout(Hl2);

    Hl1->addWidget(settings);
    Hl1->setAlignment(Qt::AlignRight | Qt::AlignTop);

    QFormLayout* formLayout= new QFormLayout();
    formLayout->setRowWrapPolicy(QFormLayout::DontWrapRows);
    formLayout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
    formLayout->setFormAlignment(Qt::AlignHCenter | Qt::AlignTop);
    formLayout->setLabelAlignment(Qt::AlignLeft);

    lineE = m.lineE;

    Hname->addLayout(formLayout);
    formLayout->addRow("Inserisci il tuo nome", lineE);

    Hl2->addWidget(tutorial);
    Hl2->addWidget(startGame);
    Hl2->addWidget(lastGame);
    Hl2->setAlignment(Qt::AlignCenter);

    connect(settings,&QPushButton::clicked, this, &MainWindow::SettingsRequest);
    connect(tutorial,&QPushButton::clicked, this, &MainWindow::TutorialRequest);
    connect(startGame,&QPushButton::clicked, this, &MainWindow::GameRequestSlot);
    connect(lastGame,&QPushButton::clicked, this, &MainWindow::LastGameRequest);
}

MainWindow& MainWindow::operator =(const MainWindow& m){
    if(this != &m){
        delete lineE;
        delete settings;
        delete tutorial;
        delete startGame;
        delete lastGame;
        delete Vl;

        setWindowFlag(Qt::Dialog);

        QRect screenGeometry = QApplication::desktop()->screenGeometry();
        int x = (screenGeometry.width()- width()) / 2;
        int y = (screenGeometry.height()- height()) / 2;
        move(x, y);

        //settaggio proprietà finestra
        setWindowTitle ("QtMiner");
        setMinimumSize(350,300);
        setMaximumSize(600,500);

        //creazione bottoni impostazioni / inizio gioco
        startGame = new QPushButton(tr("Inizia a giocare!"), this);
        tutorial = new QPushButton(tr("Tutorial"), this);
        lastGame = new QPushButton(tr("Ultima partita"), this);

        settings = new SettingsButton();

        // set layout visualizzazione
        Vl= new QVBoxLayout(this);

        QHBoxLayout *Hl1=new QHBoxLayout();
        QHBoxLayout *Hl2=new QHBoxLayout();
        QHBoxLayout *Hname=new QHBoxLayout();
        Vl->addLayout(Hl1);
        Vl->addLayout(Hname);
        Vl->addLayout(Hl2);

        Hl1->addWidget(settings);
        Hl1->setAlignment(Qt::AlignRight | Qt::AlignTop);

        QFormLayout* formLayout= new QFormLayout();
        formLayout->setRowWrapPolicy(QFormLayout::DontWrapRows);
        formLayout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
        formLayout->setFormAlignment(Qt::AlignHCenter | Qt::AlignTop);
        formLayout->setLabelAlignment(Qt::AlignLeft);

        lineE = m.lineE;

        Hname->addLayout(formLayout);
        formLayout->addRow("Inserisci il tuo nome", lineE);

        Hl2->addWidget(tutorial);
        Hl2->addWidget(startGame);
        Hl2->addWidget(lastGame);
        Hl2->setAlignment(Qt::AlignCenter);

        connect(settings,&QPushButton::clicked, this, &MainWindow::SettingsRequest);
        connect(tutorial,&QPushButton::clicked, this, &MainWindow::TutorialRequest);
        connect(startGame,&QPushButton::clicked, this, &MainWindow::GameRequestSlot);
        connect(lastGame,&QPushButton::clicked, this, &MainWindow::LastGameRequest);
    }
    return *this;
}

MainWindow::MainWindow(){

    setWindowFlag(Qt::Dialog);

    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()- width()) / 2;
    int y = (screenGeometry.height()- height()) / 2;
    move(x, y);

    //settaggio proprietà finestra
    setWindowTitle ("QtMiner");
    setMinimumSize(350,300);
    setMaximumSize(450,370);

    //creazione bottoni impostazioni / inizio gioco
    startGame = new QPushButton(tr("Inizia a giocare!"), this);
    tutorial = new QPushButton(tr("Tutorial"), this);
    lastGame = new QPushButton(tr("Ultima partita"), this);

    settings = new SettingsButton();

    // set layout visualizzazione
    Vl= new QVBoxLayout(this);

    QHBoxLayout *Hl1=new QHBoxLayout();
    QHBoxLayout *Hl2=new QHBoxLayout();
    QHBoxLayout *Hname=new QHBoxLayout();
    Vl->addLayout(Hl1);
    Vl->addLayout(Hname);
    Vl->addLayout(Hl2);

    Hl1->addWidget(settings);
    Hl1->setAlignment(Qt::AlignRight | Qt::AlignTop);

    QFormLayout* formLayout= new QFormLayout();
    formLayout->setRowWrapPolicy(QFormLayout::DontWrapRows);
    formLayout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
    formLayout->setFormAlignment(Qt::AlignHCenter | Qt::AlignTop);
    formLayout->setLabelAlignment(Qt::AlignLeft);

    lineE = new QLineEdit("");

    Hname->addLayout(formLayout);
    formLayout->addRow("Inserisci il tuo nome", lineE);

    Hl2->addWidget(tutorial);
    Hl2->addWidget(startGame);
    Hl2->addWidget(lastGame);
    Hl2->setAlignment(Qt::AlignCenter);

    connect(settings,&QPushButton::clicked, this, &MainWindow::SettingsRequest);
    connect(tutorial,&QPushButton::clicked, this, &MainWindow::TutorialRequest);
    connect(startGame,&QPushButton::clicked, this, &MainWindow::GameRequestSlot);
    connect(lastGame,&QPushButton::clicked, this, &MainWindow::LastGameRequest);
}

void MainWindow::GameRequestSlot(){
    emit GameRequest(lineE->displayText());
}

void MainWindow::OpenSettingsWindow(nat i){
    hide();
    settWindow = new SettingsWindow(i);
    connect(settWindow, &SettingsWindow::newBoardDimension, this, &MainWindow::changeBoardDimension);
    connect(settWindow, &SettingsWindow::closeSett, this , &MainWindow::closeSettings);
    settWindow->exec();
}

void MainWindow::OpenTutorialWindow(){

    tWindow = new Tutorialwindow();
    tWindow->exec();
}

void MainWindow::OpenGameWindow(nat dim, QString n){
    startGame->setDisabled(true);
    boardWindoW = new BoardWindow(dim, n);

    connect(boardWindoW, &BoardWindow::rimbalzoSegnaleCasellaSelezionataBoard, this, &MainWindow::casellaBoardSelezionata);

    connect(this, &MainWindow::UpdateViewfromModel, boardWindoW, &BoardWindow::aggiornamentoView);
    connect(this, &MainWindow::UpdateCardMano, boardWindoW, &BoardWindow::aggiornamentoCartaMano);

    connect(boardWindoW, &BoardWindow::cheImmagineHo, this, &MainWindow::RimbalzoCheImmagineHo);
    connect(boardWindoW, &BoardWindow::chiusuraBoardW, this, &MainWindow::closeGameBoard);
    connect(boardWindoW, &BoardWindow::scambiaScarte, this, &MainWindow::rimbalzoScambioCarteMB);
    connect(boardWindoW, &BoardWindow::scartaCarta, this, &MainWindow::ScartaCartaRimbalzo);
    //Roba AI
    connect(boardWindoW, &BoardWindow::mossaAI, this, &MainWindow::rimbalzoMossaAI);
    connect(this, &MainWindow::updateBoardAI, boardWindoW, &BoardWindow::aggiornamentoBoardAI);

    boardWindoW->addElVectors();
    hide();

    boardWindoW->show();

}

void MainWindow::OpenLastGameWindow(){
    LGWindow = new LastGameWindow();
    connect(LGWindow, &LastGameWindow::chiusuraLastGame, this, &MainWindow::closeLastGame);
    hide();
}

void MainWindow::closeLastGame(){
    show();
    disconnect(LGWindow, &LastGameWindow::chiusuraLastGame, this, &MainWindow::closeLastGame);
    delete LGWindow;
    LGWindow=nullptr;
}

void MainWindow::closeSettings(){
    show();
    disconnect(settWindow, &SettingsWindow::newBoardDimension, this, &MainWindow::changeBoardDimension);
    disconnect(settWindow, &SettingsWindow::closeSett, this , &MainWindow::closeSettings);
    delete settWindow;
    settWindow=nullptr;
}

void MainWindow::closeGameBoard(){
    startGame->setDisabled(false);
    show();
    disconnect(boardWindoW, &BoardWindow::rimbalzoSegnaleCasellaSelezionataBoard, this, &MainWindow::casellaBoardSelezionata);
    disconnect(this, &MainWindow::UpdateViewfromModel, boardWindoW, &BoardWindow::aggiornamentoView);
    disconnect(this, &MainWindow::UpdateCardMano, boardWindoW, &BoardWindow::aggiornamentoCartaMano);
    disconnect(boardWindoW, &BoardWindow::cheImmagineHo, this, &MainWindow::RimbalzoCheImmagineHo);
    disconnect(boardWindoW, &BoardWindow::chiusuraBoardW, this, &MainWindow::closeGameBoard);
    disconnect(boardWindoW, &BoardWindow::scambiaScarte, this, &MainWindow::rimbalzoScambioCarteMB);
    disconnect(boardWindoW, &BoardWindow::scartaCarta, this, &MainWindow::ScartaCartaRimbalzo);
    disconnect(boardWindoW, &BoardWindow::mossaAI, this, &MainWindow::rimbalzoMossaAI);
    disconnect(this, &MainWindow::updateBoardAI, boardWindoW, &BoardWindow::aggiornamentoBoardAI);

    delete boardWindoW;
    boardWindoW=nullptr;
    emit chiusuraBoardWRimbalzo();
}

void MainWindow::changeCardsFailed(QString i){
    boardWindoW->disableButton();
    emit boardWindoW->CardError(i);
}
