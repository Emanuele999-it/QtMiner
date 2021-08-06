#include "Model\Header\modelBoard.h"
#include "Model/Header/carta/blocco.h"
#include "Model/Header/carta/crollo.h"
#include "Model/Header/carta/obstruction.h"
#include "Model/Header/carta/tunnel.h"

#include "Model/Header/carta/clonecards.h"
#include <QErrorMessage>
#include <cstdlib>

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


QString ModelBoard::getImage(nat i, CVector<unique_ptr<Card> *> v) const {
    Card* _carta = v[i]->get()->clone();

    if (dynamic_cast<Obstruction*>(_carta)) {
        if(dynamic_cast<Blocco*>(_carta))
            return "╬(blocco)";
        else
            return "r";
    }

    else if (dynamic_cast<CloneCards*>(_carta)){
            return "sr";
    }

    else if (dynamic_cast<Tunnel*>(_carta)){
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
            return "╗(0)";
        else if(a[0]==true && a[1]==true && a[2]==false && a[3]==false)
            return "╚(0)";
        else if(a[0]==true && a[1]==true && a[2]==true && a[3]==false)
            return "╠(0)";
        else
            return "╦(0)";
    }
    else
        return "blank";
}

Card* ModelBoard::getCardMano(nat posizione) const{
    return _handStuff[posizione]->get();
}

Card* ModelBoard::getCardBoard(nat posizione) const{
    return _boardStuff[posizione]->get();
}

void ModelBoard::posiziona(nat posizioneMano, nat posizioneBoard){
//modificare comportmento in caso ci sia carta crollo/blocco
    if(_boardStuff[posizioneBoard] == nullptr || _boardStuff[posizioneBoard]->get() == nullptr){


        _boardStuff[posizioneBoard] = new unique_ptr<Card>(
                                _handStuff[posizioneMano]->get()->clone());

        /*
         * Funzione controllo compatibilità carta mano->board
         *
        */

        _handStuff[posizioneMano]->~unique_ptr();
        _handStuff[posizioneMano] = new unique_ptr<Card>(estrattoreCasuale());


        //segnale aggiornamento view
        //invio segnale a view nuova carta
        emit CambiaPosizioneManoBoard(posizioneMano, posizioneBoard,
                                      getImage(posizioneMano, _handStuff),
                                      getImage(posizioneBoard, _boardStuff));
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

Card* ModelBoard::estrattoreCasuale(){

    nat generator= rand() % 11 + 1;

    if(generator == 1) return new Blocco();
    else if(generator == 2) return new Crollo();
    else if(generator == 3) return new CloneCards();
    else if(generator == 4) return new Tunnel(true,true,true,true);
    else if(generator == 5) return new Tunnel(false,true,false,true);
    else if(generator == 6) return new Tunnel(true,false,true,false);
    else if(generator == 7) return new Tunnel(false,true,true,false);
    else if(generator == 8) return new Tunnel(false,false,true,true);
    else if(generator == 9) return new Tunnel(true,true,false,false);
    else if(generator == 10) return new Tunnel(true,true,true,false);
    else return new Tunnel(false,true,true,true);
}

void ModelBoard::deleteAllCards(){
    for(nat i=0;i<_nMano;i++)
        if(_handStuff[i])
            _handStuff[i]->~unique_ptr();

    for(nat i=0;_boardStuff[i] && i<_nBoard;i++)
        if(_boardStuff[i])
            _boardStuff[i]->~unique_ptr();
}

}
