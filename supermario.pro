QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    checkpoint.cpp \
    coin.cpp \
    coinspack.cpp \
    game.cpp \
    gamecompletedwindow.cpp \
    gameoverwindow.cpp \
    health.cpp \
    level1.cpp \
    level2.cpp \
    level3.cpp \
    level4.cpp \
    level5.cpp \
    levelclass.cpp \
    levelcompletedwindow.cpp \
    main.cpp \
    platform.cpp \
    player.cpp \
    score.cpp \
    spikes.cpp

HEADERS += \
    checkpoint.h \
    coin.h \
    coinspack.h \
    game.h \
    gamecompletedwindow.h \
    gameoverwindow.h \
    health.h \
    level1.h \
    level2.h \
    level3.h \
    level4.h \
    level5.h \
    levelclass.h \
    levelcompletedwindow.h \
    platform.h \
    player.h \
    score.h \
    spikes.h

FORMS += \
    gamecompletedwindow.ui \
    gameoverwindow.ui \
    levelcompletedwindow.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ImgsResources.qrc \
    mario.qrc
