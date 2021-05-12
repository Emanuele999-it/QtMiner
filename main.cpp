#include <QApplication>
#include "Controller/Header/initialScreenController.h"
#include "View/Header/boardwindow.h"

#include "Entities/Header/cvector.h"
#include "Entities/Header/unique_ptr.h"

#include "Model/Header/carta/tunnel.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Controller c;
    c.ShowMainWindow();

    return a.exec();

}
