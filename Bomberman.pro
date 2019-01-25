#-------------------------------------------------
#
# Project created by QtCreator 2017-01-07T12:17:06
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Bomberman
TEMPLATE = app


SOURCES += main.cpp \
    game.cpp \
    player.cpp \
    bomb.cpp \
    crate.cpp \
    playerinfo.cpp \
    thingboard.cpp \
    floor.cpp \
    portal.cpp \
    gunpowder.cpp \
    wall.cpp \
    powerup.cpp

HEADERS  += \
    game.h \
    player.h \
    bomb.h \
    crate.h \
    playerinfo.h \
    thing.h \
    thingboard.h \
    floor.h \
    portal.h \
    gunpowder.h \
    wall.h \
    powerup.h

RESOURCES += \
    res.qrc
