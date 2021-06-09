#include "View\Header\screens\gameScreen\gameScene.h"
#include "Model\Header\game.h"

using std::vector;

namespace view {

GameScene::GameScene(const model::Game& game): gioco(game){
    setItemIndexMethod(QGraphicsScene::NoIndex);

    setSceneRect(0,0,1280,720);

    drawBackground();
    createHUD();

}
}
