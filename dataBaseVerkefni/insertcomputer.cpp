#include "gui.h"
#include "insertcomputer.h"
#include "connectiontodatabase.h"
#include <QtSql>
#include <iostream>

using namespace std;

Computers::Computers()
{
   cpuName="";
   yearBuilt=0;
   cpuType="";
};

void Computers::insertCPU()
{
        QSqlDatabase db;
        QSqlQuery query(db);

        cout<< "Please enter cpu name, year built and cpu type. \n";
        cin >> cpuName >> yearBuilt >> cpuType;

        query.prepare("INSERT INTO Computers (cpuName, yearBuilt, cpuType) "
                          "VALUES (:cpuName, :yearBuilt, :cpuType)");
        query.bindValue(":cpuName", QString::fromStdString(cpuName));
        query.bindValue(":yearBuilt", yearBuilt);
        query.bindValue(":cpuType",  QString::fromStdString(cpuType));

        if(query.exec()){
            cout<<endl;
            cout<<"-====Tokst ad setja gogn inn i gagnagrunn ====-"<<endl;
            cout <<endl;
                }
        else{
            cout <<endl;
            cout << "-==== Tokst ekki ad setja gogn inn i gagnagrunn ====-"<<endl;
            cout <<endl;}
        }
