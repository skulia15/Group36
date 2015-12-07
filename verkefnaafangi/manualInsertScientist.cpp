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
   YoB = 0;
   YoD = 0;
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
    query.bindValue(":YoB", QString(YoB));
    query.prepare("SELECT * FROM Scientists WHERE YoD = :YoD;)");
    query.bindValue(":YoD", QString(YoD));


   string player = "INSERT INTO Scientists (firstName, lastName, sex, YoB) values ('"+firstName+"', '"+lastName+"', '"+sex+"', '"+YoB+"')";
   //Vantar að adda YoB og YoD, fæ alltaf errors....

    if(query.exec(QString(player.c_str()))){
        cout << "Successfully added to Database" << endl;
    }
    else
        cout << "Was NOT added to the Database" << endl;
}



