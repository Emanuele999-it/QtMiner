#include "View/Header/screens/gameScreen/Board/casella.h"

namespace view {

Casella::~Casella(){}

Casella::Casella(const Casella &c){
    pos=c.pos;
    onHover=c.onHover;
    iconStd=c.iconStd;
    def=c.def;
    setIcon(iconStd);
    setIconSize(QSize(40,60));
    setFixedSize(45,65);
    connect(this,&QPushButton::clicked, this, &Casella::supportCasellaCliccata);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

Casella& Casella::operator=(const Casella& c){
    if(this != &c){
        pos=c.pos;
        onHover=c.onHover;
        iconStd=c.iconStd;
        def=c.def;
        setIcon(iconStd);
        setIconSize(QSize(40,60));
        setFixedSize(45,65);
        connect(this,&QPushButton::clicked, this, &Casella::supportCasellaCliccata);
        setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    }
    return *this;
}

Casella::Casella(nat p, QString s, QPushButton*pushbutton):QPushButton(pushbutton), pos(p){

    def=s;
    iconStd=QIcon(":/Img/"+def+".jpg");
    onHover=QIcon(":/Img/"+def+"h.jpg");
    setIcon(iconStd);
    setIconSize(QSize(40,60));
    setFixedSize(45,65);
    connect(this,&QPushButton::clicked, this, &Casella::supportCasellaCliccata);

    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

QString Casella::getDefautImage() const {
    return def;
}

void Casella::cambiaImmagine(QString i){

    // path imagine standard
    iconStd=QIcon(":/Img/"+i+".jpg");

    // path immagine hover
    onHover=QIcon(":/Img/"+i+"h.jpg");
    setIcon(iconStd);

    setIconSize(QSize(40,60));
}

void Casella::supportCasellaCliccata(){

    emit casellaCliccata(pos);
}

void Casella::enterEvent(QEvent *event){
    Q_UNUSED(event)
    setIcon(onHover);
}

void Casella::leaveEvent(QEvent *event){
    Q_UNUSED(event)
    setIcon(iconStd);
}

}
