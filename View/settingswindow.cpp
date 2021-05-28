#include "Header/settingswindow.h"

//test
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

SettingsWindow::SettingsWindow(QWidget*parent): QWidget(parent)
{
    QFile file(":/readme2.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
        close();
    }
    file.close();
}
