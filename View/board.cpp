#include "View\Header\screens\gameScreen\Board\board.h"

#include <QGraphicsScene>

using std::vector;

namespace view {

Board(const unsigned int& i){


    //connect(Casella,&QPushButton::clicked, this, &MainWindow::TutorialRequest);

}


void Board::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Q_UNUSED(option);
    Q_UNUSED(widget);
    Q_UNUSED(painter);

}

void Board::selectCardBoard(const Card* confronto){
    //allora si fa il for di tutto l'array e se si trova la card nell'array si mette true
    for(int i=0; i<40;i++){
        if(_caselle.getCardBoard(i) == confronto){ //conftonto i loro L-valori per evitare FP
            _caselle.cambiaSelezioneBoard(i);
        }
    }
}

void Board::selectCardHand(const Card* confronto){
    //allora si fa il for di tutto l'array e se si trova la card nell'array si mette true
    for(int i=0; i<7;i++){
        if(_caselle.getCardMano(i) == confronto){ //conftonto i loro L-valori per evitare FP
            _caselle.cambiaSelezioneMano(i);
        }
    }
}

}
