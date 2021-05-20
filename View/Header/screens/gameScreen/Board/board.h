#ifndef BOARD
#define BOARD

#include <QGraphicsItem>
#include <vector>

#include "Entities/Header/unique_ptr.h"
#include "Entities/Header/cvector.h"
#include "Model/Header/carta/card.h"
#include "Model/Header/carta/blocco.h"

using std::vector;

namespace view {

class Board : public QGraphicsItem, public QObject{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

private:
    QSize size; //Grandezza Board
    //Ok ora mi serve un vettore per ricordare dove sono le cose
    vector <unique_ptr<Card>*> baseVector;
    //Sperimentiamo con dei blocchi
    vector <unique_ptr<Blocco>*> blocchi;
    //Ci teniamo una carta in memoria quando la selezioniamo
    Card* selezione;

    void createBoard();

public:
    Board (const QSize &size, const vector <unique_ptr<Card>*> &baseVector, const vector <unique_ptr<Blocco>*> &blocco);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void turn();
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

}
#endif

