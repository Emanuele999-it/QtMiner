#include "Model/Header/modelBoard.h"
#include "Model/Header/carta/blocco.h"
#include "Model/Header/carta/crollo.h"
#include "Model/Header/carta/obstruction.h"
#include "Model/Header/carta/tunnel.h"

#include "Model/Header/carta/clonecards.h"
#include <QMessageBox>
#include <cstdlib>

#include <QDebug>
#include <QVector>

#include <QErrorMessage>

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>


namespace model{

ModelBoard::~ModelBoard(){
    _handStuff.~CVector();
    _boardStuff.~CVector();
}

ModelBoard::ModelBoard(const ModelBoard &m): _nMano(m._nMano), nCaselle(m.nCaselle),
    _handStuff(m._handStuff),
    _boardStuff(m._boardStuff){}

ModelBoard& ModelBoard::operator=(const ModelBoard& m){
    if(this!=&m){
        _handStuff.~CVector();
        _boardStuff.~CVector();

        _nMano=m._nMano;
        nCaselle=m.nCaselle;

        CVector<unique_ptr<Card>*> _handStuff(m._handStuff) ;
        CVector<unique_ptr<Card>*> _boardStuff(m._boardStuff) ;
    }
    return *this;
}

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

    if(v[i] == nullptr || v[i]->get() == nullptr){
        return "blank";
    }
    else
        return QString::fromStdString(v[i]->get()->getName());
}

Card* ModelBoard::getCardMano(nat posizione) const{
    return _handStuff[posizione]->get();
}

Card* ModelBoard::getCardBoard(nat posizione) const{
    return _boardStuff[posizione]->get();
}

void ModelBoard::path(int cartaPrecedente, QVector<nat> &posizioni, QVector<nat> &controllate, int posizioneAttuale) const{
    if((posizioneAttuale < 0) || posizioneAttuale>=nCaselle || ((cartaPrecedente%(nCaselle/10) == 0) && (posizioneAttuale == cartaPrecedente-1)) || ((cartaPrecedente%(nCaselle/10) == (nCaselle/10-1)) && (posizioneAttuale == cartaPrecedente+1))){
        qDebug()<<"Posizione Fuori board"<< cartaPrecedente%(nCaselle/10)<< posizioneAttuale<< cartaPrecedente-1;
        return;
    }

    //Caso Base: la posizione che staimo controllando è vuota:
    if(_boardStuff[posizioneAttuale]== nullptr || _boardStuff[posizioneAttuale]->get()==nullptr){
        posizioni.push_back(posizioneAttuale);
        return;
    }

    else{
        //Nel caso sia il primo ciclo prendiamo in considerazione la cella in posizioneAttuale
        Tunnel* t = dynamic_cast<Tunnel*>(_boardStuff[posizioneAttuale]->get()->clone());

        for(int i=0;i<4 && t;i++){
            qDebug()<< *(t->getArr()+i);
        }

        if(t!=nullptr){
            //se la posizione che si sta per controllare è già stata controllata esci
            if(controllate.contains(posizioneAttuale))
                return;

            controllate.push_back(posizioneAttuale);

            //NORD
            if(*(t->getArr())){
                qDebug()<<"Pre:NORD";
                path(posizioneAttuale,posizioni,controllate,posizioneAttuale-(nCaselle/10));
            }

            //EST
            if(*(t->getArr()+1)){
                qDebug()<<"Pre:EST";
                path(posizioneAttuale,posizioni,controllate,posizioneAttuale+1);
            }

            //SUD
            if(*(t->getArr()+2)){
                qDebug()<<"Pre:SUD";
                path(posizioneAttuale,posizioni,controllate,posizioneAttuale+(nCaselle/10));
            }

            //OVEST
            if(*(t->getArr()+3)){
                qDebug()<<"Pre:OVEST";
                path(posizioneAttuale,posizioni,controllate,posizioneAttuale-1);
            }
        }
        //se non è un tipo tunnel ma blocco non si fa nulla

    }
}

