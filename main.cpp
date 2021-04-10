#include "View/Header/finestrainiziale.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //a.add(b);
    FinestraIniziale b;
    b.visualizza();
    a.exec();
}
