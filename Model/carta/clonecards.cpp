#include "Model/Header/carta/clonecards.h"

CloneCards::~CloneCards(){}

CloneCards::CloneCards(){}

CloneCards* CloneCards::clone() const {
    return new CloneCards(*this);
}

CloneCards::CloneCards(const CloneCards& c){}

std::string CloneCards::getName() const {
    return "cloning";
}


