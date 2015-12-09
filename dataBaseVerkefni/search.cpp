#include "connectiontodatabase.h"

searchData::searchData(){
    firstName = "";
    lastName = "";
    sex = "";
    YoB = 0;
    YoD = 0;
}

void searchData::searchFirstName(){ //searches table 'Scientists' for first name.
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

    if(!query.exec())
        qDebug() << "Search failed: " << query.lastError();
    else
        qDebug() << "Search failed: Person doesn't exist.";
}

void searchData::searchLastName() //searches table 'Scientists' for last name.
{
    QSqlDatabase db;
    QSqlQuery query(db);
    display print;


    cout << "Enter the last name you want to search for: ";

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

    if(!query.exec())
        qDebug() << "Search failed: " << query.lastError();
    else
        qDebug() << "Search failed: Person doesn't exist.";
}

void searchData::searchBirthYear(){ //searches table 'Scientists' for birthyear.

    QSqlDatabase db;
    QSqlQuery query(db);
    display print;

    cout << "Enter the birth year you want to search for: ";

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

    if(!query.exec())
        qDebug() << "Search failed: " << query.lastError();
    else
        qDebug() << "Search failed: Person doesn't exist.";
}

void searchData::searchCpuName(){ //searches table 'Computers' for name.
    QSqlDatabase db;
    QSqlQuery query(db);
    display print;


    cout << "Enter name of the computer you want to search for: ";
    cin >> inputName;

    cout << "===== SEARCH RESULTS =====" << endl;

   query.prepare("SELECT * FROM Computers WHERE cpuName = (:name)");
   query.bindValue(":name",QString::fromStdString(inputName) );
   query.exec();
   while (query.next()){

      int id = query.value("id").toUInt();
      QString cpuName = query.value("cpuName").toString();
      QString cpuType = query.value("cpuType").toString();
      QString built = query.value("built").toString();
      int yb = query.value("yearBuilt").toUInt();

      cout << "Computer ID: ";
      qDebug() << id;
      cout << "Name: ";
      qDebug() << qPrintable(cpuName);
      cout << "Type: ";
      qDebug() << qPrintable(cpuType);
      cout << "Was it buit?: ";
      qDebug() << qPrintable(built);
      cout << "Year Built: ";
      qDebug() << yb;
      cout << endl;
    }
    cout << "===== END OF RESULTS =====" << endl;

    if(!query.exec())
        qDebug() << "Search failed: " << query.lastError();
    else
        qDebug() << "Search failed: Computer doesn't exist.";
}

void searchData::searchYearBuilt(){ //searches table 'Computers' for year built.
    QSqlDatabase db;
    QSqlQuery query(db);
    display print;


    cout << "Enter the year you want to search for: ";
    cin >> inputName;

    cout << "===== SEARCH RESULTS =====" << endl;

   query.prepare("SELECT * FROM Computers WHERE yearBuilt = (:name)");
   query.bindValue(":name",QString::fromStdString(inputName) );
   query.exec();
   while (query.next()){

      int id = query.value("id").toUInt();
      QString cpuName = query.value("cpuName").toString();
      QString cpuType = query.value("cpuType").toString();
      QString built = query.value("built").toString();
      int yb = query.value("yearBuilt").toUInt();

      cout << "Computer ID: ";
      qDebug() << id;
      cout << "Name: ";
      qDebug() << qPrintable(cpuName);
      cout << "Type: ";
      qDebug() << qPrintable(cpuType);
      cout << "Was it buit?: ";
      qDebug() << qPrintable(built);
      cout << "Year Built: ";
      qDebug() << yb;
      cout << endl;
    }
    cout << "===== END OF RESULTS =====" << endl;

   if(!query.exec())
       qDebug() << "Search failed: " << query.lastError();
   else
       qDebug() << "Search failed: Person doesn't exist.";
}

void searchData::searchCpuType(){ //searches table 'Computers' for computer type.
    QSqlDatabase db;
    QSqlQuery query(db);
    display print;


    cout << "Enter the type of computer you want to search for: ";
    cin >> inputName;

    cout << "===== SEARCH RESULTS =====" << endl;

   query.prepare("SELECT * FROM Computers WHERE cpuType = (:name)");
   query.bindValue(":name",QString::fromStdString(inputName) );
   query.exec();
   while (query.next()){

      int id = query.value("id").toUInt();
      QString cpuName = query.value("cpuName").toString();
      QString cpuType = query.value("cpuType").toString();
      QString built = query.value("built").toString();
      int yb = query.value("yearBuilt").toUInt();

      cout << "Computer ID: ";
      qDebug() << id;
      cout << "Name: ";
      qDebug() << qPrintable(cpuName);
      cout << "Type: ";
      qDebug() << qPrintable(cpuType);
      cout << "Was it buit?: ";
      qDebug() << qPrintable(built);
      cout << "Year Built: ";
      qDebug() << yb;
      cout << endl;
    }
    cout << "===== END OF RESULTS =====" << endl;

   if(!query.exec())
       qDebug() << "Search failed: " << query.lastError();
   else
       qDebug() << "Search failed: Person doesn't exist.";
}
void searchData::searchKeyword(){ //searches the database for a keyword

    QSqlDatabase db;
    QSqlQuery query(db);
    string keyWord;

    cout << "Enter the keyword you want to search for: ";
    cin >> keyWord;

    cout << "===== SEARCH RESULTS =====" << endl;

   query.prepare("SELECT * FROM Scientists WHERE firstname LIKE (:name) OR lastName LIKE (:name) OR sex LIKE (:name) OR YoB LIKE (:name)OR YoB LIKE (:name) ");
   //það þarf að bæta við þetta að leita líka í computers eftir að það hefur verið gert join!

   query.bindValue(":name",QString::fromStdString(keyWord) );
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




