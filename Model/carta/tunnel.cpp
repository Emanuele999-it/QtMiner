#include "Model/Header/carta/tunnel.h"


Tunnel::Tunnel(bool North, bool East, bool South, bool West): Card(), arr(new bool[4]){
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
   arr = new bool[4];
   copia(t.arr);
}

Tunnel& Tunnel::operator =(const Tunnel& t){
    copia(t.arr);
    return *this;
}

bool* Tunnel::getArr(){
    return arr;
}

std::string Tunnel::getName() const {
    if(arr[0]==true && arr[1]==true && arr[2]==true && arr[3]==true) {
        return "╬";
    }
    else if(arr[0]==false && arr[1]==true && arr[2]==false && arr[3]==true){
        return "═";
    }
    else if(arr[0]==true && arr[1]==false && arr[2]==true && arr[3]==false){
        return "║";
    }
    else if(arr[0]==false && arr[1]==true && arr[2]==true && arr[3]==false){
        return "╔";
    }
    else if(arr[0]==false && arr[1]==false && arr[2]==true && arr[3]==true){
        return "╗";
    }
    else if(arr[0]==true && arr[1]==true && arr[2]==false && arr[3]==false){
        return "╚";
    }
    else if(arr[0]==true && arr[1]==true && arr[2]==true && arr[3]==false){
        return "╠";
    }
    else if(arr[0]==true && arr[1]==true && arr[2]==false && arr[3]==true){
        return "╩";
    }
    else if(arr[0]==true && arr[1]==false && arr[2]==true && arr[3]==true){
        return "╣";
    }
    else if(arr[0]==true && arr[1]==false && arr[2]==false && arr[3]==true){
        return "╝";
    }

    else
        return "╦";
}
