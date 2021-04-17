#include "View/Header/casella.h"
#include <QtGui>
#include <random>

bool randomBool() {
    static auto gen = std::bind(std::uniform_int_distribution<>(0,1),std::default_random_engine());
    return gen();
}


Casella :: Casella(){
    for (int i=0,n=0;i<4;i++) {
        bool rand = randomBool();
        if (rand)
            n++;

        if (i>=2 && n<=2)
            Casella::Cardinali[i]= true;
        //Ok ora faccio che devono essere + di 2 bool
        else
            Casella::Cardinali[i]= rand;
    }
    //Ok ora i cardinali sono fatti
    //Ora dobbiamo creare randomicamnte il tipo di carta


}

//Dovrei ridefinire il costruttore
/*
bool Casella::tipoCarta(){
    if(dynamic_cast<Ostacolo*>(this))
        return false;
    else
        return true;
}
*/
