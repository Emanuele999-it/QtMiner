#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "../../View/Header/mainwindow.h"

class Controller : public QObject {
    Q_OBJECT

private:
    MainWindow* MainW;



public:
    Controller(QObject* parent= nullptr);

public slots:
    /**
     * @brief openSettings: permette di aprire la finestra delle impostazioni
     */
    void openSettings();

    /**
     * @brief openTutorial: permette di aprire finestra del tutorial
     */
    void openTutorial();

};

#endif // CONTROLLER_H
