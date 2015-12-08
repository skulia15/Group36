#include "connectiontodatabase.h"


connectionToDataBase::connectionToDataBase(){
}


void connectionToDataBase::connect()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "Scientists.sqlite";
    db.setDatabaseName("dbName");

    db.open();

    QSqlQuery query(db);

    if(db.open()){
         qDebug()<<"-==== We have been connected to the database ====-" << endl;}
    else{
         qDebug()<<"-==== Unable to connect ot the database ====-" << db.lastError().text() << " ==========" << endl;}

 string queryCreate = "CREATE TABLE Scientists(id INTEGER PRIMARY KEY AUTOINCREMENT, firstName VARCHAR NOT NULL, lastName VARCHAR NOT NULL, sex VARCHAR, YoB INTEGER NOT NULL, YoD INTEGER); ";
 string queryCreate2 ="CREATE TABLE Computers(id INTEGER PRIMARY KEY AUTOINCREMENT, cpuName VARCHAR NOT NULL, built VARCHAR NOT NULL, yearBuilt INTEGER NOT NULL, cpuType VARCHAR NOT NULL); ";
 string queryCreate3 = "CREATE TABLE Links(sci_id INTEGER,cpu_id INTEGER,FOREIGN KEY (sci_id) REFERENCES Scientists(id),FOREIGN KEY (cpu_id) REFERENCES Computers(id)PRIMARY KEY (sci_id, cpu_id));";


 //string queryCreate = "CREATE TABLE Students(id INTEGER PRIMARY KEY AUTOINCREMENT,name VARCHAR NOT NULL);";
 //string queryCreate2 = "CREATE TABLE Classes(id INTEGER PRIMARY KEY AUTOINCREMENT,name VARCHAR NOT NULL);";
 //string queryCreate3 = "CREATE TABLE StudentsInClasses(class_id INTEGER,student_id INTEGER,FOREIGN KEY (class_id) REFERENCES Classes(id),FOREIGN KEY (student_id) REFERENCES Students(id)PRIMARY KEY (class_id, student_id));";







 if(query.exec(QString(queryCreate.c_str()))){
    cout << "========== The scientist table was made successfully! =========="<< endl;}
 else {cout<< "========== Scientist table enabled! ==========" << endl;}

 if(query.exec(QString(queryCreate2.c_str()))){
     cout << "========= The computer table was made successfully! ========="<<endl;}
  else{cout << "========= Computer table enabled! ========="<<endl;}

 if(query.exec(QString(queryCreate3.c_str()))){
     cout << "========= The Combine table was created! ========="<<endl;}
  else{cout << "========= Combine table enabled! ========="<<endl<<endl;}


}

void connectionToDataBase::disconect()
{
    QSqlDatabase db;
    QSqlQuery query(db);
    db.close();
}
