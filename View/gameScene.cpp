#include "View\Header\screens\gameScreen\gameScene.h"
// non c'è #include "Model\Header\game.h"

using std::vector;

namespace view {

GameScene::GameScene(){
    setItemIndexMethod(QGraphicsScene::NoIndex);

    setSceneRect(0,0,1280,720);

    drawBackground();
    createHUD();

};
}

//implementazione drawBackground e createUHD;
