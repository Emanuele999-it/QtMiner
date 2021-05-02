#include <QApplication>
#include "Controller/Header/controller.h"

#include "Entities/Header/cvector.h"
#include "Entities/Header/unique_ptr.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Controller c;
    c.ShowMainWindow();

    return a.exec();

}














