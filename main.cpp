﻿#include <QApplication>
#include "Controller/Header/controller.h"
#include "View/Header/boardwindow.h"

#include "Entities/Header/cvector.h"
#include "Entities/Header/unique_ptr.h"

#include "Entities/Header/tunnel.h"
#include "Entities/Header/blocco.h"
#include "Entities/Header/crollo.h"
#include "Enums/obstructiontype.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Controller c;
    c.ShowMainWindow();

    return a.exec();

}
