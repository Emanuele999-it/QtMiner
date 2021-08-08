#ifndef MODEL_BOARD_H_
#define MODEL_BOARD_H_
#include "Entities/Header/cvector.h"
#include "Entities/Header/unique_ptr.h"
#include "Model/Header/carta/card.h"


namespace model {

class ModelBoard : public QObject{
    Q_OBJECT

private:
    nat _nMano; // posizione della carta toccata dalla mano
    nat _nBoard; // posizione della carta toccata dalla board
    CVector <unique_ptr<Card>*> _handStuff ;
    CVector <unique_ptr<Card>*> _boardStuff ;

    /**
     * @brief estrattoreCasuale: estrae in maniera casuale una carta
     * @return: oggetto carta
     */
    Card* estrattoreCasuale();

    /**
    * @brief getImage data posizione ritorna QString file immagine
    * @param i
    * @return
    */
   QString getImage(nat i, CVector<unique_ptr<Card>*> v) const;



public:
    ModelBoard(nat nMano = 7,nat nBoard = 40);

    /**
     * @brief addCardtoVectors: metodo per inserire gli elementi nei vettori
     */
    void addCardtoVectors();


    /**
     * @brief getCardBoard data la posizione restituisce la carta a scopo di informazioni
     * @param posizione
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

    /**
     * @brief deleteAllCards: funzione che permette di eliminare tutte le carte per
     *                      giocare una nuova partita
     */
    void deleteAllCards();

public slots:
    /**
     * @brief evidenziaCartaBoard: slot per modificare quale cella è selezionata nella board
     */
    void evidenziaCellaBoard(nat p);

    /**
     * @brief evidenziaCellaMano: slot per modificare cella selezionata nella mano
     */
    void evidenziaCellaMano(nat p);

    /**
     * @brief getHandImage: serve per ottenere l'immagine della carta nella mano
     * @param pos: di posizione pos
     * @return : parte del nome dell'immagine
     */
    void getHandImage(nat pos);

signals:
    /**
     * @brief CambiaPosizioneManoBoard: segnale per aggoirnare view
     *              il primo puntatore serve per mettere la carta nella board
     *              il secondo puntatore serve per mettere una nuova carta nella mano
     */
    void CambiaPosizioneManoBoard(nat, nat, QString,QString);


    /**
     * @brief CambiaImmagineMano: segnale che permette di aggiornare l'immagine
     *                  della carta della mano
     */
    void CambiaImmagineMano(nat,QString);



};

}

#endif //end ModelBoard
