#include "Model/Header/carta/card.h"

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
