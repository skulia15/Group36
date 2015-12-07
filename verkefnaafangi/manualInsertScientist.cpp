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
   YoB = 0;
   YoD = 0;
=======
<<<<<<< HEAD
   YoB = "";
   YoD = "";
=======
   YoB;
   YoD;
>>>>>>> 164d4166f55dccc8e0d01206b4ee6984ba400242
>>>>>>> e6e9f8a5556062e155d4ea892f5b42c537d9591a
};

void Scientists::manualInput(){

    QSqlDatabase db;
    QSqlQuery query(db);

<<<<<<< HEAD
    string queryPrint = "SELECT * FROM Scientists";
    query.exec(QString(queryPrint.c_str()));

=======
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
>>>>>>> e6e9f8a5556062e155d4ea892f5b42c537d9591a
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



