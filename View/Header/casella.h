// informazioni riguardo la posizione, tipo e posizioni possibili
#include <QLabel>
#include <QWidget>

class Casella : public QWidget{
private:
    class TipoCarta{
        private:
            bool Nord;
            bool Sud;
            bool Est;
            bool Ovest;
        public:
            bool getNord(){return Nord;};
            bool getSud(){return Sud;};
            bool getEst(){return Est;};
            bool getOvest(){return Ovest;};

            TipoCarta(): Nord(true),Sud(true),Est(true),Ovest(true){};
    };

    Tipocarta tipo; //TipoCarta è se è una strada o altro (Se vuota null)
    void posizione();
public:
    Casella();
    void cartaRandom();
    void tipoCarta();
};


