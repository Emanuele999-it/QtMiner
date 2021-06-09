#include "Model\Header\modelBoard.h"

namespace model{
ModelBoard::ModelBoard(CVector <unique_ptr<Card>*> boardStuff,
                       CVector <unique_ptr<Card>*> handStuff,
                       int nMano):
                       _boardStuff(boardStuff), _handStuff(handStuff), _nMano(nMano)
{
    for (int i = 0; i< 40; i++)
        _boardStuff.push_back(new unique_ptr<Card>);

    for (int i = 0; i< nMano; i++)
        _handStuff.push_back(new unique_ptr <Card>);
};

Card* ModelBoard::getCardBoard(unsigned int posizione) const{
    return _boardStuff[posizione]->get();
};


Card* ModelBoard::getCardMano(unsigned int posizione) const{
    return _handStuff[posizione]->get();
};

void ModelBoard::posiziona(unsigned int posizioneMano,unsigned int posizioneBoard){
    unique_ptr<Card>* selezione;
    selezione = _handStuff[posizioneMano];
    _boardStuff[posizioneBoard]=selezione;
};

int ModelBoard::getSelezioneBoard() const{
    return _nBoard;
};

void ModelBoard::cambiaSelezioneBoard(int b){
    _nBoard = b;
};

int ModelBoard::getSelezioneMano() const{
    return _nMano;
};

void ModelBoard::cambiaSelezioneMano(int m){
    _nMano = m;
};

}