double ModelBoard::checkAround(nat posizione, Card *carta) const{
    if(dynamic_cast<Blocco*>(carta))
        return true;

    //controllo nord
    if((posizione/(nCaselle/10)) != 0){//se true carta a nord è fuori dalla griglia -> non controllare
        if((_boardStuff[posizione-(nCaselle/10)] != nullptr) && (_boardStuff[posizione-(nCaselle/10)]->get() != nullptr)){
            //se carta blocco va bene
            Tunnel* c= dynamic_cast<Tunnel*>(_boardStuff[posizione-(nCaselle/10)]->get()->clone());
            if(c){
                if(((*(c->getArr()+2)) == *(dynamic_cast<Tunnel*>(carta)->getArr()))){//devo controllare il sud della casella sovrastante
                }
                else
                    return false;
            }
        }
    }
    //controllo est
    if((posizione+1)%((nCaselle/10)) > (posizione)%((nCaselle/10))){//se false significhe che si è andati a capo della riga -> non controllare
        if(_boardStuff[posizione+1] != nullptr && _boardStuff[posizione+1]->get() != nullptr){
            //se carta blocco va bene
            Tunnel* c= dynamic_cast<Tunnel*>(_boardStuff[posizione+1]->get()->clone());
            if(c){
                if(((*(c->getArr()+3)) == *((dynamic_cast<Tunnel*>(carta)->getArr())+1))){//devo controllare l'ovest della casella di destra
                }
                else
                    return false;
            }
        }
    }
    //controllo sud
    if(posizione + (nCaselle/10) < nCaselle){// se >nCaselle significa che si sta uscendo dalla griglia -> non controllare
        if(_boardStuff[posizione+(nCaselle/10)] != nullptr && _boardStuff[posizione+(nCaselle/10)]->get() != nullptr){
            //se carta blocco va bene
            Tunnel* c= dynamic_cast<Tunnel*>(_boardStuff[posizione+(nCaselle/10)]->get()->clone());
            if(c){
                if(((*(c->getArr())) == *((dynamic_cast<Tunnel*>(carta)->getArr())+2))){//devo controllare il nord della casella sottostante
                }
                else
                    return false;
            }
        }
    }
    //controllo ovest
    if((posizione-1)%((nCaselle/10)) < (posizione)%((nCaselle/10))){//se true significa che si è andati sulla riga precedente -> non controllare
        if(_boardStuff[posizione-1] != nullptr && _boardStuff[posizione-1]->get() != nullptr){
            //se carta blocco va bene
            Tunnel* c= dynamic_cast<Tunnel*>(_boardStuff[posizione-1]->get()->clone());
            if(c){
                if(((*(c->getArr()+1)) == *((dynamic_cast<Tunnel*>(carta)->getArr())+3))){//devo controllare l'ovest della casella di destra
                }
                else
                    return false;
            }
        }
    }
    return true;
}

