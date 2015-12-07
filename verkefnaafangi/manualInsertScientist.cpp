#include "gui.h"
#include "manualInsertScientist.h"
#include "connectiontodatabase.h"
#include <QtSql>
#include <iostream>
using namespace std;

Scientists::Scientists(){
   firstName = "";
   lastName = "";
   sex = "";
   YoB = "";
   YoD = "";
};

void Scientists::manualInput(){

    QSqlDatabase db;
    QSqlQuery query(db);

    string queryPrint = "SELECT * FROM Scientists";
    query.exec(QString(queryPrint.c_str()));

    cout << "Please enter the computer scientists information." << endl;
    cout << "First name: ";
    cin >> firstName;
    cout << "Last name: ";
    cin >> lastName;
    cout << "Sex: ";
    cin >> sex;
    cout << "Year of Birth: ";
    cin >> YoB;
    cout << "Year of Death: ";
    cin >> YoD;


    query.prepare("SELECT * FROM Scientists WHERE id = :id;)");
    query.bindValue(":id", QString::fromStdString(id));
    query.prepare("SELECT * FROM Scientists WHERE firstName = :fistName;)");
    query.bindValue(":firstName", "%"+ QString::fromStdString(firstName)+"%");
    query.prepare("SELECT * FROM Scientists WHERE lastName = :lastName;)");
    query.bindValue(":lastName", "%"+QString::fromStdString(lastName)+"%");
    query.prepare("SELECT * FROM Scientists WHERE sex = :sex;)");
    query.bindValue(":sex", QString::fromStdString(sex));
    query.prepare("SELECT * FROM Scientists WHERE YoB = :YoB;)");
    query.bindValue(":YoB", QString::fromStdString(YoB));
    query.prepare("SELECT * FROM Scientists WHERE YoD = :YoD;)");
    query.bindValue(":YoD", QString::fromStdString(YoD));


      string player ="INSERT INTO Scientists (firstName, lastName, sex, YoB, YoD) values ('"+firstName+"', '"+lastName+"', '"+sex+"', '"+YoB+"', '"+YoD+"')";

        if(query.exec(QString(player.c_str()))){

            cout<<"========== Setti inn i Database =========="<<endl;
        }else cout << "========== Setti Ekki inn i Database =========="<<endl;

}



