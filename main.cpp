#include <QApplication>
//#include "Controller/Header/initialScreenController.h"
//#include "View/Header/boardwindow.h"

#include "Entities/Header/cvector.h"
#include "Entities/Header/unique_ptr.h"
#include "Controller/Header/controller.h"
#include <QApplication>
#include <cstdlib>

//test



int main(int argc, char *argv[])
{
    srand(time(0));

    QApplication a(argc, argv);

    Controller c;

    return a.exec();

}
