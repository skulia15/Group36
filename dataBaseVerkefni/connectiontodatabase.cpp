#include "connectiontodatabase.h"
#include "gui.h"
#include "manualInsertScientist.h"
#include <QtSql>

connectionToDataBAse::connectionToDataBAse()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "database.sqlite";
    db.setDatabaseName(dbName);

    db.open();

     QSqlQuery query(db);

    if(db.open())
         qDebug()<<"-==== Opnadi a tengingu vid gagnagrunn ====-";
     else
           qDebug()<<"-==== Tokst ekki ad koma a tenginu vid gagnagrunn ====-"<<db.lastError().text();

 string queryCreate ="CREATE TABLE CpuScientist(id INTEGER PRIMARY KEY AUTOINCREMENT, firstname VARCHAR NOT NULL, lastname VARCHAR NOT NULL , yob INTEGER NOT NULL, yod INTEGER NOT NULL); ";


 if(query.exec(QString(queryCreate.c_str()))){
 cout<< "-==== Setti upp toflu ====- "<<endl;}
 else {cout<< "-==== Setti ekki upp nyja toflu ====-"<<endl;}
}


