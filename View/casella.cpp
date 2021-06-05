#include "View\Header\screens\gameScreen\Board\casella.h"
#include "Model\Header\carta\obstruction.h"
#include "Model\Header\carta\blocco.h"
#include "Model\Header\carta\tunnel.h"
#include "Model\Header\carta\clonecards.h"

#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOptionGraphicsItem>

namespace view {

Casella::Casella(QGraphicsItem *i, int position, qreal size, Card* carta)
    :QGraphicsItem(i), _position(position), _size(size), _carta(carta){}

QRectF Casella::rect() const {
    return QRectF(0, 0, _size, _size);;
}

void Casella::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Q_UNUSED(widget);
    Q_UNUSED(option);

    QString immagine;

    if (dynamic_cast<Obstruction*>(_carta)) {
        if(dynamic_cast<Blocco*>(_carta))
            immagine= ":/Img/╬(blocco).jpg";
        else
            immagine= ":/Img/r.jpg";
    }else if (dynamic_cast<CloneCards*>(_carta)){
            immagine= ":/Img/sr.jpg";
    }else{
        bool *a = dynamic_cast<Tunnel*>(_carta)->getArr();
        if(a[0]==true && a[1]==true && a[2]==true && a[3]==true)
            immagine= ":/Img/╬(0).jpg";
        else if(a[0]==false && a[1]==true && a[2]==false && a[3]==true)
            immagine= ":/Img/═(0).jpg";
        else if(a[0]==true && a[1]==false && a[2]==true && a[3]==false)
            immagine= ":/Img/║(0).jpg";
        else if(a[0]==false && a[1]==true && a[2]==true && a[3]==false)
            immagine= ":/Img/╔(2).jpg";
        else if(a[0]==false && a[1]==false && a[2]==true && a[3]==true)
            immagine= ":/Img/╗(0).jpg";
        else if(a[0]==true && a[1]==true && a[2]==false && a[3]==false)
            immagine= ":/Img/╚(0).jpg";
        else if(a[0]==true && a[1]==true && a[2]==true && a[3]==false)
            immagine= ":/Img/╠(0).jpg";
        else
            immagine= ":/Img/╦(0).jpg";
    }


    QPixmap pixmap = QPixmap(immagine);
    painter->drawPixmap(QRect(0,0,_size,_size),pixmap);
}

/**
 * @brief Casella::mouseNonHover evento quando non si va sopra una carta/casella
 * @param event
 */
void Casella::mouseNonHover(QGraphicsSceneMouseEvent *event) {
    Q_UNUSED(event);

    emit mouseNonHover();
}

/**
 * @brief Casella::mouseHover evento quando si va sopra una carta/casella
 * @param event
 */
void Casella::mouseHover(QGraphicsSceneMouseEvent *event) {
    Q_UNUSED(event);

    emit mouseHover();
}

void Casella::mouseClick(QGraphicsSceneMouseEvent *event) {
    Q_UNUSED(event);

    emit click(this);
}

bool Casella::returnSelected() const{
    return _selected;
}

void Casella::cambiaSelected(bool s){
    _selected = s;
}

/**
 * @brief Casella::returnTipo torna la carta
 * @return
 */
Card* Casella::returnTipo() const {
    return _carta;
}


int Casella::returnPosizione(){
    return _position;
}

}
