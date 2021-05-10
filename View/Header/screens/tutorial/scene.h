#ifndef TUTORIAL_SCENE_H
#define TUTORIAL_SCENE_H

#include <QGraphicsScene>

namespace view {

class TutorialScene : public QGraphicsScene {
    Q_OBJECT

public:
    TutorialScene();

signals:
    /*
     * @brief bottoni per far partire il gioco e vero e proprio
     */

    void start();
    void menu();
};
}
#endif
