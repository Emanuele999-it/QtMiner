#include "Header/tunnel.h"

Tunnel::Tunnel(bool North, bool East, bool South, bool West){
    arr[0]={North};
    arr[1]={East};
    arr[2]={South};
    arr[3]={West};
}

Tunnel::~Tunnel(){
    delete[] arr;
}

Card& Tunnel::clone(){
    //return Tunnel(arr[0],arr[1],arr[2],arr[3]);
}
