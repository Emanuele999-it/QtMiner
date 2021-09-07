#include "Header/lastgamewindow.h"

LastGameWindow::~LastGameWindow(){
    if(grid) delete grid;
    if(ultimaP) delete ultimaP;
}

LastGameWindow::LastGameWindow(const LastGameWindow& l){
    setMaximumSize(275,500);
    setWindowTitle ("QtMiner - Ultima partita");
    QVBoxLayout * vl= new QVBoxLayout(this);
    ultimaP = l.ultimaP;
    grid = new QGridLayout();

    vl->addWidget(ultimaP);
    vl->addLayout(grid);

    std::vector<QString> vec;
    QString val;
    QFile file;
    file.setFileName("lastgameboard.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();

    val.remove("\"");
    val.remove(":");
    val.remove(",");
    val.remove("]");
    val.remove("[");
    val.remove("{");
    val.remove("}");
    val.remove(0,6);

    int index = val.indexOf("-1 ");
    if(index){
        QString get = val.mid(index, val.indexOf("\n "));
        val.remove(index-1,(val.indexOf("\n ")));
        get.remove("-1");
        get.remove(" ");
        get.remove("\n");
        if(!get.contains("Winner")){}
        else{
            QString temp=get;
            temp.remove("Winner");
            if(temp == ""){
                vincitore->setText("Il vincitore è l'utente ");
            }
            else
            {
                vincitore->setText("Il vincitore è: "+(temp));
            }
        }
    }

    index=0;
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

        setMaximumSize(275,500);
        setWindowTitle ("QtMiner - Ultima partita");
        QVBoxLayout * vl= new QVBoxLayout(this);
        ultimaP = l.ultimaP;
        grid = new QGridLayout();

        vl->addWidget(ultimaP);
        vl->addLayout(grid);

        std::vector<QString> vec;
        QString val;
        QFile file;
        file.setFileName("lastgameboard.json");
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        val = file.readAll();
        file.close();

        val.remove("\"");
        val.remove(":");
        val.remove(",");
        val.remove("]");
        val.remove("[");
        val.remove("{");
        val.remove("}");
        val.remove(0,6);

        int index = val.indexOf("-1 ");
        if(index){
            QString get = val.mid(index, val.indexOf("\n "));
            val.remove(index-1,(val.indexOf("\n ")));
            get.remove("-1");
            get.remove(" ");
            get.remove("\n");
            if(!get.contains("Winner")){}
            else{
                QString temp=get;
                temp.remove("Winner");
                if(temp == ""){
                    vincitore->setText("Il vincitore è l'utente ");
                }
                else
                {
                    vincitore->setText("Il vincitore è: "+(temp));
                }
            }
        }
        index=0;
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
    setMaximumSize(275,500);

    setWindowTitle ("QtMiner - Ultima partita");
        QVBoxLayout * vl= new QVBoxLayout(this);
        ultimaP = new QLabel("Ecco i risultati dell'ultima partita: ");
        vincitore= new QLabel();
        grid = new QGridLayout();

        vl->addWidget(ultimaP);
        vl->addWidget(vincitore);
        vl->addLayout(grid);

        std::vector<QString> vec;
        QString val;
        QFile file;
        file.setFileName("lastgameboard.json");
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        val = file.readAll();
        file.close();

        val.remove("\"");
        val.remove(":");
        val.remove(",");
        val.remove("]");
        val.remove("[");
        val.remove("{");
        val.remove("}");
        val.remove(0,6);

        int index = val.indexOf("-1 ");
        if(index){
            QString get = val.mid(index, val.indexOf("\n "));
            val.remove(index-1,(val.indexOf("\n ")));
            get.remove("-1");
            get.remove(" ");
            get.remove("\n");
            if(!get.contains("Winner")){
                vincitore->setText("Il vincitore è: "+(get));
            }
            else{
                QString temp=get;
                temp.remove("Winner");
                if(temp == ""){
                    vincitore->setText("Il vincitore è l'utente ");
                }
                else
                {
                    vincitore->setText("Il vincitore è: "+(temp));
                }
            }
        }

        index=0;
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

