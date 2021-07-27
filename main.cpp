#include <QApplication>
//#include "Controller/Header/initialScreenController.h"
//#include "View/Header/boardwindow.h"

#include "Entities/Header/cvector.h"
#include "Entities/Header/unique_ptr.h"

#include "Model/Header/modelBoard.h"
//prova
#include "Controller/Header/controller.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Controller c;

    return a.exec();

}
