#ifndef VIEW_INITIAL_SCREEN_H_
#define VIEW_INITIAL_SCREEN_H_

#include <QGraphicsScene>
#include <QPushButton>

#include "View/Header/mainsettingswindow.h"

#include <QSize>
#include <QIcon>

namespace view{

class MainWindow: public QGraphicsScene
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
    void OpenSettingsRequest() const;

public slots:
    /**
     * @brief OpenSettingsWindow: slot che crea e
     *                            rende visibile impostazioni
     */
    void OpenSettingsWindow();
};
}
#endif // MAINWINDOW_H


