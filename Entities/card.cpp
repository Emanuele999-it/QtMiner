#include "Header/card.h"

Card::Card(): canBeUsed(false) {}

bool Card::get_canBeUsed(){return canBeUsed;}

Card::~Card(){}

void Card::setUsage(bool tORf){
    canBeUsed=tORf;
}
