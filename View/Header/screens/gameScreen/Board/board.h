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
    QVector<Casella*> vettoreCaselle;


    /**
     * @brief posizione: cella selezionata
     */
    nat posizione;


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

