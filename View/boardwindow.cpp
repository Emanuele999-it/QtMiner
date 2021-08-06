#include "View/Header/boardwindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QWidget>
#include <QLCDNumber>
#include "View/Header/screens/gameScreen/Board/board.h"
#include "View\Header\screens\gameScreen\Board\casella.h"


BoardWindow::BoardWindow(QWidget *p, nat num) : QWidget(p), celle(num)
{


    b = new view::Board(celle);
    m = new view::Mano(7);
    connect(b, &view::Board::numCasellaCliccataBoard, this, &BoardWindow::rimbalzoSegnaleCasellaSelezionataBoard);
    connect(m, &view::Mano::numCasellaCliccataMano, this, &BoardWindow::rimbalzoSegnaleCasellaSelezionataMano);

    mosse = new QLCDNumber(3);
    mosse->setSegmentStyle(QLCDNumber::Filled);


    //LAYOUT


    QVBoxLayout *Vlayout = new QVBoxLayout(this);

    //layout board
    QGridLayout *GBLayout = new QGridLayout();
    //layout mano
    QGridLayout *GMLayout = new QGridLayout();


    Vlayout->addLayout(GBLayout);
    Vlayout->addLayout(GMLayout);


    c= new view::Casella();

    for(int i=0;i<10;i++)
        q.push_back(new QPushButton("ciao"));

/*
    for(int i=0;i<b->vettoreCaselleBoard.size();i++){
       GBLayout->addWidget((q[i]),i%3,i/3);
    }
*/
/*
 *      PROBLEMA: CASELLA NON VIENE VISULAIZZATA: RISOLVERE
 *
 */
                // size() da' come risultato 0
    for(int i=0;i<b->vettoreCaselleBoard.size()+1;i++){
        //emit b->cheImmagineHo(i);
        //GBLayout->addWidget((b->vettoreCaselleBoard[i]),i%4,i/4);
        GBLayout->addWidget(c,i%4,i/4);
    }

/*    che immagine ho da differenziare tra mano/board

    for(int i=0;i<m->vettoreCaselleMano.size();i++){
        //emit m->cheImmagineHo(i);
        GMLayout->addWidget((m->vettoreCaselleMano[i]),i,1);
        m->vettoreCaselleMano[i]->show();
    }
*/

    setWindowTitle(tr("Qtminer"));
    resize(1280, 720);

}

void BoardWindow::aggiornamentoView(nat posMano, nat PosBoard, QString CartaBoard, QString CartaMano){

    // mettere carta CartaBoard in posizione posBoard in b+ù
    b->addCardBoard(PosBoard,CartaBoard);

    // mettere carta CartaMano in posizione posMano in m
    m->addCardMano(posMano,CartaMano);
}
