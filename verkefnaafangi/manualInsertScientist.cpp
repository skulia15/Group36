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
<<<<<<< HEAD
   YoB = "";
   YoD = "";
=======
   YoB;
   YoD;
>>>>>>> 164d4166f55dccc8e0d01206b4ee6984ba400242
};

void Scientists::manualInput(){
    QSqlDatabase db;
    QSqlQuery query(db);

<<<<<<< HEAD
        QSqlDatabase db;
        QSqlQuery query(db);
        //string id,name,email, age;

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
=======
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
>>>>>>> 164d4166f55dccc8e0d01206b4ee6984ba400242


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

<<<<<<< HEAD
      string player ="INSERT INTO students (firstName, lastName, sex, YoB, YoD) values ('"+firstName+"', '"+lastName+"', '"+sex+"', '"+YoB+"', '"+YoD+"')";

        if(query.exec(QString(player.c_str()))){

            cout<<"========== Setti inn i Database =========="<<endl;
        }else cout << "========== Setti Ekki inn i Database =========="<<endl;
=======
    if(query.exec(QString(player.c_str()))){
        cout << "Successfully added to Database" << endl;
>>>>>>> 164d4166f55dccc8e0d01206b4ee6984ba400242
    }
    else
        cout << "Was NOT added to the Database" << endl;
    }


