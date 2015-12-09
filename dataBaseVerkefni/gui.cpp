#include "connectiontodatabase.h"
#include "gui.h"
#include "manualInsertScientist.h"
#include "insertcomputer.h"
#include "connectiontodatabase.h"
#include "search.h"
#include "display.h"

void GUI::mainMenu() //Prints out main menu
{
    cout << "-------------Main Menu---------------" <<endl;
    cout << " Please select an option:  "<<endl;
    cout << " \n 1. To add or delete." << endl;
    cout << " 2. To display." << endl;
    cout << " 3. To search." << endl;
    cout << " 4. To delete all data." << endl;
    cout << " 5. To quit." << endl;
    cout << "-------------------------------------"<<endl;
    cout << "Choice: ";
}

void GUI::showaddMenu(){//Prints out add menu.
    cout << "--------Add Menu-----------"<<endl ;
    cout << " \n Please select an option:  "<<endl;
    cout << "\n1. To add a computer scientist." << endl;
    cout << "2. To add a computer." << endl;
    cout << "3. To delete a scientist." << endl;
    cout << "4. To delete a computer." << endl;
    cout << "5. To exit to main menu" << endl;
    cout << "------------------------------"<<endl;
    cout << "Choice: ";
}

void GUI::searchMenu(){
    cout << "--------Search Menu-----------"<<endl ;
    cout << " \n Please select a search option:  "<<endl;
    cout << " \n 1. To search by first name" << endl;
    cout << " 2. To search by last name" << endl;
    cout << " 3. To search by birth year" << endl;
    cout << " 4. To search anywhere by a keyword." << endl;
    cout << " 5. To search on Wikipedia" << endl;
    cout << " 6. To exit to main menu" << endl;
    cout << "------------------------------"<<endl;
    cout << "Search by:  " << endl;
}

void GUI::showDisplay(){
    cout << "--------Display Menu-----------"<<endl ;
    cout << " \n Please select an option:  "<<endl;
    cout << " \n 1. To print all computer scientists." << endl;
    cout << " 2. To print all computers." << endl;
    cout << " 3. To exit to main menu" << endl;
    cout << "------------------------------"<<endl;
    cout << "Choice: ";
}

void GUI::showSortMenu(){
    cout << endl;
    cout << "--------------Sort menu--------------" << endl;
    cout << "How would you like to display your persons?" << endl;
    cout << " \n 1. By first name in alphabetical order." << endl;
    cout << " 2. By first name in reverse alphabetical order." << endl;
    cout << " 3. By Last name in alphabetical order." << endl;
    cout << " 4. By Last name in reverse alphabetical order." << endl;
    cout << " 5. By birth year. (Oldest to youngest)" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Input your choice: ";
}

void GUI::showComputerSortMenu(){
    cout << endl;
    cout << "--------------Display menu--------------" << endl;
    cout << "How would you like to display your computers?" << endl;
    cout << " \n 1. By name in alphabetical order." << endl;
    cout << " 2. By name in reverse alphabetical order." << endl;
    cout << " 3. By type in alphabetical order." << endl;
    cout << " 4. By typein reverse alphabetical order." << endl;
    cout << " 5. By year built." << endl;
    cout << "----------------------------------------" << endl;
    cout << "Input your choice: ";
}

void GUI::displayMainMenu(){//Switch statment for main menu
    connectionToDataBase diconect;
    extras deleter;
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
            cout << "All data was deleted." << endl;
            deleter.deleteAll();
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

void GUI::displaySearchMenu(){//Switch statment for search menu
    char input;
    bool loop = true;
    extras doSearch;
    searchData find;
    string theSearchName;

    while(loop == true){
        GUI::searchMenu();
        cin >> input;

        switch(input){ //Runs through vector and prints out the locations where "i" equals name provided.
        case '1':
           find.searchFirstName();
           break;
        case '2': //Runs through vector and prints out the locations where "i" equals last name provided.
           find.searchLastName();
           break;
        case '3': //Runs through vector and prints out the locations where "i" equals birthday provided..
           find.searchBirthYear();
           break;
        case '4':
            cout << "Searching for keyword." << endl;
            find.searchKeyword();

            break;
        case '5': //Searches wikipedia
           cout << "Search on Wikipedia"<< endl;
           doSearch.searchWiki();
           break;
        case '6':
           cout << "Going back to Main menu." << endl;
           loop = false;
           break;
        default:
           cout << "Please enter a number between 1 and 4." << endl << endl;
           break;
       }
   }
}


void GUI::addMenu(){ //Switch statment for add menu.
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
            theScientist.deleteScientist();
            break;
        case '4':
            theComputer.deleteCPU();
            break;
        case '5':
            cout << endl;
            cout << "Going back to main-menu." << endl<<endl;
            loop = false;
            break;
        default:
            cout << "Error in command, try again." << endl << endl;
            break;
        }
     }
}


