#include "gui.h"
#include "manualInsertScientist.h"
#include "connectiontodatabase.h"
#include <QtSql>
#include <iostream>
using namespace std;

Scientists::Scientists()
{
   id="";
   name="";
   email="";
   age="";
};

void Scientists::manualInput()
{

        QSqlDatabase db;
        QSqlQuery query(db);
        //string id,name,email, age;

        cout<< "Please enter ID, Name, email and age \n";
        cin >> id>> name>> email>> age;

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

