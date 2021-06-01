#ifndef MODEL_GAME_H_
#define MODEL_GAME_H_

namespace model {

class Game {
private:
    void win();
public:
    enum State {
      Execution,
      Pause,
      End
    };

};
}

#endif
