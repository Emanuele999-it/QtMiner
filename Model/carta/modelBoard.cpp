#include "Model\Header\modelBoard.h"

namespace model{
ModelBoard::ModelBoard(vector <unique_ptr<Card>*> boardStuff(unsigned int b),
                       vector <unique_ptr<Card>*> handStuff(unsigned int h),
                       int nMano):
                       _boardStuff(boardStuff), _handStuff(handStuff), _nMano(nMano)
{}
}
