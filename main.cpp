#include "View/Header/finestrainiziale.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    FinestraIniziale b;
    //a.add(b);
    b.visualizza();
    a.exec();
}
