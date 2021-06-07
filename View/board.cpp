#include "View\Header\screens\gameScreen\Board\board.h"
#include "Model/Header/carta/card.h"
#include "Model/Header/carta/blocco.h"
#include "Model/Header/carta/tunnel.h"
#include "View\casella.cpp"

#include <QGraphicsScene>

using std::vector;

namespace view {

Board::Board(const QSize &size,  vector <Casella*> caselle) :
    _dimensione(size),
    _caselle(caselle){

}


void Board::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Q_UNUSED(option);
    Q_UNUSED(widget);
    Q_UNUSED(painter);

}


}
