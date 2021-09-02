#include "View/Header/screens/gameScreen/Board/board.h"

#include <QGraphicsScene>


namespace view {

Board::~Board(){
}

Board::Board(const Board &b){

    posizioneBoard=b.posizioneBoard;
    QVector<Casella*> vettoreCaselleBoard(b.vettoreCaselleBoard);
    grid= new QGridLayout();
    QHBoxLayout* h= new QHBoxLayout(this);
    spaceR=new QSpacerItem(1,0,QSizePolicy::Minimum);
    spaceL=new QSpacerItem(1,0,QSizePolicy::Minimum);
    h->addItem(spaceL);
    h->addLayout(grid);
    h->addItem(spaceR);
}

Board& Board::operator =(const Board& b){
    if(this != &b){
        posizioneBoard=b.posizioneBoard;
        QVector<Casella*> vettoreCaselleBoard(b.vettoreCaselleBoard);
        grid= new QGridLayout();
        QHBoxLayout* h= new QHBoxLayout(this);
        spaceR=new QSpacerItem(1,0,QSizePolicy::Minimum);
        spaceL=new QSpacerItem(1,0,QSizePolicy::Minimum);
        h->addItem(spaceL);
        h->addLayout(grid);
        h->addItem(spaceR);
    }
    return *this;
}

Board::Board(const nat &i): posizioneBoard(0){
    QVector<Casella*> vettoreCaselleBoard(i);
    grid= new QGridLayout();
    QHBoxLayout* h= new QHBoxLayout(this);
    spaceR=new QSpacerItem(1,0,QSizePolicy::Minimum);
    spaceL=new QSpacerItem(1,0,QSizePolicy::Minimum);

    h->addItem(spaceL);
    h->addLayout(grid);
    h->addItem(spaceR);
}

void Board::addelVec(nat c){
    for(nat counter=0; counter<c; counter++){
        vettoreCaselleBoard.push_back(new view::Casella(counter));
        connect(vettoreCaselleBoard[counter],SIGNAL(casellaCliccata(nat)), this, SLOT(selectCardBoard(nat)));
    }
}

void Board::selectCardBoard(nat r){
    vettoreCaselleBoard[posizioneBoard]->setStyleSheet("");
    posizioneBoard=r;
    vettoreCaselleBoard[r]->setStyleSheet("QPushButton {background-color: green;}");
    emit numCasellaCliccataBoard(r);
}

void Board::removeStylesheetButton() {
    vettoreCaselleBoard[posizioneBoard]->setStyleSheet("");
}

void Board::addCardBoard(nat n, QString c){
    vettoreCaselleBoard[n]->cambiaImmagine(c);
}

Casella* Board::getCasella(nat i){
    return vettoreCaselleBoard[i];
}

nat Board::getPosizione() const {
    return posizioneBoard;
}

QString Board::getImage(nat p) const {
    return vettoreCaselleBoard[p]->getDefautImage();
}

void Board::addElGrid(nat celle){

    if(celle == 7){
        for(nat counter=0; counter<celle; counter++){
            grid->addWidget(vettoreCaselleBoard[counter],1,counter,1,1);
        }
    }


    else{
        for(nat counter=0; counter<celle; counter++){
            grid->addWidget(vettoreCaselleBoard[counter],counter/(celle/10),counter%(celle/10),1,1);
        }
    }

}

void Board::setStart(nat celle){
    vettoreCaselleBoard[celle-((celle/10)/2+1)]->setStyleSheet("QPushButton {background-color: yellow;}");
}

Mano::Mano(const nat &i) : Board(i){}

}