void ModelBoard::posiziona(){
//modificare comportmento in caso ci sia carta crollo/blocco
    bool win = false;
    Card* temp = _handStuff[_nMano]->get()->clone();

    /**
      *Controlla se la carta è tunnel o se è obstrucion controlla se nella posizione esiste una carta, inoltre controlla se è start oppure se legale
      */

    if((dynamic_cast<Tunnel*>(temp) || (dynamic_cast<Obstruction*>(temp) && (dynamic_cast<Obstruction*>(temp)->getType() == ObstructionType::blocco))) &&
            (_boardStuff[_nBoard] == nullptr || _boardStuff[_nBoard]->get() == nullptr)){

        QVector<nat> posizioni, controllate;

        path(nCaselle-((nCaselle/10)/2+1),posizioni,controllate,nCaselle-((nCaselle/10)/2+1));

        qDebug()<<"******************************";
        for(auto i= posizioni.begin(); i<posizioni.end();++i){
           qDebug()<<*i;
        }
        qDebug()<<"******************************";
        if((_nBoard == nCaselle-(nCaselle/10-2) && (dynamic_cast<Obstruction*>(temp))? dynamic_cast<Obstruction*>(temp)->getName()=="╬b" : false)){
            qDebug() << "Qui entra se mossa non valida";
            emit changeCardsfailed("Non si puo mettere un blocco allo start!");
        }
        else if((posizioni.contains(_nBoard) || ((dynamic_cast<Obstruction*>(temp) && (dynamic_cast<Obstruction*>(temp)->getType() == ObstructionType::blocco))))
                                                                    && checkAround(_nBoard,temp)){//se è la root si mette (se non gia occupata) || é una cella detro posizioni valide
            qDebug() << "Qui entra se mossa valida";
            _boardStuff[_nBoard] = new unique_ptr<Card>(temp);
                /*
             * Funzione controllo compatibilità carta mano->board
             *
             */
            _handStuff[_nMano]->~unique_ptr();
            _handStuff[_nMano] = new unique_ptr<Card>(estrattoreCasuale());

            posizioni.clear();
            controllate.clear();

            //segnale aggiornamento view

            //invio segnale a view nuova carta
            if(_nBoard ==1 || _nBoard == nCaselle/10-2){
                win == true;
                emit CambiaPosizioneManoBoard(_nMano, _nBoard,
                                              getImage(_nMano, _handStuff),
                                          "gold",0);//mettere carta con pepita e interompere il gioco
                emit userWin("Nome");
                qDebug()<<"Hai trovato il tesoro";
            }
            else{
                emit CambiaPosizioneManoBoard(_nMano, _nBoard,
                                              getImage(_nMano, _handStuff),
                                          getImage(_nBoard, _boardStuff),0);
            }
        }
        else{
            qDebug()<<"Modelboard: errore";
            emit changeCardsfailed("Posizione non valida. Non è possibile posizionare una carta Percorso non collegata a quelle adiacenti");
        }

    }
    //Controlla se la cella clonecards è su una cella non vuota
    else if((dynamic_cast<CloneCards*>(temp) || (dynamic_cast<Obstruction*>(temp) && dynamic_cast<Obstruction*>(temp)->getType() == ObstructionType::crollo))
            && (_boardStuff[_nBoard] != nullptr && _boardStuff[_nBoard]->get() != nullptr)){

        qDebug() << "Qui entra se clone o crollo";

        if(dynamic_cast<CloneCards*>(temp)){
            _handStuff[_nMano]->~unique_ptr();
            _handStuff[_nMano] = new unique_ptr<Card>(_boardStuff[_nBoard]->get()->clone());
            emit CambiaPosizioneManoBoard(_nMano,0,getImage(_nMano, _handStuff),"",1);
        }
        //la carta utilizzata è un crollo
        else{
            _boardStuff[_nBoard]->~unique_ptr();
            _handStuff[_nMano] = new unique_ptr<Card>(estrattoreCasuale());
            emit CambiaPosizioneManoBoard(_nMano,_nBoard,getImage(_nMano, _handStuff),"",2);
        }
    }

    //Errori
    else{
        qDebug() << "Qui entra se mossa non valida";
        if(_nBoard == nCaselle-(nCaselle/10-2) && (dynamic_cast<Blocco*>(temp) && dynamic_cast<Blocco*>(temp)->getType() == ObstructionType::blocco)){
               qDebug()<<"Modelboard: errore";
               emit changeCardsfailed("Non è possibile posizionare un blocco nella cella di partenza!");
        }
        else if((dynamic_cast<Tunnel*>(temp) || (dynamic_cast<Obstruction*>(temp) && dynamic_cast<Obstruction*>(temp)->getType() == ObstructionType::blocco))){
            emit changeCardsfailed("Posizione board non valida. Non è possibile posizionare una carta Percorso in una casella occupata");
        }

        else if(dynamic_cast<CloneCards*>(temp)){
            emit changeCardsfailed("Posizione board non valida. Non è possibile clonare una casella vuota");
        }
        else
            emit changeCardsfailed("Posizione board non valida. Non è possibile demolire una casella vuota");
    }
}

double ModelBoard::controlloAmmissibilita(nat posizione) const{
    //per ciascun tipo di carta controllo se è ammesso l'inserimento in posizione
    if(checkAround(posizione,new Tunnel(true,true,true,true)) ||
       checkAround(posizione, new Tunnel(false,true,false,true)) ||
       checkAround(posizione, new Tunnel(true,false,true,false)) ||
       checkAround(posizione, new Tunnel(false,true,true,false)) ||
       checkAround(posizione, new Tunnel(false,false,true,true)) ||
       checkAround(posizione,new Tunnel(true,true,false,true)) ||
       checkAround(posizione,new Tunnel(true,false,true,true)) ||
       checkAround(posizione,new Tunnel(true,false,false,true)) ||
       checkAround(posizione,new Tunnel(true,true,false,false)) ||
       checkAround(posizione,new Tunnel(true,true,true,false)) ||
       checkAround(posizione,new Tunnel(false,true,true,true))){
       return true;
    }
    else
        return false;
}


