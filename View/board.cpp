#include "View\Header\screens\gameScreen\Board\board.h"
#include "Model/Header/carta/card.h"
#include "Model/Header/carta/blocco.h"
#include "Model/Header/carta/tunnel.h"

#include <QGraphicsScene>

using std::vector;

namespace view {

Board::Board(const QSize &size, const vector <unique_ptr<Card>*> &cells) :
    dimensione(size),
    celle(cells){

    createBoard();
}

void Board::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    Q_UNUSED(painter);
}
/**
 * @brief Board::createBoard il mio scopo è di creare un vettore che contenga inizio, i
 * tre finali e le occasionali carte che piazzero'
 */
void Board::createBoard() {
    int lunghezza = dimensione.width() * dimensione.height();
    //incominciamo con l'allungare il vector "celle" creato nel .h
    for (int i = 0; i<=lunghezza; i++){
       unique_ptr<Card>* carta;
       if (celle[i]!=NULL){
           celle.push_back(carta);
       }
    }
}
/**
 * @brief Board::tick la logica del tutto è integrata in tick
 */
void Board::turn(){

}

}
