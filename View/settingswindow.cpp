﻿#include "Header/settingswindow.h"

//test
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

#include <QDebug>


SettingsWindow::SettingsWindow(unsigned int i)
{

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
    slider->setRange(40,44);
    slider->setValue((i-40)/10+40);
    //correggere

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
    int t=(i-40)*10;
    valore=t+40;
    lcd->display(t+40);
    slider->setValue(i);
}

void SettingsWindow::emitBoardDimension(){
    emit newBoardDimension(valore);
    this->destroy();
}
