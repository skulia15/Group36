#-------------------------------------------------
#
# Project created by QtCreator 2015-12-11T18:41:16
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Group36W3
TEMPLATE = app
CONFIG += C++11
RC_FILE = myapp.rc \
          myapp2.rc
SOURCES += main.cpp\
        mainwindow.cpp \
    models/computer.cpp \
    models/scientist.cpp \
    repositories/computerrepository.cpp \
    repositories/linkrepository.cpp \
    repositories/scientistrepository.cpp \
    services/computerservice.cpp \
    services/linkservice.cpp \
    services/scientistservice.cpp \
    ui/consoleui.cpp \
    utilities/utils.cpp \
    ui/addscientistdialog.cpp \
    ui/addcomputerdialog.cpp \
    ui/relations.cpp

HEADERS  += mainwindow.h \
    models/computer.h \
    models/scientist.h \
    repositories/computerrepository.h \
    repositories/linkrepository.h \
    repositories/scientistrepository.h \
    services/computerservice.h \
    services/linkservice.h \
    services/scientistservice.h \
    ui/consoleui.h \
    utilities/constants.h \
    utilities/utils.h \
    ui/addscientistdialog.h \
    ui/addcomputerdialog.h \
    ui/relations.h

FORMS    += mainwindow.ui \
    ui/addscientistdialog.ui \
    ui/addcomputerdialog.ui \
    ui/relations.ui

INCLUDEPATH += models \
    ui

DISTFILES += \
    myapp.rc \
    myapp2.rc
