#ifndef GAMESCENE_H_
#define GAMESCENE_H_

#include <QGraphicsScene>
#include <vector>

#include "View/Header/screens/gameScreen/Board/board.h"
#include <QPushButton>

namespace view {

//GameScene: racchiude tutto ciò che è visibile

class GameScene : public QGraphicsScene {
  Q_OBJECT
private:
    Board* _board;
    Board* _mano;


    void drawBackground();
    void createHUD();
public:
    GameScene();
    /**
     * @brief costruttore, niente di speciale
     */

public slots:
    void premiBoard(const QPointF& click);


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

}

#endif
