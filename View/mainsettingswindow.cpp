#include "Header/mainsettingswindow.h"

//test
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

MainSettingsWindow::MainSettingsWindow(QWidget*parent): QWidget(parent)
{
    QFile file("readme2.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }
    file.close();
}
