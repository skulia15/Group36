#include "connectiontodatabase.h"
#include "gui.h"
#include "manualInsertScientist.h"
#include <QtSql>

connectionToDataBAse::connectionToDataBAse()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "student_db.sqlite";
    db.setDatabaseName(dbName);

    db.open();

     QSqlQuery query(db);

    if(db.open())
         qDebug()<<"opnadi DB";
     else
           qDebug()<<"Close"<<db.lastError().text();

 string queryCreate ="CREATE TABLE students(id INTEGER, name VARCHAR, email VARCHAR, age INTEGER); ";
 if(query.exec(QString(queryCreate.c_str()))){
 cout<< "Bjo til DB"<<endl;}
 else {cout<< "Bjo ekki til nyjan DB"<<endl;}
}

