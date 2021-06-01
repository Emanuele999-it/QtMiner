#ifndef CASELLA_H_
#define CASELLA_H_

#include <QGraphicsItem>
#include "Entities/Header/unique_ptr.h"
#include "Entities/Header/cvector.h"
#include "Model/Header/carta/card.h"

namespace view {

enum class TipoCasella {
Incrocio,

};

class Casella : public QObject, public QGraphicsItem {
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

private:
    tip
}

}
#endif

