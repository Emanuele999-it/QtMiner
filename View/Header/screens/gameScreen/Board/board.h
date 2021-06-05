#ifndef BOARD
#define BOARD

#include <QGraphicsItem>
#include <vector>

#include "Entities/Header/unique_ptr.h"
#include "Entities/Header/cvector.h"
#include "Model/Header/carta/card.h"
#include "Model/Header/carta/blocco.h"
#include "Model/Header/carta/tunnel.h"
#include "View\Header\screens\gameScreen\Board\casella.h"
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
    //Ok ora mi serve un vettore per ricordare dove sono le cose
    vector <Casella*> _caselle;

public:
    Board (const QSize &size, vector <Casella*> caselle);
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    //void turn();

public slots:

    signals:
    /**
     * @brief selectCard quando targetti una carta te la salva in memoria
     * se non c'è nessuna carta selezionata, copia la carta dalla memoria allo spazio
     * se non c'e nessuna carta ne in memoria ne in memoria non fa nulla
     */
    void selectCard(const Card*);
    void addCard(const Card*,int posizione = 0);
    /**
     * @brief hoverCard quando heveri si mostra i path possibili
     */

    /**
     * @brief hoverCard serve un metodo simile con (QGraphicsScene *a)
     * che fa roba
     */
    void hoverCard(QGraphicsScene *stuff);
};

class Mano :  public QGraphicsItem, public QObject {

};
}
#endif

