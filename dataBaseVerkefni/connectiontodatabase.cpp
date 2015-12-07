#include "connectiontodatabase.h"
#include "gui.h"
#include "manualInsertScientist.h"
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

 if(query.exec(QString(queryCreate.c_str()))){
    cout << "========== The Database was made successfully! =========="<< endl;}
 else {cout<< "========== The Database already exists! ==========" << endl;}

}


