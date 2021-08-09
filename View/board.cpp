#include "View/Header/screens/gameScreen/Board/board.h"

#include <QGraphicsScene>


namespace view {

/*********************** Board ******************************************************************/



Board::Board(const nat &i): posizioneBoard(0){

    QVector<Casella*> vettoreCaselleBoard(i);
    /*
        for(nat counter=0; counter<i; counter++){
        vettoreCaselleBoard[counter]=new Casella(counter);
        connect(vettoreCaselleBoard[counter],SIGNAL(casellaCliccata(nat)), this, SLOT(selectCardBoard(nat)));
    }*/
    }
    /*
     * creazione vettore delle caselle + connessione di ciascuna casella con lo slot selectCardBoard
     *
    */



/*void Board::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Q_UNUSED(option);
    Q_UNUSED(widget);
    Q_UNUSED(painter);

}*/

//getCardModel è nel model
/*

*/

/*
void Board::selectCardBoard(nat ...){
    emit pincopallino();
*/

void Board::selectCardBoard(nat r){
    posizioneBoard=r;
    emit numCasellaCliccataBoard(r);
}

void Board::addCardBoard(nat n, QString c){
    vettoreCaselleBoard[n]->cambiaImmagine(c);
}

Casella* Board::getCasella(nat i){
    return vettoreCaselleBoard[i];
}

/*********************** Mano ******************************************************************/

Mano::Mano(const nat &i) : posizioneMano(0){
    QVector<Casella*> vettoreCaselleMano(i);
    /*
        for(nat counter=0; counter<i; counter++){
            vettoreCaselleMano[counter]=new Casella(counter);
            connect(vettoreCaselleMano[counter],SIGNAL(casellaCliccata(nat)), this, SLOT(selectCardMano(nat)));
        }
    */
}

void Mano::selectCardMano(nat r){
    posizioneMano=r;
    emit numCasellaCliccataMano(r);
}

void Mano::addCardMano(nat n, QString c){
    vettoreCaselleMano[n]->cambiaImmagine(c);
}

Casella* Mano::getCasella(nat i){
    return vettoreCaselleMano[i];
}

}
