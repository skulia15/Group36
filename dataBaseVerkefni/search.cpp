#include "gui.h"
#include "manualInsertScientist.h"
#include "insertcomputer.h"
#include "connectiontodatabase.h"
#include "search.h"
#include "display.h"
#include <QtSql>
#include <iostream>

searchData::searchData(){
    firstName = "";
    lastName = "";
    sex = "";
    YoB = 0;
    YoD = 0;
}

void searchData::searchFirstName(){
    QSqlDatabase db;
    QSqlQuery query(db);
    string inputName;
    cout << "You are in the right place" << endl;
    cout << "Enter a name to search: ";
    cin >> inputName;

    query.prepare("SELECT * FROM Scientists WHERE firstName = (:name)");
    query.bindValue(":name", QString::fromStdString(inputName));
    query.exec();

    if(!query.exec()){
        qDebug() << "Search failed: " << query.lastError();
    }
    else{
        qDebug() << "Search failed: Person doesn't exist.";
    }
    cout << "You are now leaving the right place" << endl;
}

void searchData::searchLastName(){
    display print;
    QSqlDatabase db;
    QSqlQuery query(db);

    cout << "Enter the last name you want search for: ";
    cin >> inputName;

    cout << "===== SEARCH RESULTS =====" << endl;
    query.prepare("SELECT * FROM Scientists WHERE lastName = (:inputName)");
    query.bindValue(":firstName", QString::fromStdString(inputName));

    print.showResult("SELECT * FROM Scientists WHERE lastName = (:inputName)");
        cout << "===== END OF RESULTS =====" << endl;

    if(!query.exec()){
        qDebug() << "Search failed: " << query.lastError();
    }

    else{
        qDebug() << "Search failed: Person doesn't exist.";
    }


}

void searchData::searchBirthYear(){
    QSqlDatabase db;
    QSqlQuery query(db);

    cout << "Enter the birth year you want search for: ";
    cin >> inputYear;

    cout << "===== SEARCH RESULTS =====" << endl;
    query.prepare("SELECT * FROM Scientists WHERE YoB = (:inputYear)");
    query.bindValue(":YoB", QString::fromStdString(inputYear));

    if(query.exec()){
        while(query.next()){
            int id = query.value(0).toUInt();
            string firstName = query.value("firstName").toString().toStdString();
            string lastName = query.value("lastName").toString().toStdString();
            string sex = query.value("sex").toString().toStdString();
            int YoB = query.value("YoB").toUInt();
            int YoD = query.value("YoB").toUInt();

            cout << "Id: " << id << endl
            << "Name: " << firstName << " " << lastName << endl
            << "Sex: " << sex << endl
            << "Year of Birth: " << YoB << endl
            << "Year of Death: " << YoD << endl;
            cout << endl;
        }
        cout << "===== END OF RESULTS =====" << endl;

        if(!query.exec()){
            qDebug() << "Search failed: " << query.lastError();
        }
    }
    else{
        qDebug() << "Search failed: Person doesn't exist.";
    }


}
