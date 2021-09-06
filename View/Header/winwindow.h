﻿#ifndef WINWINDOW_H
#define WINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QString>
#include <QTextEdit>
#include <QDialog>
#include <QLabel>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QTextStream>


//#include "View/Header/mainwindow.h"

class WinWindow : public QDialog
{
    Q_OBJECT
private:

    QPushButton *newgame=nullptr;
    QPushButton *checkboard=nullptr;
    QPushButton *menu=nullptr;
    QLabel *text=nullptr;
    QPushButton *image=nullptr;
    QVBoxLayout *Vl = nullptr;

signals:
    /**
     * @brief newgame manda segnale a mainwindow
     */
    void newgamesignal();
    /**
     * @brief NewBoardRequest: mandero' una segnale a mainwindow per una nuova board
     */
    void NewBoardRequest();
public:
    /**
    *costruttore
    */
    WinWindow(QString);

    /**
    * costruttore di copia
    */
    //WinWindow(const Tutorialwindow& t);

    /**
    * operatore di assegnazione
    */
    //WinWindow& operator=(const Tutorialwindow& t);

    /**
    *distruttore
    */
    ~WinWindow() override;


private slots:

    /**
     * @brief NewCheckRequest: mandero' un segnale a boardWindow per il controllo del terreno
     */
    void NewCheckRequest();

    /**
     * @brief NewMenuRequest: si chiude la finestra e si riapre mainWindow
     */
    void NewMenuRequest();

    /**
     * @brief CloseWindow: chiusura finestra
     */
    //void CloseWindow();


};

#endif // TUTORIALWINDOW_H
