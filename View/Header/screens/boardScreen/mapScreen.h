#ifndef BOARD
#define BOARD
#include <QFrame>
#include <QGridLayout>
#include <QBasicTimer>
#include "View\Header\casella.h"

class Board : public QFrame
{
private:
    int numeroCaselle = 64;
    QVector<Casella*> casellaVettore; //vettore caselle
    QLabel *createLabel(const QString &text);

public:
    Board(QWidget *p = nullptr); //Ok, fatta la board la popolo

public slots:
    void next(); //per la mossa dopo
    void pausa(); //per impostazioni

signals:
    void pietraTrovata (bool found);
    void carteGiocate (int carteGiocate);
    void pietreTrovate (int pietre); //se lo implementiamo idk

protected:
    void avantiUnTurno(QKeyEvent *event);

private:
    enum { BoardWidth = 10, BoardHeight = 22 };

    QBasicTimer timer;
    bool Partita; //La partita sta andando o no?
    bool Pausa; //vogliamo implemetare la pausa?
    int Carte; //carte giocate
    bool trovato; // suppongo che questa sia la vittoria
    QVector<Casella*> Mano; //Queste sono le carte in mano
};


#endif
