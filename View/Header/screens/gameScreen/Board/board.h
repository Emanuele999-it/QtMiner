#ifndef BOARD
#define BOARD

#include <QGraphicsItem>
#include <vector>

#include "Model/Header/modelBoard.h"
#include "View\Header\screens\gameScreen\Board\casella.h"

#include <QVector>

namespace view {

class Board : public QObject{
    Q_OBJECT

private:
    /**
     * @brief dimensione è al grandezza della board, si costruisce con QSize(Width,Height)
     */
    QVector<Casella*> vettoreCaselleBoard;


    /**
     * @brief posizione: cella selezionata
     */
    nat posizioneBoard;

public:
    Board(const nat&);

public slots:
    /**
     * @brief selectCardBoard: slot che permette di salvare la posizione della carta cliccata
     *                         e la emette al model tramite numCasellaCliccata(nat)
     */
    void selectCardBoard(nat);

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
     * @brief dimensione è al grandezza della board, si costruisce con QSize(Width,Height)
     */
    QVector<Casella*> vettoreCaselleMano;

    /**
     * @brief posizione: cella selezionata
     */
    nat posizioneMano;

public:
    Mano(const nat&);

public slots:
    /**
     * @brief selectCardMano: slot che permette di salvare la posizione della carta cliccata
     *                         e la emette al model
     */
    void selectCardMano(nat);

signals:
    /**
     * @brief numCasellaCliccata: invio segnale a model posizione casella cliccata
     */
    void numCasellaCliccataMano(nat);
};

}
#endif

