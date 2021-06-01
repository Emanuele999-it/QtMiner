#include "View\Header\screens\gameScreen\gameScene.h"
#include "Model\Header\game.h"

using std::vector;

namespace view {

GameScene::GameScene(const model::Game& game): gioco(game){

    setSceneRect (0,0, 120, 720);

    board = new Board (QSize(96 * 16, 96 * 16));

}
}
