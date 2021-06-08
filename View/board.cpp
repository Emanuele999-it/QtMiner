#include "View\Header\screens\gameScreen\Board\board.h"

#include <QGraphicsScene>

using std::vector;

namespace view {

Board::Board(const QSize &size,  model::ModelBoard caselle) :
    _dimensione(size),
    _caselle(caselle){


};


void Board::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Q_UNUSED(option);
    Q_UNUSED(widget);
    Q_UNUSED(painter);

}

void Board::selectCard(const Card*){
    //allora si fa il for di tutto l'array e se si trova la card nell'array si mette true
    for(_caselle.)
}

}
