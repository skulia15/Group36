#include "gui.h"
#include "manualInsertScientist.h"
#include "insertcomputer.h"
#include "connectiontodatabase.h"
#include "search.h"
#include "display.h"
#include <QtSql>
#include <iostream>

Searchdata::Searchdata(){
    firstName = "";
    lastName = "";
    sex = "";
    YoB = 0;
    YoD = 0;
}

void Searchdata::searchFirstName(){
    QSqlDatabase db;
    QSqlQuery query(db);
    display print;

    cout << "Enter the first name you want search for: ";
    cin >> inputName;

    cout << "===== SEARCH RESULTS =====" << endl;

   query.prepare("SELECT * FROM Scientists WHERE firstName = (:name)");
   query.bindValue(":name", QString::fromStdString(inputName));
   query.exec();
   while (query.next())
   {
      int id = query.value("id").toUInt();
      QString firstName = query.value("firstName").toString();
      QString lastName = query.value("lastName").toString();
      QString sex = query.value("sex").toString();
      int YoB = query.value("YoB").toUInt();
      int YoD = query.value("YoD").toUInt();

      cout << "Scientist ID: ";
      qDebug() << id;
      cout << "Name: ";
      qDebug() << qPrintable(firstName)  << qPrintable(lastName) ;
      cout << "Sex: ";
      qDebug() << qPrintable(sex);
      cout << "Year of Birth: ";
      qDebug() << YoB;
      cout << "Year of Death: ";
      if (YoD == 0){
          cout << "Still Alive" << endl;
      }
      else{
          qDebug() << YoD;
      }
      cout << endl;
   }













   cout << "===== END OF RESULTS =====" << endl;

   /* if(!query.exec()){
        qDebug() << "Search failed: " << query.lastError();
    }
    else{
        qDebug() << "Search failed: Person doesn't exist.";
    }*/
}

void Searchdata::searchLastName()
{
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

void Searchdata::searchBirthYear(){
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
