#include "Header/controller.h"


Controller::~Controller(){
    if(MainW) delete MainW;
    if(modelBoard) delete modelBoard;
}

Controller& Controller::operator=(const Controller &c){
    if(this != &c){
        delete MainW;
        delete modelBoard;

        boardDimension=c.boardDimension;
        MainW=c.MainW;

        connect(MainW, &MainWindow::SettingsRequest, this, &Controller::openSettings);
        connect(MainW, &MainWindow::TutorialRequest, this, &Controller::openTutorial);
        connect(MainW, &MainWindow::GameRequest, this, &Controller::openBoardWindow);
        connect(MainW, &MainWindow::LastGameRequest, this, &Controller::openLastGameWindow);
        connect(MainW, &MainWindow::casellaBoardSelezionata, this, &Controller::cambiaCellaBoard);
        connect(MainW, &MainWindow::chiusuraBoardWRimbalzo, this, &Controller::chiusuraGame);
        connect(MainW, &MainWindow::changeBoardDimension, this, &Controller::cambioDimensioniBoard);
        connect(MainW, &MainWindow::ScartaCartaRimbalzo, this, &Controller::scartaCartaDallaMano);
        MainW->show();
    }
    return *this;
}

Controller::Controller(const Controller& c){
    boardDimension=c.boardDimension;
    MainW = c.MainW;

    connect(MainW, &MainWindow::SettingsRequest, this, &Controller::openSettings);
    connect(MainW, &MainWindow::TutorialRequest, this, &Controller::openTutorial);
    connect(MainW, &MainWindow::GameRequest, this, &Controller::openBoardWindow);
    connect(MainW, &MainWindow::LastGameRequest, this, &Controller::openLastGameWindow);

    //da controllare potrebbero essere sbagliati
    connect(MainW, &MainWindow::casellaBoardSelezionata, this, &Controller::cambiaCellaBoard);

    connect(MainW, &MainWindow::chiusuraBoardWRimbalzo, this, &Controller::chiusuraGame);
    connect(MainW, &MainWindow::changeBoardDimension, this, &Controller::cambioDimensioniBoard);
    connect(MainW, &MainWindow::ScartaCartaRimbalzo, this, &Controller::scartaCartaDallaMano);

    MainW->show();
}


Controller::Controller(QObject* parent): QObject(parent) {

    boardDimension=50;
    MainW = new MainWindow();

    connect(MainW, &MainWindow::SettingsRequest, this, &Controller::openSettings);
    connect(MainW, &MainWindow::TutorialRequest, this, &Controller::openTutorial);
    connect(MainW, &MainWindow::GameRequest, this, &Controller::openBoardWindow);
    connect(MainW, &MainWindow::LastGameRequest, this, &Controller::openLastGameWindow);

    //da controllare potrebbero essere sbagliati
    connect(MainW, &MainWindow::casellaBoardSelezionata, this, &Controller::cambiaCellaBoard);

    connect(MainW, &MainWindow::chiusuraBoardWRimbalzo, this, &Controller::chiusuraGame);
    connect(MainW, &MainWindow::changeBoardDimension, this, &Controller::cambioDimensioniBoard);
    connect(MainW, &MainWindow::ScartaCartaRimbalzo, this, &Controller::scartaCartaDallaMano);

    MainW->show();
    //MainW->createObjVectors();
}

void Controller::buildAndConnectModelView(){
    modelBoard = new model::ModelBoard(7,boardDimension);
    //connessione tra model e view (aggiornamento carta)
    connect(modelBoard, &model::ModelBoard::CambiaPosizioneManoBoard, MainW, &MainWindow::UpdateViewfromModel);
    connect(MainW, &MainWindow::rimbalzoScambioCarteMB, modelBoard, &model::ModelBoard::posiziona);
    connect(MainW, &MainWindow::RimbalzoCheImmagineHo, modelBoard, &model::ModelBoard::getHandImage);
    connect(modelBoard, &model::ModelBoard::CambiaImmagineMano, MainW, &MainWindow::UpdateCardMano);

    connect(modelBoard, &model::ModelBoard::changeCardsfailed, MainW, &MainWindow::changeCardsFailed);
    connect(MainW, &MainWindow::rimbalzoMossaAI, modelBoard, &model::ModelBoard::posizionaAI);
    connect(modelBoard, &model::ModelBoard::cambiaCellaBoardAI, MainW, &MainWindow::updateBoardAI);

    connect(modelBoard, &model::ModelBoard::userWin, MainW, &MainWindow::apriVittoria);
}

void Controller::openSettings() {
    emit MainW->OpenSettingsWindow(boardDimension);
}

void Controller::openTutorial(){
    emit MainW->OpenTutorialWindow();
}

void Controller::openBoardWindow(QString n){
    name = n;
    buildAndConnectModelView();
    modelBoard->addCardtoVectors();
    modelBoard->saveName(n);
    emit MainW->OpenGameWindow(boardDimension,n);
}

void Controller::openLastGameWindow(){
    emit MainW->OpenLastGameWindow();
}

void Controller::chiusuraGame(){
    emit modelBoard->saveLastGame();
    disconnect(modelBoard, &model::ModelBoard::CambiaPosizioneManoBoard, MainW, &MainWindow::UpdateViewfromModel);
    disconnect(MainW, &MainWindow::rimbalzoScambioCarteMB, modelBoard, &model::ModelBoard::posiziona);
    disconnect(MainW, &MainWindow::RimbalzoCheImmagineHo, modelBoard, &model::ModelBoard::getHandImage);
    disconnect(modelBoard, &model::ModelBoard::CambiaImmagineMano, MainW, &MainWindow::UpdateCardMano);

    disconnect(modelBoard, &model::ModelBoard::changeCardsfailed, MainW, &MainWindow::changeCardsFailed);
    disconnect(MainW, &MainWindow::rimbalzoMossaAI, modelBoard, &model::ModelBoard::posizionaAI);
    disconnect(modelBoard, &model::ModelBoard::cambiaCellaBoardAI, MainW, &MainWindow::updateBoardAI);
    delete modelBoard;
    modelBoard=nullptr;
}

void Controller::cambiaCellaBoard(nat x, nat y){
    emit modelBoard->evidenziaCellaBoard(x,y);
}

void Controller::cambioDimensioniBoard(nat i){
    boardDimension=i;
}

void Controller::scartaCartaDallaMano(){
    modelBoard->scartaCartaMano();
}


