#ifndef BOARDWINDOW_H
#define BOARDWINDOW_H

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMainWindow>
#include <QLabel>
#include <QLCDNumber>
#include "View/Header/screens/gameScreen/Board/board.h"
#include "View/Header/boardwindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QWidget>
#include <QLCDNumber>
#include "View/Header/screens/gameScreen/Board/casella.h"


class BoardWindow : public QWidget{

    Q_OBJECT
public:
    BoardWindow(QWidget *parent = nullptr, nat num=40);

    /**
     * @brief addElVectors: permette di aggiungere gli elementi ai
     *                      vettori
     */
    void addElVectors();

private:
    QLabel *label(const QString &text);
    view::Board *b;
    view::Mano *m;
    QLCDNumber *mosse;
    nat celle;
    QGridLayout *GBLayout;
    //layout mano
    QGridLayout *GMLayout;

    //test
    QPushButton *p;
    QVector<view::Casella*> q;
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

    /**
     * @brief aggiornamentoCartaMano: per modificare le immagini delle carte della mano
     * @param a: posizione carta
     * @param c: porzione di stringa da sostituire
     */
    void aggiornamentoCartaMano(nat a , QString c);

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

    /**
     * @brief cheImmagineHo: segnale per chiedere al model il tipo di carta
     */
    void cheImmagineHo(nat);
};

#endif // BOARDWINDOW_H
