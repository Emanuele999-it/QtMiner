#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "../../View/Header/mainwindow.h"
#include "../../Model/Header/modelBoard.h"

class Controller : public QObject {
    Q_OBJECT

private:
    /**
     * @brief MainW: ptr finestra principale
     */
    MainWindow* MainW;


    model::ModelBoard* modelBoard;


    void buildAndConnectModelView();


public:
    Controller(QObject* parent= nullptr);

public slots:

    /**
     * @brief chiusuraGame: slot che intercetta segnale di chiusura della
     *                  finestra di gioco
     */
    void chiusuraGame();

/******************* MainWindow **************************************************************/
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


/******************* Casella **************************************************************/

    /**
     * @brief cambiaCellaBoard: slot che permette di cambiare
     *                  la della slezionata nella board/mano
     */
    void cambiaCellaBoard(nat);

    /**
     * @brief cambiaCellaModel: segnale modifica cella selezionata
     *                      per il modello modelBoard
     */
    void cambiaCellaMano(nat);

    /**
     * @brief cambia la carta in una posizione specifica nela board
     */
    //void cambiaCellaBoardAI(nat);
signals:

};

#endif // CONTROLLER_H
