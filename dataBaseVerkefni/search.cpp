#include "connectiontodatabase.h"

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
    display print;

    cout << "Enter the first name you want to search for: ";
    cin >> inputName;

    cout << "===== SEARCH RESULTS =====" << endl;

   query.prepare("SELECT * FROM Scientists WHERE firstName LIKE (:name)");
   query.bindValue(":name", QString::fromStdString(inputName));
   query.exec();
   while (query.next()){
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

void searchData::searchLastName()
{
    QSqlDatabase db;
    QSqlQuery query(db);
    display print;

<<<<<<< HEAD
    cout << "Enter the last name you want to search for: ";
=======
    cout << "Enter the last name you want search for: ";
>>>>>>> bce005b2e8d1b72f337f0424b4f70f302bbd74d2
    cin >> inputName;

    cout << "===== SEARCH RESULTS =====" << endl;

   query.prepare("SELECT * FROM Scientists WHERE lastName LIKE (:name)");
   query.bindValue(":name", QString::fromStdString(inputName));
   query.exec();
   while (query.next()){
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

void searchData::searchBirthYear(){

    QSqlDatabase db;
    QSqlQuery query(db);
    display print;

<<<<<<< HEAD
    cout << "Enter the birth year you want to search for: ";
=======
    cout << "Enter the birth year you want search for: ";
>>>>>>> bce005b2e8d1b72f337f0424b4f70f302bbd74d2
    cin >> inputName;

    cout << "===== SEARCH RESULTS =====" << endl;

   query.prepare("SELECT * FROM Scientists WHERE YoB = (:name)");
   query.bindValue(":name",QString::fromStdString(inputName) );
   query.exec();
   while (query.next()){
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

void Searchdata::substring()
{


}






