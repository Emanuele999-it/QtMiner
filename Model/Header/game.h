#ifndef MODEL_GAME_H_
#define MODEL_GAME_H_

namespace model {

class Game {
private:
    /*
     * Ok qui ci va il vettore di puntatori alle singole carte
     */
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
