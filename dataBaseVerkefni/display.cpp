#include "gui.h"
#include "manualInsertScientist.h"
#include "connectiontodatabase.h"
#include "display.h"
#include "gui.h"
#include <QtSql>
#include <iostream>

display::display()
{

}

void display::showresult()
{
    QSqlDatabase db;
    QSqlQuery query(db);

    query.exec("SELECT * FROM CpuSCientist");
    while(query.next()){
   // qDebug()<< query.lastQuery();
    int id = query.value(0).toUInt();
    string firstname = query.value("firstname").toString().toStdString();
    string lastname = query.value("lastname").toString().toStdString();
    int yob = query.value("yob").toUInt();
    int yod = query.value("yod").toUInt();

    cout <<id<<" "<<firstname<<" "<<lastname<<" "<<yob<<" "<<yod<<endl;

}
}
