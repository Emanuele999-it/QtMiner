#include "Header/tutorialwindow.h"

#include <QDebug>

Tutorialwindow::~Tutorialwindow(){
    if(l) delete l;
    if(avanti) delete avanti;
    if(indietro) delete indietro;
    if(menu) delete menu;
    if(text) delete text;
}

Tutorialwindow& Tutorialwindow::operator =(const Tutorialwindow &t){
    if(this != &t){
        delete avanti;
        delete indietro;
        delete menu;
        delete text;

        setWindowTitle ("QtMiner - Tutorial");

        setMinimumSize(350,300);
        setMaximumSize(700,500);

        l= new QVBoxLayout(this);
        icon = t.icon;
        QHBoxLayout *hLay = new QHBoxLayout();
        QHBoxLayout *hButton = new QHBoxLayout();

        text = t.text;
        text->setWordWrap(true);
        l->addLayout(hLay);
        hLay->addWidget(text);
        hLay->addWidget(icon);
        l->addLayout(hButton);

        indietro = new QPushButton(tr("Indietro"));
        avanti = new QPushButton(tr("Avanti"));
        menu = new QPushButton(tr("Finestra principale"));

        hButton->addWidget(indietro);
        hButton->addWidget(avanti);
        hButton->addWidget(menu);

        TotLine=0;
        QFile file(":/tutorial.txt");
        QString line="";
        if (file.open(QIODevice::ReadOnly)){
            QTextStream stream(&file);
            line.append(stream.readLine());
            page=0;
            if(line.contains("<img>")){
                int inizio=line.indexOf("<img>");
                int fine=line.indexOf("</img>");
                QString get = line.mid(inizio,fine);
                line.remove(inizio,fine);
                get.remove("<img>");
                get.remove("</img>");
                QImage* inputImg = new QImage(get);
                icon->setPixmap(QPixmap::fromImage(*inputImg).scaled(100,150));
            }
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

        connect(menu,&QPushButton::clicked,this,&Tutorialwindow::CloseWindow);
        connect(avanti,&QPushButton::clicked,this,&Tutorialwindow::ContinueTutorial);
        connect(indietro,&QPushButton::clicked,this,&Tutorialwindow::GoBackTutorial);

        indietro->setDisabled(true);
    }
    return *this;
}

Tutorialwindow::Tutorialwindow(const Tutorialwindow &t){

    setWindowTitle ("QtMiner - Tutorial");

    setMinimumSize(350,300);
    setMaximumSize(700,500);

    l= new QVBoxLayout(this);
    icon = t.icon;
    QHBoxLayout *hLay = new QHBoxLayout();
    QHBoxLayout *hButton = new QHBoxLayout();

    text = t.text;
    text->setWordWrap(true);
    l->addLayout(hLay);
    hLay->addWidget(text);
    hLay->addWidget(icon);
    l->addLayout(hButton);

    indietro = new QPushButton(tr("Indietro"));
    avanti = new QPushButton(tr("Avanti"));
    menu = new QPushButton(tr("Finestra principale"));

    hButton->addWidget(indietro);
    hButton->addWidget(avanti);
    hButton->addWidget(menu);

    TotLine=0;
    QFile file(":/tutorial.txt");
    QString line="";
    if (file.open(QIODevice::ReadOnly)){
        QTextStream stream(&file);
        line.append(stream.readLine());
        page=0;
        if(line.contains("<img>")){
            int inizio=line.indexOf("<img>");
            int fine=line.indexOf("</img>");
            QString get = line.mid(inizio,fine);
            line.remove(inizio,fine);
            get.remove("<img>");
            get.remove("</img>");
            QImage* inputImg = new QImage(get);
            icon->setPixmap(QPixmap::fromImage(*inputImg).scaled(100,150));
        }
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

    connect(menu,&QPushButton::clicked,this,&Tutorialwindow::CloseWindow);
    connect(avanti,&QPushButton::clicked,this,&Tutorialwindow::ContinueTutorial);
    connect(indietro,&QPushButton::clicked,this,&Tutorialwindow::GoBackTutorial);

    indietro->setDisabled(true);

}

Tutorialwindow::Tutorialwindow()
{

    setWindowTitle ("QtMiner - Tutorial");

    setMinimumSize(350,300);
    setMaximumSize(700,500);

    l= new QVBoxLayout(this);
    icon = new QLabel();
    QHBoxLayout *hLay = new QHBoxLayout();
    QHBoxLayout *hButton = new QHBoxLayout();

    text = new QLabel("");
    text->setWordWrap(true);
    l->addLayout(hLay);
    hLay->addWidget(text);
    hLay->addWidget(icon);
    l->addLayout(hButton);

    indietro = new QPushButton(tr("Indietro"));
    avanti = new QPushButton(tr("Avanti"));
    menu = new QPushButton(tr("Finestra principale"));

    hButton->addWidget(indietro);
    hButton->addWidget(avanti);
    hButton->addWidget(menu);

    TotLine=0;
    QFile file(":/tutorial.txt");
    QString line="";
    if (file.open(QIODevice::ReadOnly)){
        QTextStream stream(&file);
        line.append(stream.readLine());
        page=0;
        if(line.contains("<img>")){
            int inizio=line.indexOf("<img>");
            int fine=line.indexOf("</img>");
            QString get = line.mid(inizio,fine);
            line.remove(inizio,fine);
            get.remove("<img>");
            get.remove("</img>");
            QImage* inputImg = new QImage(get);
            icon->setPixmap(QPixmap::fromImage(*inputImg).scaled(100,150));
            icon->setVisible(true);
        }
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
    QFile file(":/tutorial.txt");
    if( file.open( QIODevice::ReadOnly | QIODevice::Text ) ) {
       QTextStream in( &file );
       int counter = 0;
       while( ! in.atEnd() ) {
          QString line( in.readLine() );
          if( counter == page ) {
              if(line.contains("<img>")){
                  int inizio=line.indexOf("<img>");
                  int fine=line.indexOf("</img>");
                  QString get = line.mid(inizio,fine);
                  line.remove(inizio,fine);
                  get.remove("<img>");
                  get.remove("</img>");
                  QImage* inputImg = new QImage(get);
                  icon->setPixmap(QPixmap::fromImage(*inputImg).scaled(100,150));
                  icon->setVisible(true);
              }
              else
                  icon->setVisible(false);

              result = line;
              break;
          }
          counter += 1;
       }
    }
    text->setText(result);
}

void Tutorialwindow::closeEvent(QCloseEvent *event){
    Q_UNUSED(event)
    emit closeTut();
}
