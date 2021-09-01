#include "Header/settingswindow.h"

//test
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

#include <QDebug>

SettingsWindow::~SettingsWindow(){
    if(vLayout) delete vLayout;
    if(hLayout) delete hLayout;
    if(slider) delete slider;
    if(lcd) delete lcd;
    if(confirm) delete confirm;
}

SettingsWindow::SettingsWindow(const SettingsWindow &s){
    setWindowTitle ("QtMiner - Impostazioni");
    valore=s.valore;
    setMinimumSize(250,150);

    confirm = s.confirm;

    vLayout = new QVBoxLayout(this);
    hLayout = new QHBoxLayout();

    lcd = s.lcd;
    lcd->setSegmentStyle(QLCDNumber::Flat);
    lcd->display(valore);

    slider = new QSlider(Qt::Horizontal);
    slider->setSingleStep(1);
    slider->setPageStep(1);
    slider->setTickInterval(1);
    slider->setTickPosition(QSlider::TicksAbove);
    slider->setRange(50,52);
    slider->setValue((valore-50)/20+50);

    vLayout->addLayout(hLayout);
    hLayout->addWidget(new QLabel("Dimensioni Board: "));
    QVBoxLayout* v= new QVBoxLayout();
    hLayout->addLayout(v);
    v->addWidget(lcd);
    v->addWidget(slider);

    vLayout->addWidget(confirm);

    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(setDisplayNumber(int)));
    connect(confirm, &QPushButton::clicked, this, &SettingsWindow::emitBoardDimension);
}

SettingsWindow& SettingsWindow::operator =(const SettingsWindow& s){
    if(this != &s){
        delete slider;
        delete lcd;
        delete confirm;

        setWindowTitle ("QtMiner - Impostazioni");
        valore=s.valore;
        setMinimumSize(250,150);

        confirm = s.confirm;

        vLayout = new QVBoxLayout(this);
        hLayout = new QHBoxLayout();

        lcd = s.lcd;
        lcd->setSegmentStyle(QLCDNumber::Flat);
        lcd->display(valore);

        slider = new QSlider(Qt::Horizontal);
        slider->setSingleStep(1);
        slider->setPageStep(1);
        slider->setTickInterval(1);
        slider->setTickPosition(QSlider::TicksAbove);
        slider->setRange(50,52);
        slider->setValue((valore-50)/20+50);

        vLayout->addLayout(hLayout);
        hLayout->addWidget(new QLabel("Dimensioni Board: "));
        QVBoxLayout* v= new QVBoxLayout();
        hLayout->addLayout(v);
        v->addWidget(lcd);
        v->addWidget(slider);

        vLayout->addWidget(confirm);

        connect(slider, SIGNAL(valueChanged(int)), this, SLOT(setDisplayNumber(int)));
        connect(confirm, &QPushButton::clicked, this, &SettingsWindow::emitBoardDimension);
    }
    return *this;
}

SettingsWindow::SettingsWindow(unsigned int i)
{

    setWindowTitle ("QtMiner - Impostazioni");

    valore=i;
    setMinimumSize(250,150);

    confirm = new QPushButton("conferma");

    vLayout = new QVBoxLayout(this);
    hLayout = new QHBoxLayout();

    lcd = new QLCDNumber(2);
    lcd->setSegmentStyle(QLCDNumber::Flat);
    lcd->display(valore);

    slider = new QSlider(Qt::Horizontal);
    slider->setSingleStep(1);
    slider->setPageStep(1);
    slider->setTickInterval(1);
    slider->setTickPosition(QSlider::TicksAbove);
    slider->setRange(50,52);
    slider->setValue((valore-50)/20+50);

    vLayout->addLayout(hLayout);
    hLayout->addWidget(new QLabel("Dimensioni Board: "));
    QVBoxLayout* v= new QVBoxLayout();
    hLayout->addLayout(v);
    v->addWidget(lcd);
    v->addWidget(slider);

    vLayout->addWidget(confirm);

    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(setDisplayNumber(int)));
    connect(confirm, &QPushButton::clicked, this, &SettingsWindow::emitBoardDimension);
}

void SettingsWindow::setDisplayNumber(int i){
    int t=(i-50)*20;
    valore=t+50;
    lcd->display(t+50);
    slider->setValue(i);
}

void SettingsWindow::emitBoardDimension(){
    emit newBoardDimension(valore);
    this->destroy();
}
