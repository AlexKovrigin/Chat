#-------------------------------------------------
#
# Project created by QtCreator 2017-08-31T19:34:43
#
#-------------------------------------------------

QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chatServer
TEMPLATE = app

SOURCES += main.cpp\
        chatserver.cpp

HEADERS  += chatserver.h

FORMS    += chatserver.ui

RESOURCES += \
    resource.qrc
