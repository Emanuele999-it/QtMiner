#ifndef MODEL_BOARD_H_
#define MODEL_BOARD_H_
#include "Entities/Header/cvector.h"
#include "Entities/Header/unique_ptr.h"
#include "Model\Header\carta\card.h"

using std::vector;

namespace model {

class ModelBoard : public QObject{
    Q_OBJECT

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
    QString getImage(nat i, CVector<unique_ptr<Card>*> v) const;

    /**
     * @brief getCardBoard data la posizione restituisce la carta a scopo di informazioni
     * @param posizione
     * @return
     */
   Card* getCardBoard(nat posizione) const;

    /**
     * @brief getCardHand data posizione torna la carta
     * @param posizione
     * @return
     */
    Card* getCardMano(nat posizione) const;

    /**
     * @brief posiziona la facciamo attivare OGNI VOLTA che si tocca la board pero' controlla se ha salvato una
     * posizioneMano
     * @param posizioneMano
     * @param posizioneBoard
     * @return
     */
    void posiziona(nat posizioneMano,nat posizioneBoard);


public slots:
    /**
     * @brief evidenziaCartaBoard: slot per modificare quale cella è selezionata nella board
     */
    void evidenziaCellaBoard(nat p);

    /**
     * @brief evidenziaCellaMano: slot per modificare cella selezionata nella mano
     */
    void evidenziaCellaMano(nat p);

signals:
    /**
     * @brief CambiaPosizioneManoBoard: segnale per aggoirnare view
     *              il primo puntatore serve per mettere la carta nella board
     *              il secondo puntatore serve per mettere una nuova carta nella mano
     */
    void CambiaPosizioneManoBoard(nat, nat, QString,QString);

};

}

#endif //end ModelBoard
