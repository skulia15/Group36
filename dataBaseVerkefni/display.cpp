#include "gui.h"
#include "manualInsertScientist.h"
#include "connectiontodatabase.h"
#include "display.h"
#include "gui.h"
#include <QtSql>
#include <iostream>

display::display(){
}

void display::showresult()
{
    QSqlDatabase db;
    QSqlQuery query(db);

    cout << "=====PRINTING=======" << endl;
    query.exec("SELECT * FROM Scientist");
    //while(query.next()){
   // qDebug()<< query.lastQuery();
        int id = query.value("id").toUInt();
        string firstName = query.value("firstName").toString().toStdString();
        string lastName = query.value("lastName").toString().toStdString();
        string sex = query.value("sex").toString().toStdString();
        int YoB = query.value("YoB").toUInt();
        int YoD = query.value("YoB").toUInt();

        cout << "Id: "<< id << endl
        << "Name:  "<< firstName << " " << lastName << endl
        << "Sex: " << sex << endl
        << "Year of Birth: " << YoB << endl
        << "Year of Death: " << YoD << endl;
    //}
    cout << "=====End of PRINTING=======" << endl;
}
