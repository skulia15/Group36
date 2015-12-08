#ifndef CONNECTIONTODATABASE_H
#define CONNECTIONTODATABASE_H
#include "gui.h"
#include "manualInsertScientist.h"
#include "insertcomputer.h"
#include "connectiontodatabase.h"
#include <iostream>
#include <QtSql>
#include <fstream>
#include <string>
#include <vector>
#include <QCoreApplication>
#include <fstream>

class connectionToDataBase{
public:
    connectionToDataBase();
    void connect();
    void disconect();
};

#endif // CONNECTIONTODATABASE_H
