#include "Model/Header/modelBoard.h"
#include "Model/Header/carta/blocco.h"
#include "Model/Header/carta/crollo.h"
#include "Model/Header/carta/obstruction.h"
#include "Model/Header/carta/tunnel.h"

#include "Model/Header/carta/clonecards.h"
#include <QMessageBox>
#include <cstdlib>

#include <QDebug>


#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>


namespace model{

ModelBoard::ModelBoard(nat nMano, nat nBoard): _nMano(nMano), nCaselle(nBoard),
    _handStuff(CVector<unique_ptr<Card>*>(0)),
    _boardStuff(CVector<unique_ptr<Card>*>(0)){}

void ModelBoard::addCardtoVectors() {

    for (nat i = 0; i< nCaselle; ++i)
        _boardStuff.push_back(new unique_ptr<Card>());


    for (nat i = 0; i< _nMano; ++i){
        _handStuff.push_back(new unique_ptr<Card>(estrattoreCasuale()));
    }
}

QString ModelBoard::getImage(nat i, CVector<unique_ptr<Card> *> v) const {

    if(v[i] == nullptr || v[i]->get() == nullptr)
        return "blank";

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
        return "sr";
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

        qDebug()<<"ModelBoard: prima di bug: ";
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
        if(dynamic_cast<Tunnel*>(temp) || dynamic_cast<Blocco*>(temp)){
            emit changeCardsfailed("Posizione board non valida. Non è possibile posizionare una carta Percorso in una casella occupata");
        }

        else if(dynamic_cast<CloneCards*>(temp)){
            emit changeCardsfailed("Posizione board non valida. Non è possibile clonare una casella vuota");
        }

        else
            emit changeCardsfailed("Posizione board non valida. Non è possibile demolire una casella vuota");
    }
}


void ModelBoard::posizionaAI(){
    nat size =_boardStuff.get_size();
    //Qui metto un rand, ma è da rivedere da dove si PARTE a fare algo di conseguenza
    nat generator;
    bool ok=false;

    while(size>0 && !ok){
        generator = rand() % nCaselle + 1;
        if(_boardStuff[generator] == nullptr || _boardStuff[generator]->get() == nullptr){
            _boardStuff[generator] = new unique_ptr<Card>(estrattoreCasuale(4));
            ok = true;
        }
        size--;
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

Card* ModelBoard::estrattoreCasuale(int i){


    nat generator= rand() % 11 + i;
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
        return new Tunnel(true,true,true,true);     // ╬
        break;
    case 5:
        return new Tunnel(false,true,false,true);   // ═
        break;
    case 6:
        return new Tunnel(true,false,true,false);   // ║
        break;
    case 7:
        return new Tunnel(false,true,true,false);   // ╔
        break;
    case 8:
        return new Tunnel(false,false,true,true);   // ╗
        break;
    case 9:
        return new Tunnel(true,true,false,true);    // ╩
        break;
    case 10:
        return new Tunnel(true,false,true,true);    // ╣
        break;
    case 11:
        return new Tunnel(true,false,false,true);   // ╝
        break;
    case 12:
        return new Tunnel(true,true,false,false);   // ╚
        break;
    case 13:
        return new Tunnel(true,true,true,false);    // ╠
        break;
    default:
        return new Tunnel(false,true,true,true);    // ╦
        break;
    }
}

void ModelBoard::getHandImage(nat pos){
    emit CambiaImmagineMano(pos, getImage(pos,_handStuff),0);
}

void ModelBoard::scartaCartaMano(){
    _handStuff[_nMano]->~unique_ptr();
    _handStuff[_nMano] = new unique_ptr<Card>(estrattoreCasuale());
    emit CambiaImmagineMano(_nMano,getImage(_nMano,_handStuff),1);
}

void ModelBoard::saveLastGame(){
    //perndo vettore _boardStuff e lo dovrei copiare in un json per poi passarlo al controller

    QFile file("lastgameboard.json");
    //file.open(QIODevice::ReadWrite);
    if(!file.open(QIODevice::ReadWrite)) {
        qDebug() << "File open error";
    } else {
        qDebug() <<"JSONTest2 File open!";
    }

    // Clear the original content in the file
    file.resize(0);

    // Add a value using QJsonArray and write to the file
    QJsonArray jsonArray;

    if(nCaselle == 40){
        for(int i = 0; i < 8; i++) {
            QJsonObject jsonObject;
            jsonObject.insert("Riga",QJsonArray() << i << getImage(0+ i*5, _boardStuff)<< getImage(1+i*5, _boardStuff)<< getImage(2+i*5, _boardStuff)
                              << getImage(3+i*5, _boardStuff) << getImage(4+i*5, _boardStuff));
            jsonArray.append(jsonObject);
        }
    }
    else if (nCaselle==50){
        for(int i = 0; i < 10; i++) {
            QJsonObject jsonObject;
            jsonObject.insert("Riga",QJsonArray() << i << getImage(0+ i*5, _boardStuff)<< getImage(1+i*5, _boardStuff)<< getImage(2+i*5, _boardStuff)
                              << getImage(3+i*5, _boardStuff) << getImage(4+i*5, _boardStuff));
            jsonArray.append(jsonObject);
        }
    }
    else if (nCaselle==60){
        for(int i = 0; i < 10; i++) {
            QJsonObject jsonObject;
            jsonObject.insert("Riga",QJsonArray() << i << getImage(0+ i*6, _boardStuff)<< getImage(1+i*6, _boardStuff)<< getImage(2+i*6, _boardStuff)
                              << getImage(3+i*6, _boardStuff) << getImage(4+i*6, _boardStuff)<< getImage(5+i*6, _boardStuff));
            jsonArray.append(jsonObject);
        }
    }
    else if (nCaselle==70){
        for(int i = 0; i < 10; i++) {
            QJsonObject jsonObject;
            jsonObject.insert("Riga",QJsonArray() << i << getImage(0+ i*7, _boardStuff)<< getImage(1+i*7, _boardStuff)<< getImage(2+i*7, _boardStuff)
                              << getImage(3+i*7, _boardStuff) << getImage(4+i*7, _boardStuff) << getImage(5+i*7, _boardStuff) << getImage(6+i*7, _boardStuff));
            jsonArray.append(jsonObject);
        }
    }
    else{
        for(int i = 0; i < 10; i++) {
            QJsonObject jsonObject;
            jsonObject.insert("Riga",QJsonArray() << i << getImage(0+ i*8, _boardStuff)<< getImage(1+i*8, _boardStuff)<< getImage(2+i*8, _boardStuff)
                              << getImage(3+i*8, _boardStuff)  << getImage(4+i*8, _boardStuff) << getImage(5+i*8, _boardStuff) << getImage(6+i*8, _boardStuff) << getImage(7+i*8, _boardStuff));
            jsonArray.append(jsonObject);
        }
    }

      QJsonDocument jsonDoc;
      jsonDoc.setArray(jsonArray);
      file.write(jsonDoc.toJson());
      file.close();
      qDebug() << "Write to file";


}

}
