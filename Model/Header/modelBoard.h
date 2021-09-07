#ifndef MODEL_BOARD_H_
#define MODEL_BOARD_H_
#include "Entities/Header/cvector.h"
#include "Entities/Header/unique_ptr.h"
#include "Model/Header/carta/card.h"
#include "Model/Header/carta/blocco.h"
#include "Model/Header/carta/crollo.h"
#include "Model/Header/carta/obstruction.h"
#include "Model/Header/carta/tunnel.h"

#include "Model/Header/carta/clonecards.h"
#include <QMessageBox>
#include <cstdlib>
#include <QVector>
#include <QErrorMessage>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

#include <QCloseEvent>

namespace model {

class ModelBoard : public QObject{
    Q_OBJECT

private:
    nat _nBoard; // posizione Board
    nat _nMano; // posizione della carta toccata dalla mano
    nat nCaselle;//numero caselle board
    nat _nMosse; //numero mosse eseguite
    CVector <unique_ptr<Card>*> _handStuff ;
    CVector <unique_ptr<Card>*> _boardStuff ;
    QString nome;
    QString Winner;

    /**
     * @brief estrattoreCasuale: estrae in maniera casuale una carta
     * @return: oggetto carta
     */
    Card* estrattoreCasuale(int i=1);

    /**
    * @brief getImage data posizione ritorna QString file immagine
    * @param i
    * @return
    */
    QString getImage(nat i, CVector<unique_ptr<Card>*> v) const;

    /**
     * @brief path calcola se il path è corretto
     * @param pos essenzialmente _nBoard
     * @return
     */
    void path(int CartaPrecedente, QVector <nat> &posizioni, QVector <nat> &controllate, int posizioneCorrente) const;

    /**
     * @brief checkAround: funzione che permette di controllare se la carta scelta per essere posizionata in una determinata
     *                     posizione disponibile rispetta il percorso non andando a collegarsi a carte non collegabili
     */
    double checkAround(nat posizione, const Card* carta) const ;


    /**
     * @brief controlloAmmissibilita: funzione che permette di dire se esiste almeno una carta compatibile con una posizione data
     * @param posizione
     * @return
     */
    double controlloAmmissibilita(nat posizione) const ;


public:
   /**
    * costruttore
    */
    ModelBoard(nat nMano,nat nBoard);

    /**
     * costruttore di copia
     */
    ModelBoard(const ModelBoard& m);

    /**
     * operatore di assegnazione
     */
    ModelBoard& operator=(const ModelBoard& b);

    /**
     * distruttore
     */
    ~ModelBoard() override;

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
     * @brief getMosse questo ci serve per le mosse
     * @return
     */
    nat getMosse()const;

public slots:
    /**
     * @brief evidenziaCartaBoard: slot per modificare quale cella è selezionata nella board
     */
    void evidenziaCellaBoard(nat x, nat y);

    /**
     * @brief getHandImage: serve per ottenere l'immagine della carta nella mano
     * @param pos: di posizione pos
     * @return : parte del nome dell'immagine
     */
    void getHandImage(nat pos);

    /**
     * @brief posiziona la facciamo attivare OGNI VOLTA che si tocca la board pero' controlla se ha salvato una
     * posizioneMano
     */
    void posiziona();

    /**
     * @brief scartaCartaMano: slot che permette di scarte una carta dalla mano per ottenerne una
     *                         nuova estratta casualmente
     */
    void scartaCartaMano();

    /**
     * @brief posizionaAI posiziona la carta della ia (random) e la mette dove puo'
     */
    void posizionaAI();

    /**
     * @brief saveLastGame: salvatiaggio untima partita
     */
    void saveLastGame();

    /**
     * @brief saveName: slot per salvare il nome del giocatore
     */
    void saveName(QString);


signals:

    /**
     * @brief CambiaPosizioneManoBoard: segnale per aggoirnare view
     *              il primo puntatore serve per mettere la carta nella board
     *              il secondo puntatore serve per mettere una nuova carta nella mano.
     *        l'ultimo parametro che passiamo serve a far capire allo slot ricevente come deve gestire
     *        i dati che gli arrivano
     */
    void CambiaPosizioneManoBoard(nat, nat, QString,QString,nat);


    /**
     * @brief CambiaImmagineMano: segnale che permette di aggiornare l'immagine
     *                  della carta della mano
     */
    void CambiaImmagineMano(nat,QString, nat);

    /**

     * @brief cambiaCellaBoardAI
     */
    void cambiaCellaBoardAI(nat,QString);

    /**
     * @brief changeCardsfailed: emissione segnale scambio carte fallito
     */
    void changeCardsfailed(QString);

    /**
     * @brief userWin quando la IA non ha piu mosse l'user vince, oppure quando l'user non ha piu mosse e l'IA vince
     *        QStrinf: Se vince AI "AI" e se vince nome dato "Nome"
     */
    void userWin(QString);
};

}

#endif //end ModelBoard
