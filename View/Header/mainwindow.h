#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "settingswindow.h"
#include "tutorialwindow.h"
#include "boardwindow.h"
#include "lastgamewindow.h"
#include "View/Header/winwindow.h"
#include "View/Header/settingsbutton.h"

#include <QLineEdit>
#include <QSize>
#include <QIcon>
#include <QHBoxLayout>
#include <QErrorMessage>
#include <QRect>
#include <QDesktopWidget>
#include <QFormLayout>
#include <QPoint>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QString>

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
     * @brief MainWindow: costruttore di copia
     */
    MainWindow(const MainWindow& m);

    /**
     * @brief operator =: operatore di assegnazione
     */
    MainWindow& operator= (const MainWindow& m);

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
    /**
     * @brief lineE: spazio inserimento nome
     */
    QLineEdit* lineE;

/****************** Settings ************************************/
    /**
     * @brief Settings: bottone impostazioni
     */
    SettingsButton* settings;

    /**
     * @brief settWindow: finestra impostazioni
     */
    SettingsWindow *settWindow ;

/****************** Tutorial ************************************/
    /**
     * @brief tutorial: bottone finestra tutorial
     */
    QPushButton * tutorial;

    /**
     * @brief tWindow: finestra tutorial
     */
    Tutorialwindow *tWindow ;


/****************** Game ************************************/

    /**
     * @brief startGame: bottone inizio gioco
     */
    QPushButton* startGame;

    /**
     * @brief boardWindoW: finestra gioco
     */
    BoardWindow* boardWindoW ;


/****************** Last Game ************************************/
    /**
     * @brief lastGame: bottone finestra lastGame
     */
    QPushButton * lastGame ;

    LastGameWindow* LGWindow ;

/****************** Layout ************************************/
    /**
     * @brief Vl: layout principale finestra
     */
    QVBoxLayout *Vl ;

/********** Win *******/
    /**
     * @brief tWindow: finestra tutorial
     */
   WinWindow *openwinWindow ;


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
     * @brief RimbalzoCheImmagineHo: segnale di rimbalzo
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

    /**
     * @brief rimbalzoMossaAI
     */
    void rimbalzoMossaAI();

    void updateBoardAI(nat, QString);

    /**
     * @brief apriVittoria manda segnale e vincitore
     */
  void apriVittoria(QString);


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
     * @brief closeSettings: slot chiusura finestra impostazioni
     */
    void closeSettings();

    /**
     * @brief closeTutorial: slot chiusura finestra tutorial
     */
    void closeTutorial();

    /**
     * @brief GameRequestSlot: slot per inviare la richiesta di giocare
     */
    void GameRequestSlot();

    /**
     * @brief closeWinWindow: close the win window
     */
    void closeWinWindow();

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

    /**
     * @brief openWinWindow: apri la vittoria
     */
    void openWinWindow(QString);

};

#endif // MAINWINDOW_H
