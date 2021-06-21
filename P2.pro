QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Model/carta/modelBoard.cpp \
    View/board.cpp \
    View/casella.cpp \
    View/gameScene.cpp \
    main.cpp \
    Controller/controller.cpp \
    Model/carta/blocco.cpp \
    Model/carta/card.cpp \
    Model/carta/clonecards.cpp \
    Model/carta/crollo.cpp \
    Model/carta/obstruction.cpp \
    Model/carta/tunnel.cpp \
    View/mainwindow.cpp \
    View/mainsettingswindow.cpp \
    Model/carta/blocco.cpp \
    Model/carta/card.cpp \
    Model/carta/clonecards.cpp \
    Model/carta/crollo.cpp \
    Model/carta/obstruction.cpp \
    Model/carta/tunnel.cpp \
    View/tutorialwindow.cpp \
    View/settingswindow.cpp



HEADERS += \
<<<<<<< HEAD
    Entities/Header/cvector.h \
    Entities/Header/unique_ptr.h \
    Model/Header/modelBoard.h \
    View/Header/screens/gameScreen/Board/casella.h \
    View/Header/screens/gameScreen/mano.h \
    Controller/Header/scenes.h \
=======
    Model/Header/modelBoard.h \
    View/Header/screens/gameScreen/Board/casella.h \
    View/Header/screens/gameScreen/mano.h \
>>>>>>> ale
    Controller/Header/controller.h \
    View/Header/hud/iconButton.h \
    View/Header/mainwindow.h \
    View/Header/mainsettingswindow.h \
<<<<<<< HEAD
=======
    Entities/Header/cvector.h \
    Entities/Header/unique_ptr.h \
>>>>>>> ale
    View/Header/hud/infoBox.h \
    View/Header/screens/gameScreen/Board/board.h \
    View/Header/screens/gameScreen/Modal/gameOver.h \
    View/Header/screens/gameScreen/Modal/pause.h \
    View/Header/screens/gameScreen/gameScene.h \
    View/Header/screens/initialScreen/initialScreen.h \
    View/Header/screens/boardScreen/mapScreen.h \
    View/Header/screens/boardScreen/setBoard.h \
    View/Header/screens/tutorial/scene.h \
    View/Header/screens/tutorial/content.h \
    Model/Header/game.h \
    Model/Header/carta/blocco.h \
    Model/Header/carta/card.h \
    Model/Header/carta/clonecards.h \
    Model/Header/carta/crollo.h \
    Model/Header/carta/obstruction.h \
    Model/Header/carta/tunnel.h
<<<<<<< HEAD
    Enums/obstructiontype.h \
    View/Header/settingswindow.h \
    Entities/Header/cvector.h \
    Entities/Header/unique_ptr.h \
    Model/Header/carta/blocco.h \
    Model/Header/carta/card.h \
    Model/Header/carta/clonecards.h \
    Model/Header/carta/crollo.h \
    Model/Header/carta/obstruction.h \
    Model/Header/carta/tunnel.h \
    View/Header/mainwindow.h \
    View/Header/tutorialwindow.h
=======
>>>>>>> ale


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
