#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "../../View/Header/mainwindow.h"
#include "../../Model/Header/modelBoard.h"
#include "../../View/Header/winwindow.h"

class Controller : public QObject {
    Q_OBJECT

private:
    /**
     * @brief MainW: ptr finestra principale
     */
    MainWindow* MainW;


    model::ModelBoard* modelBoard=nullptr;

    WinWindow* winBoard = nullptr;

    nat boardDimension;

    void buildAndConnectModelView();

    QString name;

public:
    /**
     * @brief Controller: costruttore
     */
    Controller(QObject* parent= nullptr);

    /**
     * @brief Controller: costruttore copia
     */
    Controller(const Controller& c);

    /**
     * @brief operator =: op. assegnazione
     */
    Controller& operator=(const Controller& c);

    /**
    * @brief distruttore
    */
    ~Controller() override;

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
    void openBoardWindow(QString);

    /**
     * @brief openLastGameWindow: permette di creare lastGameWindow
     */
    void openLastGameWindow();


/******************* Casella **************************************************************/

    /**
     * @brief cambiaCellaBoard: slot che permette di cambiare
     *                  la della slezionata nella board/mano
     */
    void cambiaCellaBoard(nat, nat);

    /**
     * @brief cambioDimensioniBoard: slot per modifica della dimensione della board
     */
    void cambioDimensioniBoard(nat);

    /**
     * @brief scartaCartaDallaMano: permette di scambiare carta in mano con una estratta
     *                              casualmente
     */
    void scartaCartaDallaMano();

signals:
};

#endif // CONTROLLER_H
