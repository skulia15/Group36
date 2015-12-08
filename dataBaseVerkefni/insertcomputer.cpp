#include "gui.h"
#include "manualInsertScientist.h"
#include "insertcomputer.h"
#include "connectiontodatabase.h"
#include "display.h"
#include "search.h"


using namespace std;

Computers::Computers()
{
   cpuName="";
   yearBuilt=0;
   cpuType="";
};

void Computers::insertCPU()
{
        bool error = false;
        bool error2 = true;
        char cpus;
        char temp;

        QSqlDatabase db;
        QSqlQuery query(db);

        while(error == false){
            cout << "How many computers would you like to add? ";
            cin >> cpus;
            if (isalpha(cpus)){
                cout << "Error in input, try again." << endl;
            }
            else
                error = true;
        }

        for (int i = 1;i <= cpus - '0'; i++){
            if (i == 1){
                cout << "\nEnter the info for the first computer: " << endl;
            }
            else {
                cout << "Enter the info for the next computer: " << endl;
            }

            cout << "Computer name: ";
            cin >> cpuName;

            while (error2 == true){
                cout << "Was the computer built? (y/n) ";
                cin >> temp;
                if (temp == 'y'||temp == 'Y'){
                    built = "Yes"; error2 = false;
                    cout << "Year built: ";
                    cin >> yearBuilt;
                }
                else if (temp == 'n'||temp == 'N'){
                    built = "No"; error2 = false;
                }
                else
                cout << "Input was invalid, please try again." << endl;
            }

            cout << "Computer type: ";
            cin >> cpuType;

            query.prepare("INSERT INTO Computers (cpuName, built, yearBuilt, cpuType) "
                              "VALUES (:cpuName, :built, :yearBuilt, :cpuType)");
            query.bindValue(":cpuName", QString::fromStdString(cpuName));
            query.bindValue(":built", QString::fromStdString(built));
            query.bindValue(":yearBuilt", yearBuilt);
            query.bindValue(":cpuType",  QString::fromStdString(cpuType));

            if(query.exec()){
                cout << endl;
                cout << "-==== Successfully inserted data into database ====-"<<endl;
                cout << endl;
            }
            else{
                cout << endl;
                cout << "-==== Could not insert data into database ====-"<<endl;
                cout << endl;
            }
        }
}
