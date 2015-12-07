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
   YoB;
   YoD;
};

void Scientists::manualInput(){
    QSqlDatabase db;
    QSqlQuery query(db);

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


    /*
        query.prepare("SELECT * FROM students WHERE id = :id;)");
        query.bindValue(":id", QString::fromStdString(id));
        query.prepare("SELECT * FROM students WHERE name = :name;)");
        query.bindValue(":name", "%"+ QString::fromStdString(name)+"%");
        query.prepare("SELECT * FROM students WHERE email = :email;)");
        query.bindValue(":email", "%"+QString::fromStdString(email)+"%");
        query.prepare("SELECT * FROM students WHERE age = :age;)");
        query.bindValue(":age", QString::fromStdString(age));
    */


   string player = "INSERT INTO Scientists (firstName, lastName, sex) values ('"+firstName+"', '"+lastName+"', '"+sex+"')";
   //Vantar að adda YoB og YoD, fæ alltaf errors....

    if(query.exec(QString(player.c_str()))){
        cout << "Successfully added to Database" << endl;
    }
    else
        cout << "Was NOT added to the Database" << endl;
    }


