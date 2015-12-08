QT += core
QT -= gui
QT += sql

TARGET = dataBaseVerkefni
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    gui.cpp \
    connectiontodatabase.cpp \
    manualInsertScientist.cpp \
    display.cpp \
    insertcomputer.cpp \
    search.cpp \
    extras.cpp

HEADERS += \
    gui.h \
    connectiontodatabase.h \
    manualInsertScientist.h \
    display.h \
    insertcomputer.h \
    search.h \
    extras.h

