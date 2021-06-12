#include "../Header/carta/crollo.h"

Crollo::Crollo() :type(ObstructionType::crollo){}

Crollo* Crollo::clone() const{
    return new Crollo(*this);
}

ObstructionType Crollo::getType() const {
    return type;
}

Crollo::Crollo(const Crollo& c) : type(c.type) {}

Crollo& Crollo::operator =(const Crollo& c){
    type=c.type;
    return *this;
}

Crollo::~Crollo(){}
