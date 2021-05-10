QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    View/board.cpp \
    main.cpp \
    Controller/controller.cpp \
    View/mainwindow.cpp \
    View/mainsettingswindow.cpp \
    View/finestrainiziale.cpp \
    Entities/card.cpp \
    Entities/tunnel.cpp \
    Entities/clonecards.cpp \
    Entities/obstruction.cpp \
    Entities/blocco.cpp \
    Entities/crollo.cpp

HEADERS += \
    View/Header/board.h \
    View/Header/finestrainiziale.h \
    Controller/Header/controller.h \
    View/Header/mainwindow.h \
    View/Header/mainsettingswindow.h \
    Entities/Header/cvector.h \
    Entities/Header/unique_ptr.h \
    Entities/Header/card.h \
    Entities/Header/tunnel.h \
    Entities/Header/clonecards.h \
    Entities/Header/obstruction.h \
    Enums/obstructiontype.h \
    Entities/Header/blocco.h \
    Entities/Header/crollo.h





# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
