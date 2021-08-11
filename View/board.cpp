#include "View/Header/screens/gameScreen/Board/board.h"

#include <QGraphicsScene>


namespace view {

/*********************** Board ******************************************************************/



Board::Board(const nat &i): posizioneBoard(0){
    QVector<Casella*> vettoreCaselleBoard(i);

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

/*********************** Mano ******************************************************************/

Mano::Mano(const nat &i) : posizioneMano(0){
    QVector<Casella*> vettoreCaselleMano(i);

}

void Mano::selectCardMano(nat r){
    vettoreCaselleMano[posizioneMano]->setStyleSheet("");
    posizioneMano=r;
    vettoreCaselleMano[r]->setStyleSheet("QPushButton {background-color: green;}");
    emit numCasellaCliccataMano(r);
}

void Mano::removeStylesheetButton() const{
    vettoreCaselleMano[posizioneMano]->setStyleSheet("");
}

void Mano::addCardMano(nat n, QString c){
    vettoreCaselleMano[n]->cambiaImmagine(c);
}

Casella* Mano::getCasella(nat i){
    return vettoreCaselleMano[i];
}

nat Mano::getPosizione() const {
    return posizioneMano;
}

}
