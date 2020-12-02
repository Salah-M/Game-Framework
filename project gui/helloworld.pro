QT       += widgets \
         multimedia

SOURCES += \
    account.cpp \
    button.cpp \
    game1menu.cpp \
    game1scene.cpp \
    game1score.cpp \
    game2menu.cpp \
    game2scene.cpp \
    globalvar.cpp \
    historywidget.cpp \
    main.cpp \
    mainwidget.cpp \
    piece.cpp \
    signinwidget.cpp \
    signupwidget.cpp \
    vdeath.cpp \
    virus.cpp

HEADERS += \
    account.h \
    button.h \
    game1menu.h \
    game1scene.h \
    game1score.h \
    game2menu.h \
    game2scene.h \
    globalvar.h \
    historywidget.h \
    mainwidget.h \
    piece.h \
    signinwidget.h \
    signupwidget.h \
    vdeath.h \
    virus.h

DISTFILES += \
    level1.txt \
    level2.txt \
    level3.txt

RESOURCES += \
    images.qrc

QMAKE_CXXFLAGS+=-pg
QMAKE_LFLAGS+=-pg
CONFIG += debug
