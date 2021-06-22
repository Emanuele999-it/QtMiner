
/*
*   PROBLEMA RISCONTRATO: se card fosse classe astratta non compilerebbe
*                         perché il costruttore di unique_ptr costruisce un
*                         oggetto di copia (quindi dovrebbe costruire Card)
*
*   SOLUZIONE TEMPORANEA: Card classe concreta con campo
*
*    ATTENZIONE: Per specifica del progetto
*/

#include "Model\Header\carta\card.h"

Card::Card(bool n) : canBeUsed(n) {}

bool Card::get_canBeUsed(){return canBeUsed;}

Card::~Card(){}

void Card::setUsage(bool tORf){
    canBeUsed=tORf;
}
/*
Card* Card::clone() const{
    return new Card(*this);
}

Card::Card(const Card& c): canBeUsed(c.canBeUsed){}
*/
