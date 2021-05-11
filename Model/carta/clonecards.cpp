#include "Header/clonecards.h"

CloneCards::CloneCards(){}

CloneCards* CloneCards::clone() const {
    return new CloneCards(*this);
}

CloneCards::CloneCards(const CloneCards& c){}
