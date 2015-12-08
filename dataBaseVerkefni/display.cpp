#include "gui.h"
#include "manualInsertScientist.h"
#include "insertcomputer.h"
#include "connectiontodatabase.h"
#include "display.h"
#include "search.h"
#include <QtSql>
#include <iostream>

#include <string>
using namespace std;

display::display(){
}

void display::showResult(string command){
    QSqlDatabase db;
    QSqlQuery query(db);


        //string querySort = "SELECT * FROM Scientists ORDER BY firstName ASC; ";


        //string querySort = "SELECT * FROM Scientists ORDER BY firstName DESC; ";


    string querySort = command;
    if(query.exec(QString(querySort.c_str()))){
       cout << "========== The scientist table sorted successfully! =========="<< endl;}
    else {cout<< "========== Scientist table was NOT sorted :( ==========" << endl;}

   // if (choice == 1){
   // string querySort = "SELECT * FROM Scientists ORDER BY firstName ASC; ";}

    int idName = query.record().indexOf("firstName");
    while (query.next())
    {
       QString firstName = query.value("firstName").toString();
       QString lastName = query.value("lastName").toString();
       QString sex = query.value("sex").toString();
       int YoB = query.value("YoB").toUInt();
       int YoD = query.value("YoD").toUInt();

       cout << "Name: ";
       qDebug() << qPrintable(firstName)  << qPrintable(lastName) ;
       cout << "Sex: ";
       qDebug() << qPrintable(sex);
       cout << "Year of Birth: ";
       qDebug() << YoB;
       cout << "Year of Death: ";
       qDebug() << YoD;
       cout << endl;
    }
}



void display::cpuShowResult(){// þarf kanski að finna betri texta
    QSqlDatabase db;
    QSqlQuery query(db);

    cout << "=====PRINTING=======" << endl;
    query.exec("SELECT * FROM Computers");
    while(query.next()){
    //qDebug()<< query.lastQuery();
        int id = query.value(0).toUInt();
        string cpuName = query.value("cpuName").toString().toStdString();
        string cpuType = query.value("cpuType").toString().toStdString();
        int yb = query.value("yearBuilt").toUInt();
        string built = query.value("built").toString().toStdString();

        cout << "Id: "<< id << endl
        << "Computer name: "<< cpuName << endl
        << "Computer type: " << cpuType << endl
        << "Was built: " << yb << endl
        << "Finished: " << built << endl;
        cout<<endl;
    }
    cout << "=====End of PRINTING=======" << endl;
}


