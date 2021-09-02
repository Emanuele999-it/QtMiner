#include "Header/lastgamewindow.h"

#include <QDebug>
#include <QPixmap>
#include <vector>

LastGameWindow::~LastGameWindow(){
    if(grid) delete grid;
    if(ultimaP) delete ultimaP;
}

LastGameWindow::LastGameWindow(const LastGameWindow& l){
    setWindowTitle ("QtMiner - Ultima partita");
    QVBoxLayout * vl= new QVBoxLayout(this);
    ultimaP = l.ultimaP;
    grid = new QGridLayout();

    vl->addWidget(ultimaP);
    vl->addLayout(grid);

    std::vector<QString> vec;
    //salvare numero di celle
    //array con i vari caratteri
    QString val;
    QFile file;
    file.setFileName("lastgameboard.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();

    //rimozione caratteri inutili
    val.remove("\"");
    val.remove(":");
    val.remove(",");
    val.remove("]");
    val.remove("[");
    val.remove("{");
    val.remove("}");
    val.remove(0,6);

    bool nonUltimo = true;
    int counter=0;

    while(nonUltimo){
        int index = val.indexOf(QString::number(counter)+" ");
        QString get = val.mid(index, val.indexOf("\n "));
        val.remove(index -1,(val.indexOf("\n ") - index-2));

        // questo perché quando mid non trova alcun valore ritorna -1
        if(get == val.mid(val.indexOf(QString::number(-1)+" "), val.indexOf("\n")))
            nonUltimo=false;
        else{
            get.remove("\n");
            get.remove(" ");
            get.remove(QString::number(counter));
            vec.push_back(get);

        }
        counter++;
    }

    counter=0;

    for(auto it = vec.begin(); it!=vec.end();++it){
        QImage* inputImg = new QImage(":/Img/"+(*it)+".jpg");
        QLabel* l  = new QLabel("");
        l->setPixmap(QPixmap::fromImage(*inputImg).scaled(50,75));
        if(vec.size()== 50)
            grid->addWidget(l,counter/5,counter%5);
        else if(vec.size()== 70)
            grid->addWidget(l,counter/7,counter%7);
        else
            grid->addWidget(l,counter/9,counter%9);
        counter++;
    }
    show();
}

LastGameWindow& LastGameWindow::operator=(const LastGameWindow& l){
    if(this != &l){
        delete ultimaP;

        setWindowTitle ("QtMiner - Ultima partita");
        QVBoxLayout * vl= new QVBoxLayout(this);
        ultimaP = l.ultimaP;
        grid = new QGridLayout();

        vl->addWidget(ultimaP);
        vl->addLayout(grid);

        std::vector<QString> vec;
        //salvare numero di celle
        //array con i vari caratteri
        QString val;
        QFile file;
        file.setFileName("lastgameboard.json");
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        val = file.readAll();
        file.close();

        //rimozione caratteri inutili
        val.remove("\"");
        val.remove(":");
        val.remove(",");
        val.remove("]");
        val.remove("[");
        val.remove("{");
        val.remove("}");
        val.remove(0,6);

        bool nonUltimo = true;
        int counter=0;

        while(nonUltimo){
            int index = val.indexOf(QString::number(counter)+" ");
            QString get = val.mid(index, val.indexOf("\n "));
            val.remove(index -1,(val.indexOf("\n ") - index-2));

            // questo perché quando mid non trova alcun valore ritorna -1
            if(get == val.mid(val.indexOf(QString::number(-1)+" "), val.indexOf("\n")))
                nonUltimo=false;
            else{
                get.remove("\n");
                get.remove(" ");
                get.remove(QString::number(counter));
                vec.push_back(get);
            }
            counter++;
        }
        counter=0;

        for(auto it = vec.begin(); it!=vec.end();++it){
            QImage* inputImg = new QImage(":/Img/"+(*it)+".jpg");
            QLabel* l  = new QLabel("");
            l->setPixmap(QPixmap::fromImage(*inputImg).scaled(50,75));
            if(vec.size()== 50)
                grid->addWidget(l,counter/5,counter%5);
            else if(vec.size()== 70)
                grid->addWidget(l,counter/7,counter%7);
            else
                grid->addWidget(l,counter/9,counter%9);
            counter++;
        }
        show();
    }
    return *this;
}

LastGameWindow::LastGameWindow(){
    setWindowTitle ("QtMiner - Ultima partita");
        QVBoxLayout * vl= new QVBoxLayout(this);
        ultimaP = new QLabel("Ecco i risultati dell'ultima partita: ");
        grid = new QGridLayout();

        vl->addWidget(ultimaP);
        vl->addLayout(grid);

        std::vector<QString> vec;
        //salvare numero di celle
        //array con i vari caratteri
        QString val;
        QFile file;
        file.setFileName("lastgameboard.json");
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        val = file.readAll();
        file.close();

        //rimozione caratteri inutili
        val.remove("\"");
        val.remove(":");
        val.remove(",");
        val.remove("]");
        val.remove("[");
        val.remove("{");
        val.remove("}");
        val.remove(0,6);

        bool nonUltimo = true;
        int counter=0;

        while(nonUltimo){
            int index = val.indexOf(" "+QString::number(counter)+" ");
            QString get = val.mid(index, val.indexOf("\n "));
            val.remove(index -1,(val.indexOf("\n ") - index-2));

            // questo perché quando mid non trova alcun valore ritorna -1
            if(get == val.mid(val.indexOf(QString::number(-1)+" "), val.indexOf("\n")))
                nonUltimo=false;
            else{
                get.remove("\n");
                get.remove(" ");
                get.remove(QString::number(counter));
                vec.push_back(get);
            }
            counter++;
        }

        counter=0;

        for(auto it = vec.begin(); it!=vec.end();++it){
            QImage* inputImg = new QImage(":/Img/"+(*it)+".jpg");
            QLabel* l  = new QLabel("");
            l->setPixmap(QPixmap::fromImage(*inputImg).scaled(50,75));
            if(vec.size()== 50)
                grid->addWidget(l,counter/5,counter%5);
            else if(vec.size()== 70)
                grid->addWidget(l,counter/7,counter%7);
            else
                grid->addWidget(l,counter/9,counter%9);
            counter++;
        }
        show();
}

void LastGameWindow::closeEvent(QCloseEvent *event){
    Q_UNUSED(event)
    emit chiusuraLastGame();
}

