#ifndef BOARDWINDOW_H
#define BOARDWINDOW_H

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMainWindow>
#include <QLabel>
#include <QLCDNumber>
#include "View/Header/screens/gameScreen/Board/board.h"

class BoardWindow : public QWidget{
    Q_OBJECT
public:
    BoardWindow(QWidget *parent = nullptr, nat num=7);

private:
    QLabel *label(const QString &text);
    view::Board *b;
    view::Mano *m;
    QLCDNumber *mosse;
    nat celle;

public:
    void aggiornamentoView(nat posMano, nat PosBoard, Card* CartaBoard, Card* CartaMano);

signals:
    /**
     * @brief rimbalzoSegnaleCasellaSelezionataBoard: prende il segnale casellaCliccataBoard e lo
     *                  passa alla classe gerarchicamente superiore
     */
    void rimbalzoSegnaleCasellaSelezionataBoard(nat);

    /**
     * @brief rimbalzoSegnaleCasellaSelezionataMano: stessa cosa del precedente
     */
    void rimbalzoSegnaleCasellaSelezionataMano(nat);


};

#endif // BOARDWINDOW_H
