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
    bool error = false;
    bool error2 = true;
    char persons;
    char temp;

    QSqlDatabase db;
    QSqlQuery query(db);

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

        cout << "First name: ";
        cin >> firstName;
        cout << "Last name: ";
        cin >> lastName;

        while (error2 == true){
            cout << "Sex: (m/f) ";
            cin >> temp;
            if (temp == 'm'||temp == 'M'){
                sex = "Male"; error2 = false;}
            else if (temp == 'f'||temp == 'F'){
                sex = "Female"; error2 = false;}
            else
            cout << "Input was invalid try again." << endl;}

        cout << "Year of Birth: ";
        cin >> YoB;

        error = false;
        do{
            cout << "Is the person still alive? (y/n) ";
            cin >> temp;
            if (temp == 'n'||temp == 'N'){
                cout << "Year of Death: ";
                cin >> YoD;
                while(YoB > YoD){
                    cout << "The person can not have died before its birth, please try again" << endl;
                    cout << "Year of Death: ";
                    cin >> YoD;}
                cout << endl;
                error = true;}
            else if (temp == 'y'||temp == 'Y'){
                YoD = "";
                cout << endl;
                error = true;}
            else cout << "Input was invalid try again." << endl;
        } while (error == false);


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


        string player = "INSERT INTO Scientists (firstName, lastName, sex, YoB, YoD) values ('"+firstName+"', '"+lastName+"', '"+sex+"', '"+YoB+"', '"+YoD+"')";

        if(query.exec(QString(player.c_str()))){
            cout << "========== Setti inn i Database ==========" << endl;
        }else cout << "========== Setti Ekki inn i Database ==========" << endl;
    }

    string queryPrint = "SELECT * FROM Scientists";
    if(query.exec(QString(queryPrint.c_str()))){
        cout << "=====should be printing the table, why doesn't it??=====" << endl;}
    else{ cout << "error executing command!" << endl;
    }
}




