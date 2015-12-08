#include "gui.h"
#include "manualInsertScientist.h"
#include "insertcomputer.h"
#include "connectiontodatabase.h"
#include "display.h"
#include "search.h"
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
                YoD = 0;
                cout << endl;
                error = true;}
            else cout << "Input was invalid try again." << endl;
        } while (error == false);

        query.prepare("INSERT INTO Scientists (firstName, lastName, sex, YoB, YoD) "
        "VALUES (:firstName, :lastName, :sex, :YoB, :YoD)");
        query.bindValue(":id", QString::fromStdString(id));
        query.bindValue(":firstName", QString::fromStdString(firstName));
        query.bindValue(":lastName",  QString::fromStdString(lastName));
        query.bindValue(":sex",  QString::fromStdString(sex));
        query.bindValue(":YoB",  YoB);
        query.bindValue(":YoD",  YoD);



        if(query.exec()){
            cout << "========== Setti inn i Database ==========" << endl;
        }else cout << "========== Setti Ekki inn i Database ==========" << endl;
    }
}




