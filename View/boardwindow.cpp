#include "View/Header/boardwindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QWidget>
#include <QLCDNumber>
#include "View/Header/screens/gameScreen/Board/board.h"
#include "View\Header\screens\gameScreen\Board\casella.h"


BoardWindow::BoardWindow(QWidget *p, nat num) : QWidget(p), celle(num)
{
    setWindowTitle(tr("Qtminer"));
    resize(1280, 720);

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

/*
    c= new view::Casella();

    for(int i=0;i<10;i++)
        q.push_back(new view::Casella(i));

    for(int i=0;i<10;i++){
       GBLayout->addWidget((q[i]),i%3,i/3);
    }
*/
/*
    for(int i=0;i<b->vettoreCaselleBoard.size();i++){
       GBLayout->addWidget((q[i]),i%3,i/3);
    }


      // PROBLEMA: CASELLA NON VIENE VISULAIZZATA: RISOLVERE

*/

    for(nat counter=0; counter<celle; counter++){
        //emit m->cheImmagineHo(i);
        b->vettoreCaselleBoard.push_back(new view::Casella(counter));
        connect(b->vettoreCaselleBoard[counter],SIGNAL(casellaCliccata(nat)), b, SLOT(selectCardBoard(nat)));
        GBLayout->addWidget(b->vettoreCaselleBoard[counter],counter%8,counter/8);
    }


    for(nat counter=0; counter<7; counter++){
        //emit m->cheImmagineHo(i);
        m->vettoreCaselleMano.push_back(new view::Casella(counter));
        connect(m->vettoreCaselleMano[counter],SIGNAL(casellaCliccata(nat)), m, SLOT(selectCardMano(nat)));
        GMLayout->addWidget(m->vettoreCaselleMano[counter],1,counter);

    }






/*
 *          PRIMA VERSIONE
 *
               // size() da' come risultato 0
    for(int i=0;i<b->vettoreCaselleBoard.size();i++){
        //emit b->cheImmagineHo(i);
        GBLayout->addWidget(b->vettoreCaselleBoard[i],i%4,i/4);
        //connect(b->vettoreCaselleBoard[i],SIGNAL(casellaCliccata(nat)), b, SLOT(selectCardBoard(nat)));
        //GBLayout->addWidget(c,i%4,i/4);
    }
*/
//    che immagine ho da differenziare tra mano/board





}

void BoardWindow::aggiornamentoView(nat posMano, nat PosBoard, QString CartaBoard, QString CartaMano){

    // mettere carta CartaBoard in posizione posBoard in b+ù
    b->addCardBoard(PosBoard,CartaBoard);

    // mettere carta CartaMano in posizione posMano in m
    m->addCardMano(posMano,CartaMano);
}
