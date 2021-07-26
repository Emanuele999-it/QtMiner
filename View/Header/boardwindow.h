#ifndef BOARDWINDOW_H
#define BOARDWINDOW_H

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMainWindow>
#include <QLabel>
#include <QLCDNumber>
#include "View/Header/screens/gameScreen/gameScene.h"

class BoardWindow : public QWidget{

public:
    BoardWindow(QWidget *parent = nullptr, nat num=7);

private:
    QLabel *label(const QString &text);
    view::Board *b;
    QLCDNumber *mosse;
    nat celle;

public:
    void visualizza();
};

#endif // BOARDWINDOW_H
