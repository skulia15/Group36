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
    QSqlDatabase db;
    QSqlQuery query(db);
    display print;

    cout << "Enter the first name you want search for: ";
    cin >> inputName;

    cout << "===== SEARCH RESULTS =====" << endl;

   query.prepare("SELECT * FROM Scientists WHERE lastName = (:name)");
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
}




void Searchdata::searchBirthYear()
{
    QSqlDatabase db;
    QSqlQuery query(db);
    display print;

    cout << "Enter the first name you want search for: ";
    cin >> inputName;

    cout << "===== SEARCH RESULTS =====" << endl;

   query.prepare("SELECT * FROM Scientists WHERE YoB = (:name)");
   query.bindValue(":name",QString::fromStdString(inputName) );
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
}








