#ifndef BOARD
#define BOARD

#include <QGraphicsItem>
#include <vector>

#include "Model/Header/modelBoard.h"

using std::vector;

namespace view {

class Board : public QGraphicsItem, public QObject{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

private:
    /**
     * @brief dimensione è al grandezza della board, si costruisce con QSize(Width,Height)
     */
    QSize _dimensione;

protected:
    /**
     * @brief _caselle è essenzialmente dove sta tutto
     */
    model::ModelBoard _caselle;

public:
    Board (const QSize &size, model::ModelBoard caselle);
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    //void turn();

public slots:

    signals:
    /**
     * @brief possiamo fare che si selezionano due carte, si preme GIOCA e avviene lo scambio
     * le due carte selezionate, una sulla board e una sulla mano e avviene il turno
     */
    void selectCardBoard(const Card*);
    /**
     * @brief hoverCard serve un metodo simile con (QGraphicsScene *a)
     * che fa roba
     */
    void hoverCard(QGraphicsScene *stuff);
};

class Mano: public Board{
    /**
     * @brief _dimensioneMano è la grandezza della mano
     */
    QSize _dimensioneMano;
public:
    Mano (const QSize &size, model::ModelBoard caselle);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

}
#endif

