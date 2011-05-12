#-------------------------------------------------
#
# Project created by QtCreator 2011-05-11T09:37:51
#
#-------------------------------------------------

QT       += core declarative

TARGET = philosophers
CONFIG   += console warn
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    philosopher.cpp \
    philosopheritem.cpp

HEADERS += \
    philosopher.h \
    philosopheritem.h

OTHER_FILES += \
    app.qml
