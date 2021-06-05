#ifndef MODEL_BOARD_H_
#define MODEL_BOARD_H_

#include "Entities/Header/cvector.h"
#include "Entities/Header/unique_ptr.h"
#include "Model\Header\carta\card.h"

namespace model {

class ModelBoard {
private:
    CVector <unique_ptr<Card>*> _boardStuff(unsigned int b);
    CVector <unique_ptr<Card>*> _handStuff(unsigned int h);
    int nMano;
public:
        ModelBoard(
            CVector <unique_ptr<Card>*> boardStuff(unsigned int b),
            CVector <unique_ptr<Card>*> handStuff(unsigned int h),
            int nMano
                );

  /**
 * @brief getCard data la posizione restituisce la carta a scopo di informazioni
 * @param posizione
 * @return
 */
Card* getCard(unsigned int posizione)const;

/**
 * @brief posiziona la facciamo attivare OGNI VOLTA che si tocca la board pero' controlla se ha salvato una
 * posizioneMano
 * @param posizioneMano
 * @param posizioneBoard
 * @return
 */
Card* posiziona(unsigned int posizioneMano,unsigned int posizioneBoard);
};
}

#endif
