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
         qDebug()<<"========== Opened the Database ==========" << endl;
    else
         qDebug()<<"========== Error: "<<db.lastError().text() << " ==========" << endl;

 string queryCreate ="CREATE TABLE students(id INTEGER, name VARCHAR, email VARCHAR, age INTEGER); ";
 if(query.exec(QString(queryCreate.c_str()))){
    cout << "========== The Database was made successfully! =========="<< endl;}
 else {cout<< "========== The Database already exists! ==========" << endl;}
}

