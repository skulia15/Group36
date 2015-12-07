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
         qDebug()<<"-==== We have been connected to the database ====-" << endl;}
    else{
         qDebug()<<"-==== Unable to connect ot the database ====-" << db.lastError().text() << " ==========" << endl;}

 string queryCreate = "CREATE TABLE Scientists(id INTEGER PRIMARY KEY AUTOINCREMENT, firstName VARCHAR NOT NULL, lastName VARCHAR NOT NULL, sex VARCHAR, YoB INTEGER NOT NULL, YoD INTEGER); ";
 string queryCreate2 ="CREATE TABLE Computers(cpuName VARCHAR NOT NULL, yearBuilt INTEGER NOT NULL, cpuType INTEGER NOT NULL); ";

 if(query.exec(QString(queryCreate.c_str()))){
    cout << "========== The scientist table was made successfully! =========="<< endl;}
 else {cout<< "========== Scientist table enabled! ==========" << endl;}

 if(query.exec(QString(queryCreate2.c_str()))){
     cout << "========= The computer table was made successfully!"<<endl;}
  else{cout << "========= Computer table enabled! ========="<<endl<<endl;}

}


