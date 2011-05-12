#-------------------------------------------------
#
# Project created by QtCreator 2011-05-11T09:37:51
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = philosophers
CONFIG   += console warn
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    philosopher.cpp \
    starvingdiner.cpp \
    starvingphilosopher.cpp

HEADERS += \
    philosopher.h \
    starvingdiner.h \
    starvingphilosopher.h
