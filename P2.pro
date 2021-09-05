QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \	
    Controller/controller.cpp \
    Model/carta/blocco.cpp \
    Model/carta/card.cpp \
    Model/carta/clonecards.cpp \
    Model/carta/crollo.cpp \
    Model/carta/obstruction.cpp \
    Model/carta/tunnel.cpp \
    Model/carta/modelBoard.cpp \
    View/board.cpp \
    View/boardwindow.cpp \
    View/casella.cpp \
    View/mainwindow.cpp \
    View/tutorialwindow.cpp \
    View/settingswindow.cpp \
    main.cpp \ 
    View/lastgamewindow.cpp \
    View/settingsbutton.cpp


HEADERS += \
    Controller/Header/controller.h \
    Entities/Header/cvector.h \
    Entities/Header/unique_ptr.h \	
    Enums/obstructiontype.h \
    Model/Header/modelBoard.h \
    Model/Header/carta/blocco.h \
    Model/Header/carta/card.h \
    Model/Header/carta/clonecards.h \
    Model/Header/carta/crollo.h \
    Model/Header/carta/obstruction.h \
    Model/Header/carta/tunnel.h	\	
    View/Header/screens/gameScreen/Board/casella.h \
    View/Header/screens/gameScreen/Board/board.h \
    View/Header/mainwindow.h \
    View/Header/tutorialwindow.h \
    View/Header/settingswindow.h \
    View/Header/boardwindow.h \
    View/Header/lastgamewindow.h \
    View/Header/settingsbutton.h


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources1.qrc \
    resources2.qrc \
    resources3.qrc \
    resources4.qrc \
    resources5.qrc \
    resources6.qrc
