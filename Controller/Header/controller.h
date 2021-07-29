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

public:
    Controller(QObject* parent= nullptr);

public slots:
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
     * @brief updateView: aggiorna view di boardwindow
     */
    void updateView(nat, nat, Card*, Card*);


};

#endif // CONTROLLER_H
