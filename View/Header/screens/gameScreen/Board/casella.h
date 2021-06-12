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
    int _position;
    qreal _size;
    bool _selected;

    void updateCursor();

protected:
    void mouseClick(QGraphicsSceneMouseEvent *event);
    void mouseHover(QGraphicsSceneMouseEvent *event);
    void mouseNonHover(QGraphicsSceneMouseEvent *event);

public:
    Casella(QPushButton*pushbutton=nullptr);

    /**
     * @brief rect:resize
     * @return
     */
    void rect(int , int ) const {};

    bool returnSelected() const;
    void cambiaSelected(bool s);

    Card* returnTipo() const;

    int returnPosizione();

signals:
    void click(Casella *casella);
    void mouseHover();
    void mouseNonHover();
};

}
#endif

