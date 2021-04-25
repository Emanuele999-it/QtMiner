#include <QApplication>
#include "Controller/Header/controller.h"

#include "Entities/Headers/cvector.h"
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
