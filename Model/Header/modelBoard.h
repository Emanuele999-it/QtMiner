#ifndef MODEL_BOARD_H_
#define MODEL_BOARD_H_
#include "Entities/Header/cvector.h"
#include "Entities/Header/unique_ptr.h"
#include "Model\Header\carta\card.h"

using std::vector;

namespace model {

class ModelBoard {

private:
    unsigned int _nMano; // posizione della carta toccata dalla mano
    unsigned int _nBoard; // posizione della carta toccata dalla board
    CVector <unique_ptr<Card>*> _handStuff ;
    CVector <unique_ptr<Card>*> _boardStuff ;


public:
    ModelBoard(nat nMano = 7,nat nBoard = 40);
     /**
     * @brief getImage data posizione ritorna QString file immagine
     * @param i
     * @return
     */
    QString getImage(int i)const;

    /**
     * @brief getCardBoard data la posizione restituisce la carta a scopo di informazioni
     * @param posizione
     * @return
     */
    Card* getCardBoard(unsigned int posizione)const;

    /**
     * @brief getCardHand data posizione torna la carta
     * @param posizione
     * @return
     */
    Card* getCardMano(unsigned int posizione)const;

    /**
     * @brief getSelezioneBoard questa mi serve per vedere che carta ho selezionata sulla Board
     * @return
     */
    int getSelezioneBoard()const;

    /**
     * @brief cambiaSelezioneBoard cambia quale carta è selezionata Board
     * @return
     */
    void cambiaSelezioneBoard(int b);

    /**
     * @brief getSelezioneHand questa mi serve per vedere quale ho selezionato sulla mano
     * @return
     */
    int getSelezioneMano()const;

    /**
     * @brief cambiaSelezioneMano cambia quale carta è selezionata sulla mano
     * @return
     */
    void cambiaSelezioneMano(int m);

    /**
     * @brief posiziona la facciamo attivare OGNI VOLTA che si tocca la board pero' controlla se ha salvato una
     * posizioneMano
     * @param posizioneMano
     * @param posizioneBoard
     * @return
     */
    void posiziona(unsigned int posizioneMano,unsigned int posizioneBoard);
};

}

#endif //end ModelBoard
