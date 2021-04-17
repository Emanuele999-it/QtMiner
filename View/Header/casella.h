// informazioni riguardo la posizione, tipo e posizioni possibili
#include <QLabel>
#include <QWidget>

class Casella : public QWidget{
private:
    bool Cardinali[3]; // Nord, Est, Sud, Ovest
    /*
    class TipoCarta{
        private:
            bool Nord;
            bool Sud;
            bool Est;
            bool Ovest;
        public:
            bool getNord(){return Nord;}
            bool getSud(){return Sud;}
            bool getEst(){return Est;}
            bool getOvest(){return Ovest;}

            TipoCarta(): Nord(true),Sud(true),Est(true),Ovest(true){}
    };

    TipoCarta tipo; //TipoCarta è se è una strada o altro (Se vuota null)
    */
    int posizione=0;
public:
    void getPosizione();
    Casella();
   // virtual ~Casella() {};
    //virtual void targetCasella();
    //virtual bool tipoCarta();
};

class Ostacolo : public Casella{
public:
    //bool tipoCarta() override;// Questa ci serve per la chiamata polimorfa
};

class Blocco : public Ostacolo{
public:
    //bool tipoCarta() override;
};

class Crollo : public Blocco{
public:
    //void targetCasella() override;
    //~Crollo(){};
};





