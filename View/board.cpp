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

/**
 * @brief Board::createBoard il mio scopo è di creare un vettore che contenga inizio, i
 * tre finali e le occasionali carte che piazzero'
 */
void Board::createBoard() {
    for (auto i = celle.begin(); i != celle.end(); i++){

    }
}

void Board::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Q_UNUSED(widget);


}
/**
 * @brief Board::tick la logica del tutto è integrata in tick
 */
void Board::turn(){

}

}
