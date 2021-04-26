#include <QApplication>
#include "Controller/Header/controller.h"
#include "View/Header/finestrainiziale.h"

#include "Entities/Headers/cvector.h"
#include "Entities/Headers/unique_ptr.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //a.add(b);
    //FinestraIniziale b;
    //b.visualizza();
    //a.exec();

    Controller c;
    c.ShowMainWindow();

    return a.exec();

}
