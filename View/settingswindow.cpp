#include "Header/settingswindow.h"

//test
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

SettingsWindow::SettingsWindow()
{
    vLayout = new QVBoxLayout(this);
    hLayout = new QHBoxLayout();

    lcd = new QLCDNumber(2);
    slider = new QSlider(Qt::Horizontal);
    slider->setMinimum(40);
    slider->setMaximum(80);

    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(setValue(int)));

    vLayout->addLayout(hLayout);
    hLayout->addWidget(slider);
    hLayout->addWidget(lcd);


}

void QLCDNumber::setValue(int i){
    slider->setValue(i);
}
