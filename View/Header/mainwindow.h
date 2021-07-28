﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QStackedWidget>
#include <QVBoxLayout>

#include "settingswindow.h"
#include "tutorialwindow.h"
#include "boardwindow.h"

#include <QSize>
#include <QIcon>

class MainWindow: public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief MainWindow: costruttore default
     * @param parent: parent di MainWindow
     */
    MainWindow(QWidget *parent=nullptr);

private:

    QStackedWidget* stackedWidget;


/****************** Settings ************************************/
    /**
     * @brief Settings: bottone impostazioni
     */
    QPushButton* settings;

    /**
     * @brief settWindow: finestra impostazioni
     */
    SettingsWindow *settWindow;

/****************** Tutorial ************************************/
    /**
     * @brief tutorial: bottone finestra tutorial
     */
    QPushButton * tutorial;

    /**
     * @brief tWindow: finestra tutorial
     */
    Tutorialwindow *tWindow;


/****************** Game ************************************/

    /**
     * @brief startGame: bottone inizio gioco
     */
    QPushButton* startGame;

    /**
     * @brief boardWindoW: finestra gioco
     */
    BoardWindow* boardWindoW;


/****************** Last Game ************************************/
    /**
     * @brief lastGame: bottone finestra lastGame
     */
    QPushButton * lastGame;

    //da mettere lastGame

/****************** Layout ************************************/
    /**
     * @brief Vl: layout principale finestra
     */
    QVBoxLayout *Vl;


signals:

    /**
    * @brief Settings: segnale per aprire finestra impostazioni, catturato
    *                      dal controller
    */
    void SettingsRequest();

    /**
     * @brief TutorialRequest: segnale per aprire finestra tutorial,
     *                             catturato dal controller
     */
    void TutorialRequest();

    /**
     * @brief GameRequest: segnale per aprire finestra gioco,
     *                  caturato dal controller
     */
    void GameRequest();



/********** Rimbalzo segnale da casella al controller ****************/
    /**
     * @brief casellaBoardSelezionata: passa il segnale al controller
     */
    void casellaBoardSelezionata(nat);

    /**
     * @brief casellaManoSelezionata: passa il segnale al controller
     */
    void casellaManoSelezionata(nat);

public slots:
    /**
     * @brief OpenSettingsWindow: slot per creare impostazioni
     */
    void OpenSettingsWindow();

    /**
     * @brief OpenTutorialWindow: slot per creare tutorial
     */
    void OpenTutorialWindow();


    /**
     * @brief OpenGameRequest: slot per creare boardwindow
     */
    void OpenGameWindow();
};

#endif // MAINWINDOW_H
