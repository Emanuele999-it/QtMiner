#ifndef CASELLA_H_
#define CASELLA_H_

#include <QGraphicsItem>
#include "Entities/Header/unique_ptr.h"
#include "Entities/Header/cvector.h"
#include "Model/Header/carta/card.h"

using std::vector;

namespace view {


class Casella : public QObject, public QGraphicsItem {
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

private:
    int _position;
    qreal _size;
    vector<bool> _tipo {false, false, false, false};
    bool _selected;

    void updateCursor();

protected:
    void mouseClick(QGraphicsSceneMouseEvent *event);
    void mouseHover(QGraphicsSceneMouseEvent *event);
    void mouseNonHover(QGraphicsSceneMouseEvent *event);

public:
    Casella(
            QGraphicsItem *i,
            int position,
            qreal size,
            vector<bool> tipo
    );

    QRectF rect();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    bool returnSelected() const;
    void cambiaSelected(bool s);

    bool returnTipo() const;
    void cambiaTipo(vector<bool> tipo);

    int returnPosizione();

signals:
    void click(Casella *casella);
    void mouseHover();
    void mouseNonHover();
};

}
#endif

