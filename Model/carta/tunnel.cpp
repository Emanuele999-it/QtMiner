<<<<<<< HEAD
﻿#include "../Header/carta/tunnel.h"
=======
﻿#include "Model\Header\carta\tunnel.h"
>>>>>>> ale

Tunnel::Tunnel(bool North, bool East, bool South, bool West): Card() {
    arr[0]=North;
    arr[1]=East;
    arr[2]=South;
    arr[3]=West;
}

Tunnel::~Tunnel(){
    delete[] arr;
}

Tunnel* Tunnel::clone() const {
    return new Tunnel(*this);
}

void Tunnel::copia(const bool* a){
    for(int i=0;i<4;i++){
        arr[i]=a[i];
    }
}

Tunnel::Tunnel(const Tunnel &t){
   copia(t.arr);
}

Tunnel& Tunnel::operator =(const Tunnel& t){
    copia(t.arr);
    return *this;
}

bool* Tunnel::getArr(){
    return arr;
}

