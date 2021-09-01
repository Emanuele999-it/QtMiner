#include "Header/tutorialwindow.h"


Tutorialwindow::~Tutorialwindow(){
    if(e) delete e;
    if(l) delete l;
    if(avanti) delete avanti;
    if(indietro) delete indietro;
    if(menu) delete menu;
    if(text) delete text;
}

Tutorialwindow::Tutorialwindow(const Tutorialwindow &t){
    setWindowTitle ("QtMiner - Tutorial");

    setMinimumSize(350,300);
    setMaximumSize(1280,960);

    l= new QVBoxLayout(this);
    QHBoxLayout *h = new QHBoxLayout();

    text = t.text;
    l->addWidget(text);
    l->addLayout(h);

    indietro = t.indietro;
    avanti = t.avanti;
    menu = t.menu;

    h->addWidget(indietro);
    h->addWidget(avanti);
    h->addWidget(menu);

    TotLine=0;
    QFile file(":/readme2.txt");
    QString line="";
    if (file.open(QIODevice::ReadOnly)){
        QTextStream stream(&file);
        line.append(stream.readLine());
        page=0;
        text->setText(line);
        QString mock;
        while(! stream.atEnd()){
            mock=stream.readLine();
            TotLine+=1;
        }
    }
    else{
        close();
    }
    file.close();

    h->addWidget(indietro);
    h->addWidget(avanti);
    h->addWidget(menu);

    connect(menu,&QPushButton::clicked,this,&Tutorialwindow::CloseWindow);
    connect(avanti,&QPushButton::clicked,this,&Tutorialwindow::ContinueTutorial);
    connect(indietro,&QPushButton::clicked,this,&Tutorialwindow::GoBackTutorial);
    indietro->setDisabled(true);
}

Tutorialwindow& Tutorialwindow::operator=(const Tutorialwindow& t){
    if(this != &t){
        delete e;
        delete avanti;
        delete indietro;
        delete menu;
        delete text;

        setWindowTitle ("QtMiner - Tutorial");

        setMinimumSize(350,300);
        setMaximumSize(1280,960);

        l= new QVBoxLayout(this);
        QHBoxLayout *h = new QHBoxLayout();

        text = t.text;
        l->addWidget(text);
        l->addLayout(h);

        indietro = t.indietro;
        avanti = t.avanti;
        menu = t.menu;

        h->addWidget(indietro);
        h->addWidget(avanti);
        h->addWidget(menu);

        TotLine=0;
        QFile file(":/readme2.txt");
        QString line="";
        if (file.open(QIODevice::ReadOnly)){
            QTextStream stream(&file);
            line.append(stream.readLine());
            page=0;
            text->setText(line);
            QString mock;
            while(! stream.atEnd()){
                mock=stream.readLine();
                TotLine+=1;
            }
        }
        else{
            close();
        }
        file.close();

        h->addWidget(indietro);
        h->addWidget(avanti);
        h->addWidget(menu);

        connect(menu,&QPushButton::clicked,this,&Tutorialwindow::CloseWindow);
        connect(avanti,&QPushButton::clicked,this,&Tutorialwindow::ContinueTutorial);
        connect(indietro,&QPushButton::clicked,this,&Tutorialwindow::GoBackTutorial);
        indietro->setDisabled(true);
    }
    return *this;
}

Tutorialwindow::Tutorialwindow()
{

    setWindowTitle ("QtMiner - Tutorial");

    setMinimumSize(350,300);
    setMaximumSize(1280,960);

    l= new QVBoxLayout(this);
    QHBoxLayout *h = new QHBoxLayout();

    text = new QLabel();
    l->addWidget(text);
    l->addLayout(h);

    indietro = new QPushButton(tr("Indietro"));
    avanti = new QPushButton(tr("Avanti"));
    menu = new QPushButton(tr("Finestra principale"));

    h->addWidget(indietro);
    h->addWidget(avanti);
    h->addWidget(menu);

    TotLine=0;
    QFile file(":/readme2.txt");
    QString line="";
    if (file.open(QIODevice::ReadOnly)){
        QTextStream stream(&file);
        line.append(stream.readLine());
        page=0;
        text->setText(line);
        QString mock;
        while(! stream.atEnd()){
            mock=stream.readLine();
            TotLine+=1;
        }
    }
    else{
        close();
    }
    file.close();

    h->addWidget(indietro);
    h->addWidget(avanti);
    h->addWidget(menu);

    connect(menu,&QPushButton::clicked,this,&Tutorialwindow::CloseWindow);
    connect(avanti,&QPushButton::clicked,this,&Tutorialwindow::ContinueTutorial);
    connect(indietro,&QPushButton::clicked,this,&Tutorialwindow::GoBackTutorial);
    indietro->setDisabled(true);
}

void Tutorialwindow::CloseWindow(){
    close();
}

void Tutorialwindow::ContinueTutorial(){
    if(page < TotLine){
        page++;
        if(page >= 1){
            indietro->setDisabled(false);
        }
        emit displayTxt(page);
    }
    if(page==TotLine)
        avanti->setDisabled(true);
}

void Tutorialwindow::GoBackTutorial(){
    if(page==1){
        indietro->setDisabled(true);
    }

    if(page>=1){
        page--;
        if(page <= TotLine){
            avanti->setDisabled(false);
        }
        emit displayTxt(page);

    }
}


void Tutorialwindow::displayTxt(int page){
    QString result;
    QFile file(":/readme2.txt");
    if( file.open( QIODevice::ReadOnly | QIODevice::Text ) ) {
       QTextStream in( &file );
       int counter = 0;
       while( ! in.atEnd() ) {
          QString line( in.readLine() );
          if( counter == page ) {
             result = line;
             break;
          }
          counter += 1;
       }
    }
    text->setText(result);
}
