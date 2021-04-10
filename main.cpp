#include <QApplication>
#include "Controller/Header/controller.h"
#include "View/Header/finestrainiziale.h"

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
