#include "Model\Header\modelBoard.h"


model::ModelBoard::ModelBoard(vector <unique_ptr<Card>*> boardStuff,
                       vector <unique_ptr<Card>*> handStuff,
                       int nMano):
                       _boardStuff(boardStuff), _handStuff(handStuff),
                                   _nMano(nMano){

}

Card* model::ModelBoard::getCard(unsigned int pos) const{
    return _boardStuff[pos]->get();
}
