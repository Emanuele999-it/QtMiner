﻿#include "View\Header\screens\gameScreen\Board\board.h"

#include <QGraphicsScene>

using std::vector;

namespace view {

Board::Board(const unsigned int& i){

    // moficare costruttore per avere numero casella corretto
    vector<Casella*> vettoreCaselle;

    //connect(Casella,&QPushButton::clicked, this, &MainWindow::TutorialRequest);

}


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
}
*/

/*
 * Questo metodo dovrebbe essere della mano, ma siccome creiamo 2 oggetti Board,
 * 1 per la mano ed 1 per il campo il metodo è lo stesso
 *
void Board::selectCardHand(const Card* confronto){
    //allora si fa il for di tutto l'array e se si trova la card nell'array si mette true
    for(int i=0; i<vettoreCaselle.capacity();i++){
        if(_caselle.getCardMano(i) == confronto){ //conftonto i loro L-valori per evitare FP
            _caselle.cambiaSelezioneMano(i);
        }
    }
}
*/
}
