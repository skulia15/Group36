#include "gui.h"
#include "manualInsertScientist.h"
#include "connectiontodatabase.h"
#include <QtSql>
#include <iostream>
using namespace std;

Scientists::Scientists()
{
   firstName="";
   lastName="";
   yob=0;
   yod=0;
};

void Scientists::manualInput()
{
        QSqlDatabase db;
        QSqlQuery query(db);

        cout<< "Please enter First Name, Last Name, YoB and YoD \n";
        cin >> firstName>> lastName>> yob >>yod;

        query.prepare("INSERT INTO CpuSCientist (firstname, lastname, yob, yod) "
                          "VALUES (:firstname, :lastname, :yob, :yod)");
        query.bindValue(":firstname", QString::fromStdString(firstName));
        query.bindValue(":lastname",  QString::fromStdString(lastName));
        query.bindValue(":yob", yob);
        query.bindValue(":yod", yod);

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


