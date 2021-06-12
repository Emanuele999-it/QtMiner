#ifndef CASELLA_H_
#define CASELLA_H_

#include <QGraphicsItem>
#include "Entities/Header/unique_ptr.h"
#include "Entities/Header/cvector.h"
#include "Model/Header/carta/card.h"
#include <QPushButton>
using std::vector;

namespace view {


class Casella : public QPushButton {
    Q_OBJECT

private:
    nat pos;
protected:

    void mouseClick(QGraphicsSceneMouseEvent *event);
    void mouseHover(QGraphicsSceneMouseEvent *event);
    void mouseNonHover(QGraphicsSceneMouseEvent *event);

public:
    Casella(nat p=0,QPushButton*pushbutton=nullptr);
    void cambiaImmagine(QString i);

signals:
    void casellaCliccata(nat p);
    //void mouseHover();
    //void mouseNonHover();
};

}
#endif

