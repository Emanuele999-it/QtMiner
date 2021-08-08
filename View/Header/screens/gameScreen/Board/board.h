#ifndef BOARD
#define BOARD

#include <QGraphicsItem>
#include <vector>

#include "Model/Header/modelBoard.h"
#include "View/Header/screens/gameScreen/Board/casella.h"

#include <QVector>

namespace view {

class Board : public QObject{
    Q_OBJECT

private:
    /**
     * @brief posizione: cella selezionata
     */
    nat posizioneBoard;

public:
    Board(const nat&);

    /**
     * @brief dimensione è al grandezza della board, si costruisce con QSize(Width,Height)
     */
    QVector<Casella*> vettoreCaselleBoard;

    /**
     * @brief getCasella: funzione che restituisce la casella in una determinata posizione
     */
    Casella* getCasella(nat);

public slots:
    /**
     * @brief selectCardBoard: slot che permette di salvare la posizione della carta cliccata
     *                         e la emette al model tramite numCasellaCliccata(nat)
     */
    void selectCardBoard(nat);

    /**
     * @brief addCard: slot che permette di aggiornare la vista (board) con la carta posizionata
     *                 dalla mano
     */
    void addCardBoard(nat, QString);



signals:
    /**
     * @brief numCasellaCliccata: invio segnale a model posizione casella cliccata
     */
    void numCasellaCliccataBoard(nat);


};


class Mano: public QObject{
    Q_OBJECT
private:


    /**
     * @brief posizione: cella selezionata
     */
    nat posizioneMano;

public:
    Mano(const nat&);

    /**
     * @brief getCasella: funzione che restituisce la casella in una determinata posizione
     */
    Casella* getCasella(nat);

    /**
     * @brief dimensione è al grandezza della board, si costruisce con QSize(Width,Height)
     */
    QVector<Casella*> vettoreCaselleMano;

public slots:
    /**
     * @brief selectCardMano: slot che permette di salvare la posizione della carta cliccata
     *                         e la emette al model
     */
    void selectCardMano(nat);

    /**
     * @brief addCardMano: permette di aggiornare la vista (mano) andando ad inserire la nuova
     *                     carta al posto della vecchia
     */
    void addCardMano(nat, QString);

signals:
    /**
     * @brief numCasellaCliccata: invio segnale a model posizione casella cliccata
     */
    void numCasellaCliccataMano(nat);

    /**
     * @brief cheImmagineHo: segnale per chiedere al model il tipo di carta
     */
    //void cheImmagineHo(nat);
};

}
#endif

