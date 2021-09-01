#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QString>

#include "settingswindow.h"
#include "tutorialwindow.h"
#include "boardwindow.h"
#include "lastgamewindow.h"

#include <QLineEdit>
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
    MainWindow();

    /**
     * distruttore
     */
    ~MainWindow() override;

    /**
     * @brief creteObjVectors: funzione che permette di chiamare addElVEctors
     *                        di boardwindow
     */
    void createObjVectors();

private:
    QLineEdit* lineE = nullptr;

/****************** Settings ************************************/
    /**
     * @brief Settings: bottone impostazioni
     */
    QPushButton* settings = nullptr;

    /**
     * @brief settWindow: finestra impostazioni
     */
    SettingsWindow *settWindow = nullptr;

/****************** Tutorial ************************************/
    /**
     * @brief tutorial: bottone finestra tutorial
     */
    QPushButton * tutorial = nullptr;

    /**
     * @brief tWindow: finestra tutorial
     */
    Tutorialwindow *tWindow = nullptr;


/****************** Game ************************************/

    /**
     * @brief startGame: bottone inizio gioco
     */
    QPushButton* startGame = nullptr;

    /**
     * @brief boardWindoW: finestra gioco
     */
    BoardWindow* boardWindoW = nullptr;


/****************** Last Game ************************************/
    /**
     * @brief lastGame: bottone finestra lastGame
     */
    QPushButton * lastGame = nullptr;

    LastGameWindow* LGWindow = nullptr;

/****************** Layout ************************************/
    /**
     * @brief Vl: layout principale finestra
     */
    QVBoxLayout *Vl = nullptr;


signals:
    void chiusuraBoardWRimbalzo();

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
    void GameRequest(QString);

    /**
     * @brief LasTGameRequest: segnale per aprire la finestra dell'ultimo gioco
     */
    void LastGameRequest();


/********** Rimbalzo segnale da casella al controller ****************/
    /**
     * @brief casellaBoardSelezionata: passa il segnale al controller
     */
    void casellaBoardSelezionata(nat, nat);

    /**
     * @brief UpdateViewfromModel aggiornamento view dopo scelta carta da mettere in campo
     * @param a posizione carta mano
     * @param b posizione carta board
     * @param c1 carta da mano a board
     * @param c2 nuova carta
     * @param behaviour: come lo slot ricevente deve comportarsi
     */
    void UpdateViewfromModel(nat a, nat b, QString c1, QString c2, nat behaviour);

    /**
     * @brief UpdateCardMano: aggiorna view mano con la carta corretta
     * @param a: parametro posizione
     * @param c: porzione stringa nome carta
     */
    void UpdateCardMano(nat a, QString c, nat i);

    /**
     * @brief RimbalzoCheImmagineHo: segnale di rimbalzo per
     */
    void RimbalzoCheImmagineHo(nat);

    /**
     * @brief rimbalzoScambioCarteMB: segnale che permette di far arrivare il segnale di scambio carte
     *                                mano->board al controller
     */
    void rimbalzoScambioCarteMB();

    /**
     * @brief changeBoardDimension: segnale di rimbalzo verso il controller per modificare
     *                              la grandezza della board
     */
    void changeBoardDimension(nat);

    /**
     * @brief ScartaCartaRimbalzo: slot per sostituzione carta
     */
    void ScartaCartaRimbalzo();


/**********Logica per mossa successiva****************/
    /**
     * @brief rimbalzoMossaAI
     */
    void rimbalzoMossaAI();

    void updateBoardAI(nat, QString);


private slots:
    /**
     * @brief closeGameBoard: slot chiusura finestra di gioco
     */
    void closeGameBoard();

    /**
     * @brief closeLastGame: slot chiusura finestra ultima partita
     */
    void closeLastGame();

    /**
     * @brief GameRequestSlot: slot per inviare la richiesta di giocare passando
     */
    void GameRequestSlot();


public slots:
    /**
     * @brief OpenSettingsWindow: slot per creare impostazioni
     */
    void OpenSettingsWindow(nat);

    /**
     * @brief OpenTutorialWindow: slot per creare tutorial
     */
    void OpenTutorialWindow();

    /**
     * @brief OpenGameRequest: slot per creare boardwindow
     */
    void OpenGameWindow(nat dim, QString n);

    /**
     * @brief OpenLastGameWindow: slot per creare  lastGameWindow
     */
    void OpenLastGameWindow();

    /**
     * @brief changeCardsFailed: cambio carte fallito
     */
    void changeCardsFailed(QString i);


};

#endif // MAINWINDOW_H
