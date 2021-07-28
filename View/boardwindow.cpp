#include "View/Header/boardwindow.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QWidget>
#include <QLCDNumber>
#include "View/Header/screens/gameScreen/Board/board.h"


BoardWindow:: BoardWindow(QWidget *p, nat num) : QWidget(p), celle(num)
{

    b = new view::Board(celle);
    m = new view::Mano(7);
    connect(b, &view::Board::numCasellaCliccataBoard, this, &BoardWindow::rimbalzoSegnaleCasellaSelezionataBoard);
    connect(m, &view::Mano::numCasellaCliccataMano, this, &BoardWindow::rimbalzoSegnaleCasellaSelezionataMano);

    mosse = new QLCDNumber(3);
    mosse->setSegmentStyle(QLCDNumber::Filled);

    QGridLayout *layout = new QGridLayout;
    //layout->addWidget(End, 4, 0);
    //layout->addWidget(b, 0, 1, 6, 1); //la cosa che voglio io, la board
    setLayout(layout);

    setWindowTitle(tr("Qtminer"));
    resize(1280, 720);

}

void BoardWindow::visualizza(){

}