void ModelBoard::posizionaAI() {
    nat size=0;
    for(nat it=0; it<nCaselle;it++){
        if(!(_boardStuff[it] != nullptr && (_boardStuff[it])->get() != nullptr)){
            size++;
        }
    }

    //Qui metto un rand, ma è da rivedere da dove si PARTE a fare algo di conseguenza
    nat generator=0;
    bool win=false;
    bool ok=false;
    bool ammissibile=false;//non si può posizionare carta in alcuna posizione disponibile

    QVector<nat> posizioni, controllate;
    path(nCaselle-((nCaselle/10)/2+1),posizioni,controllate,nCaselle-((nCaselle/10)/2+1));

    //controllo se esiste almeno una carta ammissibile per ogni posizione
    for(int n=0; n< posizioni.size() && !ammissibile ;n++)
        if(!ammissibile && (controlloAmmissibilita(posizioni[n])))
            ammissibile=true;


    while(ammissibile && (!posizioni.empty()) && size>0 && !ok && !win){
        generator = posizioni[rand() % posizioni.size()];
        qDebug()<<"posizioni.size()= "<<posizioni.size()<<" generator: "<<generator;
        if(_boardStuff[generator]->get() == nullptr){
            Card* temp = estrattoreCasuale(4);
            if(checkAround(generator,temp)){
                qDebug() << "lllllllllllll";
                qDebug() << generator;
                qDebug() << "lllllllllllll";
                if(generator==1 || generator == nCaselle/10-2)
                    win = true;
                _boardStuff[generator] = new unique_ptr<Card>(temp);
                ok = true;
            }
        }
    }

    if (win){
        qDebug()<<"L'AI ha trovato il tesoro!";
        emit userWin("AI");
        emit cambiaCellaBoardAI(generator,QString("gold"));//qui mettere cella con pepita
        return;
    }

    //ora diciamo alla view la posizione e immagine
    if(ammissibile && ok)
        emit cambiaCellaBoardAI(generator,getImage(generator,_boardStuff));
    else{    //segnale vittoria giocatore
        emit userWin("Nome");
        qDebug()<<"L'AI non può mettere carte, hai vinto";
        return;
    }

    posizioni.clear();
    controllate.clear();

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    path(nCaselle-((nCaselle/10)/2+1),posizioni,controllate,nCaselle-((nCaselle/10)/2+1));
    qDebug()<<"//////////////////////";
    for(auto i= posizioni.begin(); i<posizioni.end();++i){
       qDebug()<<*i;
    }
    qDebug()<<"/////////////////////////////";
    //Dopo averla messa il player ne mette un'altra
    ammissibile = false;
    ok = false;

    //controllo se esiste almeno una carta ammissibile per almeno una posizione
    for(int n=0;  n< posizioni.size() && !ammissibile ;++n){
            qDebug() << "entra";
        if(!ammissibile && (controlloAmmissibilita(posizioni[n])))//data posizione prova le celle per vedere se la carta si puo mettere
            qDebug() << "ammissibile Vero";
            ammissibile=true;
    }

    //Si vede se l'user puo mettere UNA carta
    for(auto i=posizioni.begin();i<posizioni.end() && ammissibile && !ok;++i){
            qDebug() << "entra2";
            /*
             * mancava il controllo ((*x)->get()) perché handstuff.end() considera tutte le celle della mano in
             * cui esiste un unique_ptr, non quelle in cui esiste la carta.
             * Siccome il vettore inizializza da 0 quando si fa il push_back delle carte si ridimensiona:
             * 1) 0 elementi
             * 2) 1 elemento
             * 3) 2 elementi
             * 4) 4 elementi
             * 5) 8 elementi -> le carte nella mano sono 7 quindi facendo il get() sull'8a da seg.fault
             *
            */
        for(auto x=_handStuff.begin(); !ok && (x!=_handStuff.end()) && ((*x)->get());++x){ //Vede tutta la mano
            qDebug()<<"La size di boardstuff è: "<<size;
            qDebug()<<"print card: "<<QString::fromStdString((*x)->get()->getName());
            if(dynamic_cast<CloneCards*>((*x)->get()) || dynamic_cast<Crollo*>((*x)->get()))
            {qDebug() << "Boh eeeee"<<*i;}
            else if(checkAround(*i,(*x)->get())){//controlliamo se possiamo mettere la carta (*x)->get()
                ok = true;
                qDebug() << "potrebbe essere" <<*i;
            }
            //altrimenti significa che la carta presa in considerazione non va bene -> continua a cercare
        }
    }

    //ora diciamo alla view la posizione e immagine
    if((ammissibile && !ok) || !ammissibile){
        emit userWin("AI");
        qDebug()<<"Non puoi piu metter carte, l'AI ha vinto";
        return;
        posizioni.clear();
        controllate.clear();
    }

    posizioni.clear();
    controllate.clear();



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
        QErrorMessage* err= new QErrorMessage();
        err->showMessage("Impossibile salvare la partita");
    } else {
        // Pulisci il contenuto precedente (Se esiste)
        file.resize(0);

        // Usiamo un valore Json per scrivere nel file
        QJsonArray jsonArray;

        QJsonObject jsonObject;
        for(nat n=0;n<nCaselle;n++){
            qDebug() << "nBoard stampata" << _nBoard << "Tipo di carta" << getImage(n, _boardStuff);
            jsonObject.insert(QString::number(n),(((n == 1  || n == (nCaselle/10-2)) && _boardStuff[n]->get()!= nullptr)? QString("gold"): QString(getImage(n, _boardStuff)) ));
        }
        jsonArray.append(jsonObject);

        QJsonDocument jsonDoc;
        jsonDoc.setArray(jsonArray);
        file.write(jsonDoc.toJson());
        file.close();
    }
}

}
