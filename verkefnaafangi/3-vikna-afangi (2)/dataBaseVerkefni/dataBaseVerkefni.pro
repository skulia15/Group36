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
    manualInsertScientist.cpp

HEADERS += \
    gui.h \
    connectiontodatabase.h \
    manualInsertScientist.h

