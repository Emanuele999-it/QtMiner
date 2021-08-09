#include "Model/Header/carta/blocco.h"


Blocco::Blocco() :type(ObstructionType::blocco){}

Blocco* Blocco::clone() const{
    return new Blocco(*this);
}

ObstructionType Blocco::getType() const {
    return type;
}

Blocco::Blocco(const Blocco& b) : type(b.type) {}

Blocco& Blocco::operator =(const Blocco& b){
    type=b.type;
    return *this;
}

Blocco::~Blocco(){}
