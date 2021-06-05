#ifndef FINESTRAINIZIALE_H
#define FINESTRAINIZIALE_H

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMainWindow>
#include <QLabel>
#include <QLCDNumber>
#include "View/Header/board.h"

class FinestraIniziale : public QWidget{
public:
    FinestraIniziale(QWidget *parent = nullptr);
private:
    QLabel *label(const QString &text);
    Board *b;
    QLCDNumber *mosse;
public:
    void visualizza();
};

#endif // FINESTRAINIZIALE_H
