#ifndef BOARDWINDOW_H
#define BOARDWINDOW_H

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMainWindow>
#include <QLabel>
#include <QLCDNumber>
#include "View/Header/screens/gameScreen/Board/board.h"
#include "View/Header/boardwindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QWidget>
#include <QLCDNumber>
#include "View/Header/screens/gameScreen/Board/casella.h"
#include <QSpacerItem>

#include <QDialog>

#include <QCloseEvent>

class BoardWindow : public QWidget{

    Q_OBJECT
public:
    BoardWindow(nat num=40);

    /**
     * @brief addElVectors: permette di aggiungere gli elementi ai
     *                      vettori
     */
    void addElVectors();

private:
    QLabel *label(const QString &text);
    view::Board *b;
    view::Mano *m;
    QLCDNumber *mosse;
    nat celle;
    QVBoxLayout *v;
    bool mano;
    bool board;


    /**
     * @brief closeEvent: evento chiusura finestra
     * @param event
     */
    void closeEvent(QCloseEvent *event);
    QPushButton *scambioMB;
    QPushButton *scarta;

public slots:
    /**
     * @brief aggiornamentoView: aggiornamento view in seguito al posizionamento di una carta
     * @param posMano
     * @param PosBoard
     * @param CartaBoard: nome immagine da inserire nella board in pos. PosBoard
     * @param CartaMano: nome immagine da inserire nella mano in pos. CartaMano
     * @param behaviour: come lo slot deve gestire i dati ricevuti
     */
    void aggiornamentoView(nat posMano, nat PosBoard, QString CartaMano, QString CartaBoard, nat behaviour);

    /**
     * @brief aggiornamentoCartaMano: per modificare le immagini delle carte della mano
     * @param a: posizione carta
     * @param c: porzione di stringa da sostituire
     */
    void aggiornamentoCartaMano(nat a , QString c, nat i);

    /**
     * @brief controlloCarteDaScambiare: funzione che controlla se sono state selezionate le carte
     *                                  da scambiare
     */
    void controlloCarteDaScambiare();

    /**
    * @brief avvia la mossa e triggera l'IA
    */
    void avviaMossaAI();

    /**
     * @brief aggiornamentoBoardAI: aggiornare la view da IA
     * @param posAI
     * @param CartaAI
     */
    void aggiornamentoBoardAI(nat posAI, QString CartaAI);

    /*
     * @brief activateButton:slot per l'attivazione del bottone scambio
     */
    void activateButton(nat);

    /**
     * @brief disableButton: slot per disabilitare bottone
     */
    void disableButton();


private slots:
    /**
     * @brief cellaSelezionata: slot che permette di differenziare chi ha emesso numCasellaCliccata
     */
    void cellaSelezionata(nat);


signals:
    /**
     * @brief chiusuraBoardW: segnale chiusura boardWindow
     */
    void chiusuraBoardW();

    /**
     * @brief rimbalzoSegnaleCasellaSelezionataBoard: prende il segnale casellaCliccataBoard e lo
     *                  passa alla classe gerarchicamente superiore
     */
    void rimbalzoSegnaleCasellaSelezionataBoard(nat, nat);


    /**
     * @brief scambiaScarte: funzione che permette di scambiare le carte da mano a board
     */
    void scambiaScarte(nat, nat);

    /**
     * @brief cheImmagineHo: segnale per chiedere al model il tipo di carta
     */
    void cheImmagineHo(nat);

    /**
     * @brief mossaAI: aggiunge alla board (ove possibile) una carta random
     */
    void mossaAI();

    /**
     * @brief scartaCarta: segnale la cui funzione è quella di sostituire la carta
     *                     in una certa posizione della mano con una carta estratta
     *                     casualmente
     */
    void scartaCarta();

};

#endif // BOARDWINDOW_H
