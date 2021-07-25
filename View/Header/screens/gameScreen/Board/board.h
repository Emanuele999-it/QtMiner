#ifndef BOARD
#define BOARD

#include <QGraphicsItem>
#include <vector>

#include "Model/Header/modelBoard.h"
#include "View\Header\screens\gameScreen\Board\casella.h"

using std::vector;

namespace view {

class Board : public QObject{
    Q_OBJECT
    //Q_INTERFACE(QGraphicsItem);

private:
    /**
     * @brief dimensione è al grandezza della board, si costruisce con QSize(Width,Height)
     */
    vector<Casella*> vettoreCaselle;

    nat posizione;


public:
    Board(const unsigned int&);

public slots:
    /**
     * @brief selectCardBoard: slot che permette di salvare la posizione della carta cliccata
     *                         e la emette al model tramite numCasellaCliccata(nat)
     */
    void selectCardBoard(const Card*);



    signals:

    /**
     * @brief selectCardHand permette di selezionare la carta in mano

    void selectCardHand(const Card*);
    */

    /**
     * @brief hoverCard serve un metodo simile con (QGraphicsScene *a)
     * che fa roba
     */
    void hoverCard(QGraphicsScene *stuff);

    /**
     * @brief numCasellaCliccata: invio segnale a model posizione casella cliccata
     */
    void numCasellaCliccata(nat);

};

/*
class Mano: public Board{
    /*
     * @brief _dimensioneMano è la grandezza della mano

    QSize _dimensioneMano;
public:
    Mano (const QSize &size, model::ModelBoard caselle);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};
*/
}
#endif

