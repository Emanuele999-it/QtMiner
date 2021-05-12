#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QGraphicsScene>
#include "Controller/Header/scenes.h" //per le diverse scene
#include "Model/Header/game.h" //Questo serve per il gioco

namespace controller{

class Controller : public QObject {
    Q_OBJECT
/*
 * Qui va l'oggetto "game" che serve per gestire tutto
 */
public:
    Controller(QObject* parent= nullptr);

    virtual QGraphicsScene* getScene() const = 0;

signals:
    void goTo (controller::Scenes scene); //Essenzialmente serve a cmbiare scena

};

}
#endif // CONTROLLER_H
