#include "connectiontodatabase.h"
#include "gui.h"
#include "manualInsertScientist.h"
#include <QtSql>

connectionToDataBase::connectionToDataBase()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "student_db.sqlite";
    db.setDatabaseName(dbName);

    db.open();

     QSqlQuery query(db);

    if(db.open())
         qDebug() << "Database was opened" << endl;
    else
         qDebug()<<"Database was closed" << db.lastError().text();

    string queryCreate = "CREATE TABLE Scientists(id INTEGER PRIMARY KEY AUTOINCREMENT, firstName VARCHAR NOT NULL, lastName VARCHAR NOT NULL, sex VARCHAR, YoB INTEGER, YoD INTEGER); ";
    if(query.exec(QString(queryCreate.c_str()))){
        cout << "The Database was made successfully "<< endl;}
    else {
        cout<< "A new Database was NOT made " << endl;}
}

