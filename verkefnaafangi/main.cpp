#include "gui.h"
#include "manualInsertScientist.h"
#include "connectiontodatabase.h"

using namespace std;

struct Klasi{
    int id;
    string firstName;
    string lastName;
    string sex;
    int YoB;
    int YoD;
};

void readFromDatabaseToVector(vector<Klasi>& viktor);

//void inputInfo(vector<Klasi>& viktor);//input into Vector
//void manualInsertToDataBase();
//void readFromDatabaseToVector(vector<Klasi>& viktor);


int main(){
    vector<Klasi>viktor;

    GUI menu;

    connectionToDataBase();

    readFromDatabaseToVector(viktor);

    menu.displayMainMenu();

    return 0;
}

/*
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
        cin >> nemandi.sex;
        cout << "Person's age: ";
        cin >> nemandi.YoB;

        viktor.push_back(nemandi);  //The struct is pushed on to the vector
    }
    for(unsigned int i =0; i<viktor.size(); i++)
    {
        cout << viktor.at(i).name <<" id is "<<viktor.at(i).id << endl;
        cout << viktor.at(i).name <<" is "<< viktor.at(i).name << endl;
        cout << viktor.at(i).name << " email is "<< viktor.at(i).sex << endl;
    }
}

*/

void readFromDatabaseToVector(vector<Klasi>& viktor){
    Klasi nemandi;
    QSqlDatabase db;
    QSqlQuery query(db);

    while(query.next()){
   // qDebug()<< query.lastQuery();
    int id = query.value(0).toUInt();
    string firstName = query.value("firstName").toString().toStdString();
    string lastName = query.value("lastName").toString().toStdString();
    string sex = query.value("sex").toString().toStdString();
    int YoB = query.value("YoB").toUInt();
    int YoD = query.value("YoD").toUInt();

    cout << id << " "<< firstName << " " << lastName << " " << sex << " "<< YoB <<  " " << YoD << endl;

    viktor.push_back(Klasi());

    }
    cout << endl;
    cout << "======How big is the vector after reading to it?: ======" << endl
         << "The size is: " << viktor.size() << endl;

    for(unsigned int i =0; i < viktor.size();i++){
        cout << viktor.at(i).id << endl;
        cout << viktor.at(i).firstName << endl;
        cout << viktor.at(i).lastName << endl;
        cout << viktor.at(i).sex << endl;
        cout << viktor.at(i).YoB << endl;
        cout << viktor.at(i).YoD << endl;
    }
}
