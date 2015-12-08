#include "gui.h"
#include "manualInsertScientist.h"
#include "insertcomputer.h"
#include "connectiontodatabase.h"
#include "display.h"
#include "search.h"
#include <QtSql>
#include <iostream>

display::display(){
}

void display::showResult(){
    //QSqlDatabase db;
   // QSqlQuery query(db);

/*    cout << "=====PRINTING=======" << endl; //Muna að taka út ===printing=== :)
=======
void display::showresult() //Prints out allt Scientists in database
{
    QSqlDatabase db;
    QSqlQuery query(db);

    cout << "=====PRINTING=======" << endl; //Muna að taka út ===printing=== :), Ég kan samt að meta þetta kv. Sverrir
>>>>>>> accad3148ef432184e09da424eaa99fa8c7fd96f
    query.exec("SELECT * FROM Scientists");

    while(query.next()){
        int id = query.value(0).toUInt();
        string firstName = query.value("firstName").toString().toStdString();
        string lastName = query.value("lastName").toString().toStdString();
        string sex = query.value("sex").toString().toStdString();
        int YoB = query.value("YoB").toUInt();
        int YoD = query.value("YoB").toUInt();

        cout << "Id: "<< id << endl
        << "Name: "<< firstName << " " << lastName << endl
        << "Sex: " << sex << endl
        << "Year of Birth: " << YoB << endl
        << "Year of Death: " << YoD << endl;
        cout << endl;

    }cout << "=====End of PRINTING=======" << endl;//Muna að taka út ===printing=== :)Ég kan samt að meta þetta kv. Sverrir*/
    QSqlQuery query("SELECT * FROM Scientists");

    int idName = query.record().indexOf("firstName");
    while (query.next())
    {
       QString firstName = query.value("firstName").toString();
       QString lastName = query.value("lastName").toString();
       QString sex = query.value("sex").toString();
       int YoB = query.value("YoB").toUInt();
       int YoD = query.value("YoB").toUInt();
       qDebug() << firstName << lastName << sex << YoB << YoD;
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


