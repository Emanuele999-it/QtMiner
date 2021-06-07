#include "View\Header\screens\gameScreen\mano.h"

#include <QGraphicsScene>

using std::vector;

namespace view {
Mano::Mano(vector <unique_ptr<Card>*> mano) : _mano(mano){};

}
