#ifndef GAMESCENE_H_
#define GAMESCENE_H_

#include <QGraphicsScene>
#include <vector>

#include "Model/Header/game.h"
#include "View\Header\screens\gameScreen\Board\board.h"
#include "View\Header\screens\gameScreen\mano.h"
#include "Model\Header\game.h"

namespace view {

class GameScene : public QGraphicsScene {
  Q_OBJECT
private:
    const model::Game gioco;
    /**
     * @brief board oggetto principale
     */
    Board* board;
    /**
     * @brief mano non troppo dissimile dalla board
     */
    Mano* inMano;
    vector <unique_ptr<Card>*> baseVector;

public:
    /**
     * @brief costruttore, niente di speciale
     */
    GameScene(const model::Game& game);

public slots:
    /**
     * @brief prendiDallaMano semplicemente dal vettore mano prende una carta e la salva
     * @attention non so se mettere questo metodo su mano o sulla scena
     */
    void prendiDallaMano(const vector <unique_ptr<Card>*> &mano);
    /**
     * @brief pesca ha un concetto simile, aggiunge una carta alla mano
     */
    void pesca(const vector <unique_ptr<Card>*> &mano);
    /**
     * @brief prossimoTurno necessario per il bot faccia la mossa
     */
    void prossimoTurno();
    /**
     * @brief pausa cambia la modal, vedremo se e come implementarlo
     */
    void pausa();

signals:
    /**
     * @brief pausaGioco necessario segnale per mettere in pausa
     */
    void pausaGioco();
    /**
     * @brief reset resetta le carte sul terreno e in mano e azzera il punteggio
     * @warning potrebbe risultare inutile
     */
    void reset();
    /**
     * @brief next serve per il segnale del bot per eseguire il suo turno
     */
    void next();
    /**
     * @brief menu torna alla schermata di menu
     */
    void menu();
};

};

#endif
