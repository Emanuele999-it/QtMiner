#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QStackedWidget>
#include <QVBoxLayout>

#include "settingswindow.h"
#include "tutorialwindow.h"

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

    /**
     * @brief startGame: bottone inizio gioco
     */
    QPushButton* startGame;
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


/****************** Tutorial ************************************/

    /**
     * @brief lastGame: bottone finestra lastGame
     */
    QPushButton * lastGame;

    //da mettere lastGame


    /**
     * @brief Vl: layout principale finestra
     */
    QVBoxLayout *Vl;

private slots:

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


public slots:
    /**
     * @brief OpenSettingsWindow: slot per creare impostazioni
     */
    void OpenSettingsWindow();

    /**
     * @brief OpenTutorialWindow: slot per creare tutorial
     */
    void OpenTutorialWindow();

};

#endif // MAINWINDOW_H
