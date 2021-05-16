#include <QApplication>
//#include "Controller/Header/initialScreenController.h"
//#include "View/Header/boardwindow.h"

#include "Entities/Header/cvector.h"
#include "Entities/Header/unique_ptr.h"

//prova
#include "View/Header/mainwindow.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow c;
    c.show();

    return a.exec();

}
