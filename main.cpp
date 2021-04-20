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

    CVector<char> v(33);
    //for(int i=0;i<33;i++)
    //{cout<<v[i]<<" ";}

    Controller c;
    c.ShowMainWindow();

    return a.exec();
}
