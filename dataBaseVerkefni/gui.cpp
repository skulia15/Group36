#include "gui.h"
#include "manualInsertScientist.h"
#include "insertcomputer.h"
#include "connectiontodatabase.h"
#include "display.h"
#include "search.h"
#include "extras.h"

using namespace std;

void GUI::mainMenu()
{
    cout << "-------------Main Menu---------------" <<endl;
    cout << " \n Please select an option:  "<<endl;
    cout << " \n 1. To add." << endl;
    cout << " 2. To display." << endl;
    cout << " 3. To search." << endl;
    cout << " 4. To delete all data." << endl;

    cout << " 5. To quit." << endl;
    cout << "-------------------------------------"<<endl;
    cout << "Choice: ";
}

void GUI::displayMainMenu(){


connectionToDataBase diconect;
    char a;
        bool loop = true;

        while(loop == true){
            GUI::mainMenu();
            cin >> a;

            switch(a){
            case '1':
                GUI::addMenu();
                break;
            case '2':
                GUI::showDisplay2();
                break;
            case '3':
                GUI::displaySearchMenu();
               break;
            case '4':
                cout << "Delete data" << endl;
                break;
            case '5':
                diconect.disconect();
                cout << "-===== We have disconected from the database====-"<<endl;
                cout << "Quitting." << endl;
                loop = false;
                break;
            default:
                cout << "Error in command, try again." << endl << endl;
                break;
            }
         }
}

void GUI::displaySearchMenu(){
    char input;
    bool loop = true;
    extras doSearch;

    string theSearchName;

    while(loop == true){
        GUI::searchMenu();
        cin >> input;

        switch(input){ //Runs through vector and prints out the locations where "i" equals name provided.
        case '1':
           cout << "Search after first name "<<endl;
           break;
        case '2': //Runs through vector and prints out the locations where "i" equals last name provided.
           cout << "Search after last name "<<endl;
           break;
        case '3': //Runs through vector and prints out the locations where "i" equals birthday provided..
           cout << "Search by birth year "<<endl;
           break;
        case '4': //Searches wikipedia
           cout << "Search on Wikipedia"<< endl;
           doSearch.searchWiki();
           break;
        case '5':
           cout << "Going back to Main menu." << endl;
           loop = false;
           break;
        default:
           cout << "Please enter a number between 1 and 4." << endl << endl;
           break;
       }
   }
}

void GUI::searchMenu(){
    cout << "--------Search Menu-----------"<<endl ;
    cout << " \n Please select a search option:  "<<endl;
    cout << " \n 1. To search by first name" << endl;
    cout << " 2. To search by last name" << endl;
    cout << " 3. To search by birth year" << endl;
    cout << " 4. To search on Wikipedia" << endl;
    cout << " 5. To exit to main menu" << endl;
    cout << "------------------------------"<<endl;
    cout << "Search by:  " << endl;
}


void GUI::addMenu(){
    Scientists theScientist;
    Computers theComputer;
char a;
    bool loop = true;

    while(loop == true){
        GUI::showaddMenu();
        cin >> a;

        switch(a){
        case '1':
            theScientist.manualInput();
            break;
        case '2':
            theComputer.insertCPU();
            break;
        case '3':
            cout << endl;
            cout << "Going back to main-menu." << endl<<endl;
            loop = false;
            break;
        default:
            cout << "Error in command, try again." << endl << endl;
            break;
        }
     }}

    void GUI::showaddMenu(){
        cout << "--------Add Menu-----------"<<endl ;
        cout << " \n Please select an option:  "<<endl;
        cout << "\n1. To add a computer scientist." << endl;
        cout << "2. To add a computer." << endl;
        cout << "3. To exit to main menu" << endl;
        cout << "------------------------------"<<endl;
        cout << "Choice: ";
    }


    void GUI::showDisplay2(){
    display abba;

    char a;
        bool loop = true;

        while(loop == true){
            GUI::showDisplay();
            cin >> a;

            switch(a){
            case '1':
                abba.showresult();
                break;
            case '2':
                abba.cpuShowresult();
                break;
            case '3':
                cout << endl;
                cout << "Going back to main-menu." << endl<<endl;
                loop = false;
                break;
            default:
                cout << "Error in command, try again." << endl << endl;
                break;
            }
         }}

        void GUI::showDisplay(){
            cout << "--------Display Menu-----------"<<endl ;
            cout << " \n Please select an option:  "<<endl;
            cout << " \n 1. To print all computer scientists." << endl;
            cout << " 2. To print all computers." << endl;
            cout << " 3. To exit to main menu" << endl;
            cout << "------------------------------"<<endl;
            cout << "Choice: ";
        }
