#include "Model\Header\modelBoard.h"
#include "Model/Header/carta/blocco.h"
#include "Model/Header/carta/crollo.h"
#include "Model/Header/carta/obstruction.h"
#include "Model/Header/carta/tunnel.h"

#include "Model/Header/carta/clonecards.h"
#include <QErrorMessage>

#include <iostream>


namespace model{
ModelBoard::ModelBoard(nat nMano, nat nBoard): _nMano(nMano), _nBoard(nBoard),
    _handStuff(CVector<unique_ptr<Card>*>(nMano)),
    _boardStuff(CVector<unique_ptr<Card>*>(nBoard))
{
    for (nat i = 0; i< nBoard; i++)
        _boardStuff.push_back(nullptr);

    for (nat i = 0; i< nMano; i++)
        _handStuff.push_back(nullptr);


/*
      if(_handStuff[nMano] != nullptr)
            std::cout<<" ok funzia";

      if(_boardStuff[nMano] == nullptr)
            std::cout<<"non funzia";
*/
}


QString ModelBoard::getImage(int i)const{
    Card* _carta = getCardBoard(i);

    if (dynamic_cast<Obstruction*>(_carta)) {
        if(dynamic_cast<Blocco*>(_carta))
            return ":/Img/╬(blocco).jpg";
        else
            return ":/Img/r.jpg";
    }else if (dynamic_cast<CloneCards*>(_carta)){
            return ":/Img/sr.jpg";
    }else{
        bool *a = dynamic_cast<Tunnel*>(_carta)->getArr();
        if(a[0]==true && a[1]==true && a[2]==true && a[3]==true)
            return "╬(0)";
        else if(a[0]==false && a[1]==true && a[2]==false && a[3]==true)
            return "═(0)";
        else if(a[0]==true && a[1]==false && a[2]==true && a[3]==false)
            return "║(0)";
        else if(a[0]==false && a[1]==true && a[2]==true && a[3]==false)
            return "╔(2)";
        else if(a[0]==false && a[1]==false && a[2]==true && a[3]==true)
            return ":/Img/╗(0).jpg";
        else if(a[0]==true && a[1]==true && a[2]==false && a[3]==false)
            return ":/Img/╚(0).jpg";
        else if(a[0]==true && a[1]==true && a[2]==true && a[3]==false)
            return ":/Img/╠(0).jpg";
        else
            return ":/Img/╦(0).jpg";
    }
}

Card* ModelBoard::getCardMano(unsigned int posizione) const{
    return _handStuff[posizione]->get();
}

Card* ModelBoard::getCardBoard(unsigned int posizione) const{
    return _boardStuff[posizione]->get();
}

void ModelBoard::posiziona(nat posizioneMano, nat posizioneBoard){

    if(_boardStuff[posizioneBoard] != nullptr && _boardStuff[posizioneBoard]->get() != nullptr){

        unique_ptr<Card>* selezione = new unique_ptr<Card>(
                    _handStuff[posizioneMano]->get()->clone());

        _boardStuff[posizioneBoard]->~unique_ptr();
        _boardStuff[posizioneBoard] = new unique_ptr<Card>(selezione->get()->clone());

        // estrattore casuale per carta mano che non c'è più
        /*
         * chiamata funz estrazione casuale
         * inserimento carta in mano
         *
         *
        */

        //segnale aggiornamento view
        //invio segnale a view nuova carta
        emit CambiaPosizioneManoBoard(posizioneMano, posizioneBoard, selezione->get(), _handStuff[posizioneMano]->get()->clone());


        selezione->~unique_ptr();
    }

    else{
        QErrorMessage *q = new QErrorMessage();
        QString str("Posizione board non valida. Casella occupata");
        q->showMessage(str);
        q->setVisible(true);
    }
}

void ModelBoard::evidenziaCellaBoard(nat p){
    _nBoard=p;
}

void ModelBoard::evidenziaCellaMano(nat p){
    _nMano=p;
}



}
