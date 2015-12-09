#ifndef CONNECTIONTODATABASE_H
#define CONNECTIONTODATABASE_H
#include "gui.h"
#include "manualInsertScientist.h"
#include "insertcomputer.h"
#include "connectiontodatabase.h"
#include "extras.h"
#include "display.h"
#include <iostream>
#include <QtSql>
#include <fstream>
#include <string>
#include <vector>
#include "search.h"
#include <QCoreApplication>
#include <fstream>
#include <windows.h>
#include <cctype>

using namespace std;

class connectionToDataBase{
public:
    connectionToDataBase();
    void connect();
    void disconect();
};

#endif // CONNECTIONTODATABASE_H
