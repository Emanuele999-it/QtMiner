#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "../../View/Header/mainwindow.h"

class Controller : public QObject {
    Q_OBJECT

private:
    /**
     * @brief MainW: ptr finestra principale
     */
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

    /**
     * @brief openBoardWindow: permette di aprire finestra gioco
     */
    void openBoardWindow();


    /**
     * @brief cambiaCellaSelezionata: slot che permette di cambiare
     *                  la della slezionata nella board/mano
     */
    void cambiaCellaSelezionata(nat);

signals:
    /**
     * @brief cambiaCellaModel: segnale modifica cella selezionata
     *                      per il modello modelBoard
     */
    void cambiaCellaModel(nat);

};

#endif // CONTROLLER_H
