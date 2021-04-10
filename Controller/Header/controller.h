#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "View/Header/mainwindow.h"

class Controller: public QObject
{
    /**
     * @brief Q_OBJECT: macro per signal/slot
     */
    Q_OBJECT

private:
    /**
     * @brief MainW: finestra iniziale
     */
    MainWindow* MainW =nullptr;

public:
    /**
     * @brief Controller: costruttore di default
     * @param parent: parent di Controller
     */
    Controller(QObject* parent = nullptr);
    /**
     * @brief ShowMainWindow: metodo usato per visualizzare la finestra
     */
    void ShowMainWindow() const;

protected slots:
    /**
     * @brief openSettings: sloto collegamento tra mainwindow
     *                      e finestra impostazioni
     */
    void openSettings();
};

#endif // CONTROLLER_H