void GUI::showDisplay2(){ // Switch statment for display menu.

    char a;
    bool loop = true;

    while(loop == true){
        GUI::showDisplay();
        cin >> a;

        switch(a){
        case '1':
            GUI::showSortMenu();
            GUI::displaySortMenu();
            break;
        case '2':
            GUI::showComputerSortMenu();
            GUI::displayComputerSortMenu();
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
     }
}

void GUI::displaySortMenu(){
    display print;
    char choice;
    bool error = false;
    QSqlDatabase db;
    QSqlQuery query(db);

    while(error == false){
        cin >> choice;
        cout << endl;
        if (isalpha(choice)){ cout << "Error in input, try again." << endl;}
        else { error = true;}
    }

    switch (choice){
        case '1':
            cout << "Displaying by first name in alphabetical order." << endl;
            print.showResult("SELECT * FROM Scientists ORDER BY firstName ASC; ");
            break;
    case '2':
            cout << "Displaying by first name in reverse alphabetical order." << endl;
            print.showResult("SELECT * FROM Scientists ORDER BY firstName DESC; ");
            break;
        case '3':
            cout << "Displaying by last name in alphabetical order." << endl;
            print.showResult("SELECT * FROM Scientists ORDER BY lastName ASC; ");
            break;
        case '4':
            cout << "Displaying by last name in reverse alphabetical order." << endl;
            print.showResult("SELECT * FROM Scientists ORDER BY lastName DESC; ");
            break;
        case '5':
            cout << "Displaying by birth year." << endl;
            print.showResult("SELECT * FROM Scientists ORDER BY YoB ASC; ");
            break;
        default:
            cout << "You entered a number with an undefined function." << endl
            << "Displaying by first name in alphabetical order." << endl;
            print.showResult("SELECT * FROM Scientists ORDER BY firstName ASC; ");
            break;
    }
    cout << endl;
}

void GUI::displayComputerSortMenu(){
    display print;
    char choice;
    bool error = false;
    QSqlDatabase db;
    QSqlQuery query(db);

    while(error == false){
        cin >> choice;
        cout << endl;
        if (isalpha(choice)){ cout << "Error in input, try again." << endl;}
        else { error = true;}
    }

    switch (choice){
        case '1':
            cout << "Displaying by name in alphabetical order." << endl;
            print.cpuShowResult("SELECT * FROM Computers ORDER BY cpuName ASC; ");
            break;
        case '2':
            cout << "Displaying by name in reverse alphabetical order." << endl;
            print.cpuShowResult("SELECT * FROM Computers ORDER BY cpuName DESC; ");
            break;
        case '3':
            cout << "Displaying by type in alphabetical order." << endl;
            print.cpuShowResult("SELECT * FROM Computers ORDER BY cpuType ASC; ");
            break;
        case '4':
            cout << "Displaying by type in reverse alphabetical order." << endl;
            print.cpuShowResult("SELECT * FROM Computers ORDER BY cpuType DESC; ");
            break;
        case '5':
            cout << "Displaying by year built." << endl;
            print.cpuShowResult("SELECT * FROM Computers ORDER BY yearBuilt ASC; ");
            break;
        default:
            cout << "You entered a number with an undefined function." << endl
            << "Displaying by name in alphabetical order." << endl;
            print.cpuShowResult("SELECT * FROM Computers ORDER BY cpuName ASC; ");
            break;
        }
    cout << endl;
}
