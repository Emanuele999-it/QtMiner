#ifndef MANO
#define MANO

#include <QGraphicsItem>
#include <vector>

#include "Entities/Header/unique_ptr.h"
#include "Entities/Header/cvector.h"
#include "Model/Header/carta/card.h"
#include "Model/Header/carta/blocco.h"

using std::vector;

namespace view {

class Mano : public QObject, public QGraphicsItem {
  Q_OBJECT
  Q_INTERFACES(QGraphicsItem)

private:
    vector <unique_ptr<Card>*> mano;

public:
    void paint(QPainter *p, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:
    /**
     * @brief grab un metodo per prendere la [n] carta
     * @param mano
     */
    void grab(const vector <unique_ptr<Card>*> &mano);
    /**
     * @brief addCard aggiungere una carta specifica, scopo di debugging
     * @param mano
     */
    void addCard(const vector <unique_ptr<Card>*> &mano);
};
}

#endif
