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


    IconStd=QIcon(":/Img/sr.jpg");
    onhover=QIcon(":/Img/r.jpg");
    setIcon(IconStd);
    connect(this,&QPushButton::clicked, this, &Casella::supportCasellaCliccata);

    //creare segnale di supposto per emettere casellaCliccata con la posizione!!!

}

void Casella::cambiaImmagine(QString i){
    IconStd=QIcon(i);
    setIcon(IconStd);
}

void Casella::supportCasellaCliccata(){
    emit casellaCliccata(pos);
}

/*
 * ATTENZIONE: l'hover sostituisce l'immagine con una nuova immagine:
 *              al momento per semplificare le cose l'immagine hover non centra nulla
*/

void Casella::enterEvent(QEvent *event){
  setIcon(onOver);
}

void Casella::leaveEvent(QEvent *event){
  setIcon(IconStd);
}

}
