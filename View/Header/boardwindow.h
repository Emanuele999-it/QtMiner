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

#include <QCloseEvent>

class BoardWindow : public QWidget{

    Q_OBJECT
public:
    BoardWindow(QWidget *parent = nullptr, nat num=40);

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
    QGridLayout *GBLayout;
    QGridLayout *GMLayout;

    /**
     * @brief closeEvent: evento chiusura finestra
     * @param event
     */
    void closeEvent(QCloseEvent *event);
    QPushButton *scambioMB;
    QPushButton *prossimo;

public slots:
    /**
     * @brief aggiornamentoView: aggiornamento view in seguito al posizionamento di una carta
     * @param posMano
     * @param PosBoard
     * @param CartaBoard    nome immagine da inserire nella board in pos. PosBoard
     * @param CartaMano     nome immagine da inserire nella mano in pos. CartaMano
     */
    void aggiornamentoView(nat posMano, nat PosBoard, QString CartaMano, QString CartaBoard);

    /**
     * @brief aggiornamentoCartaMano: per modificare le immagini delle carte della mano
     * @param a: posizione carta
     * @param c: porzione di stringa da sostituire
     */
    void aggiornamentoCartaMano(nat a , QString c);

    /**
     * @brief controlloCarteDaScambiare: funzione che controlla se sono state selezionate le carte
     *                                  da scambiare
     */
    void controlloCarteDaScambiare();

    /**
     * @brief avvia la mossa e triggera l'IA
     * @param a il numero da aggiornare
     */
    void avviaMossaAI();

    /**
     * @brief aggiornamentoBoardAI: aggiornare la view da IA
     * @param posAI
     * @param CartaAI
     */
    void aggiornamentoBoardAI(nat posAI, QString CartaAI);

signals:
    /**
     * @brief chiusuraBoardW: segnale chiusura boardWindow
     */
    void chiusuraBoardW();

    /**
     * @brief rimbalzoSegnaleCasellaSelezionataBoard: prende il segnale casellaCliccataBoard e lo
     *                  passa alla classe gerarchicamente superiore
     */
    void rimbalzoSegnaleCasellaSelezionataBoard(nat);

    /**
     * @brief rimbalzoSegnaleCasellaSelezionataMano: stessa cosa del precedente
     */
    void rimbalzoSegnaleCasellaSelezionataMano(nat);

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

};

#endif // BOARDWINDOW_H
