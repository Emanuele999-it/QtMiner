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

    //test
    QPushButton *p;
    QVector<QWidget*> q;
    view::Casella* c;

public slots:
    /**
     * @brief aggiornamentoView: aggiornamento view in seguito al posizionamento di una carta
     * @param posMano
     * @param PosBoard
     * @param CartaBoard    nome immagine da inserire nella board in pos. PosBoard
     * @param CartaMano     nome immagine da inserire nella mano in pos. CartaMano
     */
    void aggiornamentoView(nat posMano, nat PosBoard, QString CartaBoard, QString CartaMano);

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
