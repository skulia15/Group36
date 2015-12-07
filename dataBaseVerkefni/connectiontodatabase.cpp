#include "connectiontodatabase.h"
#include "gui.h"
#include "manualInsertScientist.h"
#include "insertcomputer.h"
#include <QtSql>

connectionToDataBase::connectionToDataBase()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "Scientists.sqlite";
    db.setDatabaseName(dbName);

    db.open();

    QSqlQuery query(db);

    if(db.open()){
         qDebug()<<"-==== Opnadi a tengingu vid gagnagrunn ====-" << endl;}
    else{
         qDebug()<<"-==== Tokst ekki ad koma a tenginu vid gagnagrunn ====-" << db.lastError().text() << " ==========" << endl;}

 string queryCreate = "CREATE TABLE Scientists(id INTEGER PRIMARY KEY AUTOINCREMENT, firstName VARCHAR NOT NULL, lastName VARCHAR NOT NULL, sex VARCHAR, YoB INTEGER NOT NULL, YoD INTEGER); ";
 string queryCreate2 ="CREATE TABLE Computers(cpuName VARCHAR NOT NULL, yearBuilt INTEGER NOT NULL, cpuType INTEGER NOT NULL); ";

 if(query.exec(QString(queryCreate.c_str()))){
    cout << "========== The scientist table was made successfully! =========="<< endl;}
 else {cout<< "========== The table already exists! ==========" << endl;}

 if(query.exec(QString(queryCreate2.c_str()))){
     cout << "========= The computer table was made successfully!"
 }
 else{
     cout << "========= The table already exists! ========="
 }
}


