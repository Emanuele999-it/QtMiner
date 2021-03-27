#include <QApplication>
#include "View/Header/controller.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Controller c;
    c.ShowMainWindow();

    a.exec();
}
