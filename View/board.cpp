#include "View/Header/board.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QWidget>

Board::Board(QWidget *p): QFrame(p), Partita(false), Pausa(false)// da mettere sullo heap
{
    setFrameStyle(QFrame::Panel | QFrame::Sunken);
    setFocusPolicy(Qt::StrongFocus);
}
