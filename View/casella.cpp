#include "View\Header\screens\gameScreen\Board\casella.h"


#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOptionGraphicsItem>

namespace view {

Casella::Casella(QGraphicsItem *i, int position, qreal size, std::vector<bool> tipo)
    :QGraphicsItem(i), _position(position), _size(size), _tipo(tipo), _selected(false){}



}
