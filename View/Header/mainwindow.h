#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>

#include "mainsettingswindow.h"

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

    /**
     * @brief startGame: bottone inizio gioco
     */
    QPushButton* startGame;
    /**
     * @brief Settings: bottone impostazioni
     */
    QPushButton* settings;

    MainSettingsWindow *settWindow;

signals:
    /**
    * @brief OpenSettings: segnale per aprire finestra impostazioni
    */
    void OpenSettingsRequest();

public slots:
    /**
     * @brief OpenSettingsWindow: slot che crea e
     *                            rende visibile impostazioni
     */
    void OpenSettingsWindow();
};

#endif // MAINWINDOW_H
