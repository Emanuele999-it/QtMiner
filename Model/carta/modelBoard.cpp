#include "Model/Header/modelBoard.h"

namespace model{

ModelBoard::~ModelBoard(){}

ModelBoard::ModelBoard(const ModelBoard &m): _nMano(m._nMano), nCaselle(m.nCaselle),
    _handStuff(m._handStuff),
    _boardStuff(m._boardStuff){
    Winner="";
}

ModelBoard& ModelBoard::operator=(const ModelBoard& m){
    if(this!=&m){
        _handStuff.~CVector();
        _boardStuff.~CVector();

        _nMano=m._nMano;
        nCaselle=m.nCaselle;

        CVector<unique_ptr<Card>*> _handStuff(m._handStuff) ;
        CVector<unique_ptr<Card>*> _boardStuff(m._boardStuff) ;
        Winner="";
    }
    return *this;
}

ModelBoard::ModelBoard(nat nMano, nat nBoard): _nMano(nMano), nCaselle(nBoard),
    _handStuff(CVector<unique_ptr<Card>*>(0)),
    _boardStuff(CVector<unique_ptr<Card>*>(0)){
    Winner="";
}

void ModelBoard::addCardtoVectors() {

    for (nat i = 0; i< nCaselle; ++i)
        _boardStuff.push_back(new unique_ptr<Card>());

    for (nat i = 0; i< _nMano; ++i){
        _handStuff.push_back(new unique_ptr<Card>(estrattoreCasuale()));
    }
}

QString ModelBoard::getImage(nat i, CVector<unique_ptr<Card> *> v) const {

    if(v[i] == nullptr || v[i]->get_const() == nullptr){
        return "blank";
    }
    else
        return QString::fromStdString(v[i]->get_const()->getName());
}

Card* ModelBoard::getCardMano(nat posizione) const{
    return _handStuff[posizione]->get();
}

Card* ModelBoard::getCardBoard(nat posizione) const{
    return _boardStuff[posizione]->get();
}

void ModelBoard::path(int cartaPrecedente, QVector<nat> &posizioni, QVector<nat> &controllate, int posizioneAttuale) const{
    if((posizioneAttuale < 0) || posizioneAttuale>=nCaselle || ((cartaPrecedente%(nCaselle/10) == 0) && (posizioneAttuale == cartaPrecedente-1)) || ((cartaPrecedente%(nCaselle/10) == (nCaselle/10-1)) && (posizioneAttuale == cartaPrecedente+1))){
        return;
    }

    //Caso Base: la posizione che staimo controllando è vuota
    if(_boardStuff[posizioneAttuale]== nullptr || _boardStuff[posizioneAttuale]->get_const()==nullptr){
        posizioni.push_back(posizioneAttuale);
        return;
    }

    else{
        const Tunnel* t = dynamic_cast<const Tunnel*>(_boardStuff[posizioneAttuale]->get_const()->clone());

        if(t!=nullptr){
            //se la posizione che si sta per controllare è già stata controllata esci
            if(controllate.contains(posizioneAttuale))
                return;

            controllate.push_back(posizioneAttuale);

            //NORD
            if(*(t->getArr())){
                path(posizioneAttuale,posizioni,controllate,posizioneAttuale-(nCaselle/10));
            }

            //EST
            if(*(t->getArr()+1)){
                path(posizioneAttuale,posizioni,controllate,posizioneAttuale+1);
            }

            //SUD
            if(*(t->getArr()+2)){
                path(posizioneAttuale,posizioni,controllate,posizioneAttuale+(nCaselle/10));
            }

            //OVEST
            if(*(t->getArr()+3)){
                path(posizioneAttuale,posizioni,controllate,posizioneAttuale-1);
            }
        }
        //se t non è un tipo tunnel ma blocco non si fa nulla
    }
}

double ModelBoard::checkAround(nat posizione, const Card *carta) const{
    //se la carta è di tipo blocco va bene in qualunque caso
    if(dynamic_cast<const Blocco*>(carta))
        return true;

    //controllo nord
    if((posizione/(nCaselle/10)) != 0){//se true la carta a nord è fuori dalla griglia -> non controllare
        if((_boardStuff[posizione-(nCaselle/10)] != nullptr) && (_boardStuff[posizione-(nCaselle/10)]->get_const() != nullptr)){
            const Tunnel* c= dynamic_cast<const Tunnel*>(_boardStuff[posizione-(nCaselle/10)]->get_const()->clone());
            if(c){
                //controllo a sud della casella sovrastante
                if(((*(c->getArr()+2)) == *(dynamic_cast<const Tunnel*>(carta)->getArr()))){
                }
                else
                    return false;
            }
        }
    }
    //controllo est
    if((posizione+1)%((nCaselle/10)) > (posizione)%((nCaselle/10))){//se false significhe che si è andati a capo della riga -> non controllare
        if(_boardStuff[posizione+1] != nullptr && _boardStuff[posizione+1]->get_const() != nullptr){
            const Tunnel* c= dynamic_cast<const Tunnel*>(_boardStuff[posizione+1]->get_const()->clone());
            if(c){
                if(((*(c->getArr()+3)) == *((dynamic_cast<const Tunnel*>(carta)->getArr())+1))){//controllo l'ovest della casella di destra
                }
                else
                    return false;
            }
        }
    }
    //controllo sud
    if(posizione + (nCaselle/10) < nCaselle){// se >nCaselle significa che si sta uscendo dalla griglia -> non controllare
        if(_boardStuff[posizione+(nCaselle/10)] != nullptr && _boardStuff[posizione+(nCaselle/10)]->get_const() != nullptr){
            const Tunnel* c= dynamic_cast<const Tunnel*>(_boardStuff[posizione+(nCaselle/10)]->get_const()->clone());
            if(c){
                if(((*(c->getArr())) == *((dynamic_cast<const Tunnel*>(carta)->getArr())+2))){//controllo il nord della casella sottostante
                }
                else
                    return false;
            }
        }
    }
    //controllo ovest
    if((posizione-1)%((nCaselle/10)) < (posizione)%((nCaselle/10))){//se false significa che si è andati sulla riga precedente -> non controllare
        if(_boardStuff[posizione-1] != nullptr && _boardStuff[posizione-1]->get_const() != nullptr){
            const Tunnel* c= dynamic_cast<const Tunnel*>(_boardStuff[posizione-1]->get_const()->clone());
            if(c){
                if(((*(c->getArr()+1)) == *((dynamic_cast<const Tunnel*>(carta)->getArr())+3))){//devo controllare l'est della casella di sinistra
                }
                else
                    return false;
            }
        }
    }
    return true;
}

void ModelBoard::posiziona(){
    bool win = false;
    const Card* temp = _handStuff[_nMano]->get_const()->clone();

    if((dynamic_cast<const Tunnel*>(temp) || (dynamic_cast<const Obstruction*>(temp) && (dynamic_cast<const Obstruction*>(temp)->getType() == ObstructionType::blocco))) &&
            (_boardStuff[_nBoard] == nullptr || _boardStuff[_nBoard]->get_const() == nullptr)){

        QVector<nat> posizioni, controllate;

        path(nCaselle-((nCaselle/10)/2+1),posizioni,controllate,nCaselle-((nCaselle/10)/2+1));


        if((_nBoard == nCaselle-(nCaselle/10-2) && (dynamic_cast<const Obstruction*>(temp))? dynamic_cast<const Obstruction*>(temp)->getType() == ObstructionType::blocco : false)){
            emit changeCardsfailed("Non si puo mettere un blocco allo start!");
        }
        //se è la root si mette (se non gia occupata) || é una cella detro posizioni valide
        else if(posizioni.contains(_nBoard) && checkAround(_nBoard,temp)){
            _boardStuff[_nBoard] = new unique_ptr<Card>(const_cast<Card*>(temp));

            _handStuff[_nMano]->~unique_ptr();
            _handStuff[_nMano] = new unique_ptr<Card>(estrattoreCasuale());

            posizioni.clear();
            controllate.clear();

            if(_nBoard ==1 || _nBoard == nCaselle/10-2){
                //mettere carta con pepita e interompere il gioco
                win == true;
                emit CambiaPosizioneManoBoard(_nMano, _nBoard,
                                              getImage(_nMano, _handStuff),
                                          "gold",0);
                Winner="Winner"+nome;
                emit userWin(Winner);

                return;
            }
            else{
                emit CambiaPosizioneManoBoard(_nMano, _nBoard,
                                              getImage(_nMano, _handStuff),
                                          getImage(_nBoard, _boardStuff),0);
            }
        }
        else{
            emit changeCardsfailed("Non è possibile posizionare una carta Percorso non collegata a quelle adiacenti");
        }

    }
    else if((dynamic_cast<const CloneCards*>(temp) || (dynamic_cast<const Obstruction*>(temp) && dynamic_cast<const Obstruction*>(temp)->getType() == ObstructionType::crollo))
            && (_boardStuff[_nBoard] != nullptr && _boardStuff[_nBoard]->get_const() != nullptr)){

        if(dynamic_cast<const CloneCards*>(temp)){
            _handStuff[_nMano]->~unique_ptr();
            _handStuff[_nMano] = new unique_ptr<Card>(_boardStuff[_nBoard]->get_const()->clone());
            emit CambiaPosizioneManoBoard(_nMano,0,getImage(_nMano, _handStuff),"",1);
        }
        else{
            _boardStuff[_nBoard]->~unique_ptr();
            _handStuff[_nMano] = new unique_ptr<Card>(estrattoreCasuale());
            emit CambiaPosizioneManoBoard(_nMano,_nBoard,getImage(_nMano, _handStuff),"",2);
        }
    }

    //Errori
    else{
        if(_nBoard == nCaselle-(nCaselle/10-2) && (dynamic_cast<const Blocco*>(temp))){
               emit changeCardsfailed("Non è possibile posizionare un blocco nella cella di partenza!");
        }
        else if((dynamic_cast<const Tunnel*>(temp) || (dynamic_cast<const Obstruction*>(temp) && dynamic_cast<const Obstruction*>(temp)->getType() == ObstructionType::blocco))){
            emit changeCardsfailed("Non è possibile posizionare una carta Percorso o Blocco in una casella occupata");
        }

        else if(dynamic_cast<const CloneCards*>(temp)){
            emit changeCardsfailed("Non è possibile clonare una casella vuota");
        }
        else
            emit changeCardsfailed("Non è possibile demolire una casella vuota");
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
    if(Winner==""){
        nat size=0;
        for(nat it=0; it<nCaselle;it++){
            if(!(_boardStuff[it] != nullptr && (_boardStuff[it])->get_const() != nullptr)){
                size++;
            }
        }

        nat generator=0;
        bool win=false;
        bool ok=false;
        bool ammissibile=false;

        QVector<nat> posizioni, controllate;
        path(nCaselle-((nCaselle/10)/2+1),posizioni,controllate,nCaselle-((nCaselle/10)/2+1));

        //controllo se esiste almeno una carta ammissibile per ogni posizione
        for(int n=0; n< posizioni.size() && !ammissibile ;n++)
            if(!ammissibile && (controlloAmmissibilita(posizioni[n])))
                ammissibile=true;

        while(ammissibile && (!posizioni.empty()) && size>0 && !ok && !win){
            generator = posizioni[rand() % posizioni.size()];
            if(_boardStuff[generator]->get_const() == nullptr){
                Card* temp = estrattoreCasuale(4);
                if(checkAround(generator,temp)){
                    if(generator==1 || generator == nCaselle/10-2)
                        win = true;
                    _boardStuff[generator] = new unique_ptr<Card>(temp);
                    ok = true;
                }
            }
        }

        if (win){
            Winner="CPU";
            emit cambiaCellaBoardAI(generator,QString("gold"));
            emit userWin(Winner);
            return;
        }

        if(ammissibile && ok)
            emit cambiaCellaBoardAI(generator,getImage(generator,_boardStuff));
        else{
            Winner="Winner"+nome;
            emit userWin(Winner);
            return;
        }

        posizioni.clear();
        controllate.clear();

        //controllo se il giocatore può posizionare almeno una carta dopo la mossa della CPU

        path(nCaselle-((nCaselle/10)/2+1),posizioni,controllate,nCaselle-((nCaselle/10)/2+1));
        ammissibile = false;
        ok = false;

        //controllo se esiste almeno una carta ammissibile per almeno una posizione
        for(int n=0;  n< posizioni.size() && !ammissibile ;++n){
            if(!ammissibile && (controlloAmmissibilita(posizioni[n])))
                ammissibile=true;
        }

        //Si vede se l'user puo mettere una carta
        for(auto i=posizioni.begin();i<posizioni.end() && ammissibile && !ok;++i){
            for(auto x=_handStuff.begin(); !ok && (x!=_handStuff.end()) && ((*x)->get_const());++x){
                if(dynamic_cast<const CloneCards*>((*x)->get_const()) || dynamic_cast<const Crollo*>((*x)->get_const())){}
                else if(checkAround(*i,(*x)->get_const())){
                    ok = true;
                }
            }
        }

        //ora diciamo alla view la posizione e immagine
        if((ammissibile && !ok) || !ammissibile){
            Winner="CPU";
            posizioni.clear();
            controllate.clear();
            emit userWin(Winner);
            return;
        }

        posizioni.clear();
        controllate.clear();
}


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
    QFile file("lastgameboard.json");
    if(!file.open(QIODevice::WriteOnly)) {
        QErrorMessage* err= new QErrorMessage();
        err->showMessage("Impossibile salvare la partita");
    }
    else {
        file.resize(0);
        QJsonArray jsonArray;

        QJsonObject jsonObject;
        for(nat n=0;n<nCaselle;n++){
            jsonObject.insert(QString::number(n),(((n == 1  || n == (nCaselle/10-2)) && _boardStuff[n]->get_const()!= nullptr)? QString("gold"): QString(getImage(n, _boardStuff)) ));
        }
        jsonObject.insert(QString::number(-1),Winner);
        jsonArray.append(jsonObject);
        QJsonDocument jsonDoc;
        jsonDoc.setArray(jsonArray);
        file.write(jsonDoc.toJson());
        file.close();
    }
}

void ModelBoard::saveName(QString n){
    nome=n;
}

}
