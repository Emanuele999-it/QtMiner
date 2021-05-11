#include "Header/card.h"

Card::Card(bool n) : canBeUsed(n) {}

bool Card::get_canBeUsed(){return canBeUsed;}

Card::~Card(){}

void Card::setUsage(bool tORf){
    canBeUsed=tORf;
}
