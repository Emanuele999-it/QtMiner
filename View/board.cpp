#include "View\Header\screens\gameScreen\Board\board.h"

#include <QGraphicsScene>


namespace view {

/*********************** Board ******************************************************************/

Board::Board(const nat &i): posizioneBoard(0){

    QVector<Casella*> vettoreCaselleBoard;
    for(nat counter=0; counter<i; counter++){
        vettoreCaselleBoard.push_back(new Casella(counter));
        connect(vettoreCaselleBoard[counter],SIGNAL(casellaCliccata(nat)), this, SLOT(selectCardBoard(nat)));
    }
    /*
     * creazione vettore delle caselle + connessione di ciascuna casella con lo slot selectCardBoard
     *
    */

}

void Board::selectCardBoard(nat r){
    posizioneBoard=r;
    emit numCasellaCliccataBoard(r);
}

void Board::addCardBoard(nat n, QString c){
    vettoreCaselleBoard[n]->cambiaImmagine(c);
}

/*********************** Mano ******************************************************************/

Mano::Mano(const nat &i) : posizioneMano(0){
    QVector<Casella*> vettoreCaselleMano;
    for(nat counter=0; counter<i; counter++){
        vettoreCaselleMano.push_back(new Casella(counter));
        connect(vettoreCaselleMano[counter],SIGNAL(casellaCliccata(nat)), this, SLOT(selectCardMano(nat)));
    }
}

void Mano::selectCardMano(nat r){
    posizioneMano=r;
    emit numCasellaCliccataMano(r);
}

void Mano::addCardMano(nat n, QString c){
    vettoreCaselleMano[n]->cambiaImmagine(c);
}


}
