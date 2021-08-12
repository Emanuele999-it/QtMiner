#include "Model/Header/modelBoard.h"
#include "Model/Header/carta/blocco.h"
#include "Model/Header/carta/crollo.h"
#include "Model/Header/carta/obstruction.h"
#include "Model/Header/carta/tunnel.h"

#include "Model/Header/carta/clonecards.h"
#include <QErrorMessage>
#include <cstdlib>

#include <QDebug>


namespace model{

ModelBoard::ModelBoard(nat nMano, nat nBoard): _nMano(nMano), _nBoard(nBoard),
    _handStuff(CVector<unique_ptr<Card>*>(0)),
    _boardStuff(CVector<unique_ptr<Card>*>(0)){}

void ModelBoard::addCardtoVectors() {

    qDebug()<<"Controller: _nBoard: "<<_nBoard;

    for (nat i = 0; i< _nBoard; ++i)
        _boardStuff.push_back(new unique_ptr<Card>());


    for (nat i = 0; i< _nMano; ++i){
        _handStuff.push_back(new unique_ptr<Card>(estrattoreCasuale()));
    }
}

QString ModelBoard::getImage(nat i, CVector<unique_ptr<Card> *> v) const {
    Card* _carta = v[i]->get()->clone();

    if (dynamic_cast<Obstruction*>(_carta)) {
        if(dynamic_cast<Blocco*>(_carta))
            return "╬(blocco)";
        else
            return "crollo";
    }

    else if (dynamic_cast<CloneCards*>(_carta)){
            return "cloning";
    }

    else if (dynamic_cast<Tunnel*>(_carta)){
        bool *a = dynamic_cast<Tunnel*>(_carta)->getArr();
        if(a[0]==true && a[1]==true && a[2]==true && a[3]==true) {
            return "╬(0)";
        }
        else if(a[0]==false && a[1]==true && a[2]==false && a[3]==true){
            return "═(0)";
        }
        else if(a[0]==true && a[1]==false && a[2]==true && a[3]==false){
            return "║(0)";
        }
        else if(a[0]==false && a[1]==true && a[2]==true && a[3]==false){
            return "╔(0)";
        }
        else if(a[0]==false && a[1]==false && a[2]==true && a[3]==true){
            return "╗(0)";
        }
        else if(a[0]==true && a[1]==true && a[2]==false && a[3]==false){
            return "╚(0)";
        }
        else if(a[0]==true && a[1]==true && a[2]==true && a[3]==false){
            return "╠(0)";
        }
        else if(a[0]==true && a[1]==true && a[2]==false && a[3]==true){
            return "╩(0)";
        }
        else if(a[0]==true && a[1]==false && a[2]==true && a[3]==true){
            return "╣(0)";
        }
        else if(a[0]==true && a[1]==false && a[2]==false && a[3]==true){
            return "╝(0)";
        }

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

    Card* temp = _handStuff[posizioneMano]->get()->clone();

    if((dynamic_cast<Tunnel*>(temp) || dynamic_cast<Blocco*>(temp)) &&
              (_boardStuff[posizioneBoard] == nullptr || _boardStuff[posizioneBoard]->get() == nullptr)){

        _boardStuff[posizioneBoard] = new unique_ptr<Card>(temp);
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
                                      getImage(posizioneBoard, _boardStuff),0);
    }

    else if((dynamic_cast<CloneCards*>(temp) || dynamic_cast<Crollo*>(temp))
             && (_boardStuff[posizioneBoard] != nullptr && _boardStuff[posizioneBoard]->get() != nullptr)){

        if(dynamic_cast<CloneCards*>(temp)){
            _handStuff[posizioneMano]->~unique_ptr();
            _handStuff[posizioneMano] = new unique_ptr<Card>(_boardStuff[posizioneBoard]->get()->clone());
            emit CambiaPosizioneManoBoard(posizioneMano,0,getImage(posizioneMano, _handStuff),"",1);
        }
        //la carta utilizzata è un crollo
        else{
            _boardStuff[posizioneBoard]->~unique_ptr();
            _handStuff[posizioneMano] = new unique_ptr<Card>(estrattoreCasuale());
            emit CambiaPosizioneManoBoard(posizioneMano,posizioneBoard,getImage(posizioneMano, _handStuff),"",2);
        }
    }

    else{
        QErrorMessage *q = new QErrorMessage();
        QString str("Posizione board non valida. Casella occupata, non clonabile oppure non cancellabile");
        q->showMessage(str);
        q->setVisible(true);
        emit changeCardsfailed();
    }
}


void ModelBoard::posizionaAI(){
    nat size = 40;//Qui ci verrebbe un size della nostra board
    bool ok = false; //E' una posizione valida?
    //Qui metto un rand, ma è da rivedere da dove si PARTE a fare algo di conseguenza
    nat generator;
    while(!ok){
        //Qui va in ciclo infinito se non ci sono celle available
        generator = rand() % size;
        if(_boardStuff[generator] == nullptr || _boardStuff[generator]->get() == nullptr){
            _boardStuff[generator] = new unique_ptr<Card>(estrattoreCasuale());
            ok = true;
        }
    }
    //ora diciamo alla view la posizione e immagine
    emit cambiaCellaBoardAI(generator,getImage(generator,_boardStuff));
}


void ModelBoard::evidenziaCellaBoard(nat x, nat y){
    //se il segnale arriva dalla board
    if(y==0)
        _nBoard=x;
    //se invece il segnale arriva dalla mano
    else
        _nMano=x;
}

Card* ModelBoard::estrattoreCasuale(){


    nat generator= rand() % 11 + 1;
    switch(generator){
    case 1:
        return new Blocco();
        break;
    case 2:
        return new Crollo();
        break;
    case 3:
        return new CloneCards();
        break;
    case 4:
        return new Tunnel(true,true,true,true);
        break;
    case 5:
        return new Tunnel(false,true,false,true);
        break;
    case 6:
        return new Tunnel(true,false,true,false);
        break;
    case 7:
        return new Tunnel(false,true,true,false);
        break;
    case 8:
        return new Tunnel(false,false,true,true);
        break;
    case 9:
        return new Tunnel(true,true,false,false);
        break;
    case 10:
        return new Tunnel(true,true,true,false);
        break;
    default:
        return new Tunnel(false,true,true,true);
        break;
    }
}
    /*
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
    */


void ModelBoard::getHandImage(nat pos){
    emit CambiaImmagineMano(pos, getImage(pos,_handStuff));
}

}
