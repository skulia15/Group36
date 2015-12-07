#include "gui.h"
#include "manualInsertScientist.h"
#include "connectiontodatabase.h"
#include <QtSql>
#include <iostream>
using namespace std;

Scientists::Scientists()
{
   firstName = "";
   lastName = "";
   sex = "";
   YoB = 0;
   YoD = 0;
};

void Scientists::manualInput()
{

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
        cout << "Year of Birth ";
        cin >> YoB;
        cout << "Year of Death";
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



      string player ="INSERT INTO students (id, name, email, age) values ('"+id+"', '"+name+"', '"+email+"', '"+age+"')";

        if(query.exec(QString(player.c_str()))){

            cout<<"Setti inn i Database"<<endl;
        }else cout << "Setti Ekki inn i Database"<<endl;
    }

