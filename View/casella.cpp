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
 *              interrogherà modelBoard per ottenere l'immagine che infine verrà
 *              assegnata a casella
*/
Casella::Casella(nat p, QPushButton*pushbutton):QPushButton(pushbutton), pos(p) {


    iconStd=QIcon(":/Img/sr.jpg");
    onHover=QIcon(":/Img/r.jpg");
    setIcon(iconStd);
    connect(this,&QPushButton::clicked, this, &Casella::supportCasellaCliccata);

    //creare segnale di supposto per emettere casellaCliccata con la posizione!!!

}

/*
 * PROBLEMA: capire come modificare contemporaneamente IconStd e onHover
*/

void Casella::cambiaImmagine(QString i){

    // path imagine standard
    iconStd=QIcon(":/Img/"+i+".jpg");

    // path immagine hover
    onHover=QIcon(":/Img/"+i+"h.jpg");
    setIcon(iconStd);
}

void Casella::supportCasellaCliccata(){

    //mettere cambio icona std

    emit casellaCliccata(pos);
}

/*
 * ATTENZIONE: l'hover sostituisce l'immagine con una nuova immagine:
 *              al momento per semplificare le cose l'immagine hover non centra nulla
*/

void Casella::enterEvent(QEvent *event){
  setIcon(onHover);
}

void Casella::leaveEvent(QEvent *event){
  setIcon(iconStd);
}

}
