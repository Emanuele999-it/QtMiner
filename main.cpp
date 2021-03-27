#include <QApplication>
#include "Controller/Header/controller.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Controller c;
    c.ShowMainWindow();

    return a.exec();
}
