#ifndef MODEL_BOARD_H_
#define MODEL_BOARD_H_
#include "Entities/Header/cvector.h"
#include "Entities/Header/unique_ptr.h"
#include "Model\Header\carta\card.h"

using std::vector;

namespace model {

class ModelBoard {
private:
    vector <unique_ptr<Card>*> _boardStuff;
    vector <unique_ptr<Card>*> _handStuff;
    int _nMano;
public:
        ModelBoard(
            vector <unique_ptr<Card>*> boardStuff,
            vector <unique_ptr<Card>*> handStuff,
            int nMano=0);

  /**
 * @brief getCard data la posizione restituisce la carta a scopo di informazioni
 * @param posizione
 * @return
 */
Card* getCard(unsigned int pos)const;

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

#endif //end ModelBoard
