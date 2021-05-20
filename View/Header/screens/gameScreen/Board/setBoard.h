#ifndef SET_BOARD
#define SET_BOARD

#include <QGraphicsItem>
#include <vector>

#include "Entities/Header/unique_ptr.h"
#include "Entities/Header/cvector.h"
#include "Model/Header/carta/card.h"
#include "Model/Header/carta/blocco.h"

using std::vector;

namespace view {

class SetBoard : public QObject , public QGraphicsItem {
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

private:
    QSize _size;
    }

}
#endif

