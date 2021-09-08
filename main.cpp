#include <QApplication>

#include "Entities/Header/cvector.h"
#include "Entities/Header/unique_ptr.h"
#include "Controller/Header/controller.h"
#include <QApplication>
#include <cstdlib>



int main(int argc, char *argv[])
{
    srand(time(0));

    QApplication a(argc, argv);

    Controller c;

    return a.exec();

}
