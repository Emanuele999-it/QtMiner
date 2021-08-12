#include "View/Header/screens/gameScreen/Board/board.h"

#include <QGraphicsScene>


namespace view {

/*********************** Board ******************************************************************/



Board::Board(const nat &i): posizioneBoard(0){
    QVector<Casella*> vettoreCaselleBoard(i);

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



Mano::Mano(const nat &i) : Board(i){}

}
