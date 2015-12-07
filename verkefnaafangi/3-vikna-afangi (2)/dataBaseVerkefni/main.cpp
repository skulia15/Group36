#include <iostream>
#include <QtSql>
#include <fstream>
#include <string>
#include <vector>
#include <QCoreApplication>
#include <fstream>
#include "gui.h"
#include "manualInsertScientist.h"
#include "connectiontodatabase.h"

using namespace std;

struct Klasi{
    int id;
    string name;
    string email;
    int age;

};

//void inputInfo(vector<Klasi>& viktor);//input into Vector
//void manualInsertToDataBase();
//void readFromDatabaseToVector(vector<Klasi>& viktor);


int main()
{
    /*
     vector<Klasi>viktor;

   QSqlDatabase db;
   db = QSqlDatabase::addDatabase("QSQLITE");
   QString dbName = "student_db.sqlite";
   db.setDatabaseName(dbName);

   db.open();

    QSqlQuery query(db);

   if(db.open())
        qDebug()<<"opnadi DB";
    else
          qDebug()<<"Close"<<db.lastError().text();

string queryCreate ="CREATE TABLE students(id INTEGER, name VARCHAR, email VARCHAR, age INTEGER); ";
if(query.exec(QString(queryCreate.c_str()))){
cout<< "Bjo til DB"<<endl;}
else {cout<< "Bjo ekki til nyjan DB"<<endl;}

*/


//manualInsertToDataBase();
//inputInfo(viktor);
//readFromDatabaseToVector(viktor);

GUI menu;

connectionToDataBAse();
menu.displayMainMenu();
//sci1.manualInput();
    return 0;
}


void inputInfo(vector<Klasi>& viktor){
    Klasi nemandi;

    char persons;
    bool error = false;

    while(error == false){
        cout << "How many persons would you like to add? ";
        cin >> persons;
        if (isalpha(persons)){
            cout << "Error in input, try again." << endl;
        }
        else
            error = true;
    }

    for (int i = 1;i <= persons - '0'; i++){
        if (i == 1){
            cout << "\nEnter the info for the first person: " << endl;}
        else {
            cout << "Enter the info for the next person: " << endl;}

        cout << "Person's Id: ";
        cin >> nemandi.id;
        cout << "Person's first name: ";
        cin >> nemandi.name;
        cout << "Person's first name: ";
        cin >> nemandi.email;
        cout << "Person's age: ";
        cin >> nemandi.age;

        viktor.push_back(nemandi);  //The struct is pushed on to the vector
    }
    for(unsigned int i =0; i<viktor.size(); i++)
    {
        cout << viktor.at(i).name<<" id is "<<viktor.at(i).id<<endl;
        cout << viktor.at(i).name<<" is "<< viktor.at(i).age<<endl;
        cout << viktor.at(i).name<< " email is "<< viktor.at(i).email<<endl;
    }
}

void manualInsertToDataBase() //Manual insert to Database
{
    QSqlDatabase db;
    QSqlQuery query(db);
    string id,name,email, age;

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

void readFromDatabaseToVector(vector<Klasi>& viktor){
    Klasi nemandi;
    QSqlDatabase db;
    QSqlQuery query(db);

    query.exec("SELECT * FROM students");
    while(query.next()){
   // qDebug()<< query.lastQuery();
    int id = query.value(0).toUInt();
    string name = query.value("name").toString().toStdString();
    string email = query.value("email").toString().toStdString();
    int age = query.value("age").toUInt();


    cout << id << " "<< name << " " << email << " "<<age <<endl;

        viktor.push_back(Klasi());

    }
    cout <<endl;

    for(unsigned int i =0; i<viktor.size();i++)
    {
        cout << viktor.at(i).id<<endl;
        cout << viktor.at(i).name<<endl;
        cout << viktor.at(i).email<<endl;
        cout << viktor.at(i).age<<endl;
    }


}

