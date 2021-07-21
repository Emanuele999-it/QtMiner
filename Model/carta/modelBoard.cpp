#include "Model\Header\modelBoard.h"
#include "Model/Header/carta/blocco.h"
#include "Model/Header/carta/crollo.h"
#include "Model/Header/carta/obstruction.h"
#include "Model/Header/carta/tunnel.h"

#include "Model/Header/carta/clonecards.h"

namespace model{
ModelBoard::ModelBoard(CVector <unique_ptr<Card>*> boardStuff,
                       CVector <unique_ptr<Card>*> handStuff,
                       int nMano = -1, int nBoard = -1):
                       _boardStuff(boardStuff), _handStuff(handStuff), _nMano(nMano), _nBoard(nBoard)
{
    //sistemare riempimento automatico
    for (int i = 0; i< 40; i++)
        _boardStuff.push_back(new unique_ptr<Card>);

    for (int i = 0; i< 7; i++)
        _handStuff.push_back(new unique_ptr<Card>);
}

Card* ModelBoard::getCardBoard(unsigned int posizione) const{
    return _boardStuff[posizione].get();
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
            return ":/Img/╬(0).jpg";
        else if(a[0]==false && a[1]==true && a[2]==false && a[3]==true)
            return ":/Img/═(0).jpg";
        else if(a[0]==true && a[1]==false && a[2]==true && a[3]==false)
            return ":/Img/║(0).jpg";
        else if(a[0]==false && a[1]==true && a[2]==true && a[3]==false)
            return ":/Img/╔(2).jpg";
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
    return _handStuff[posizione].get();
}

void ModelBoard::posiziona(unsigned int posizioneMano,unsigned int posizioneBoard){

    unique_ptr<Card>* selezione = new unique_ptr<Card>(
                    _handStuff[posizioneMano].get()->clone());

    _boardStuff[posizioneBoard].~unique_ptr();
    _boardStuff[posizioneBoard] = new unique_ptr<Card>(selezione);

    selezione.~unique_ptr();
}

int ModelBoard::getSelezioneBoard() const{
    return _nBoard;
}

void ModelBoard::cambiaSelezioneBoard(int b){
    _nBoard = b;
}

int ModelBoard::getSelezioneMano() const{
    return _nMano;
}

void ModelBoard::cambiaSelezioneMano(int m){
    _nMano = m;
}

}
