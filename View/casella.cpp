#include "View\Header\screens\gameScreen\Board\casella.h"
#include "Model\Header\carta\obstruction.h"
#include "Model\Header\carta\blocco.h"
#include "Model\Header\carta\tunnel.h"
#include "Model\Header\carta\clonecards.h"
#include "Model\Header\modelBoard.h"

#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOptionGraphicsItem>

namespace view {

/*
 * cosa voglio: casella invia segnale con la propria posizione
 *              che verrà ricevuto da board, che a sua volta
 *              interrogherà model board per ottenere l'immagine che infine verrà
 *              assegnata a casella
*/
Casella::Casella(nat p, QPushButton*pushbutton):QPushButton(pushbutton), pos(p) {

    setIcon(QIcon(":/Img/sr.png"));
    connect(this,&QPushButton::clicked, this, &Casella::casellaCliccata(pos));
}

void Casella::cambiaImmagine(QString i){
    setIcon(QIcon(i));
}

/*
void Casella::paint(QPainter *painter, QPushButton *pushbutton): QPushButton()  {
    Q_UNUSED(widget);
    Q_UNUSED(pushbutton);



    QPixmap pixmap = QPixmap(immagine);
    painter->drawPixmap(QRect(0,0,_size,_size),pixmap);
    */
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
