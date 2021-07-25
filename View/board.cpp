#include "View\Header\screens\gameScreen\Board\board.h"

#include <QGraphicsScene>


namespace view {

Board::Board(const nat &i): posizione(0){

    QVector<Casella*> vettoreCaselle;
    for(nat counter=0; counter<i; counter++){
        vettoreCaselle.push_back(new Casella(counter));
        connect(vettoreCaselle[counter],SIGNAL(casellaCliccata(nat)), this, SLOT(selectCardBoard(nat)));
    }
    /*
     * creazione vettore delle caselle + connessione di ciascuna casella con lo slot selectCardBoard
     *
    */

}


void Board::selectCardBoard(nat r){
    posizione=r;
    emit numCasellaCliccata(r);
}

}
