#include "connectiontodatabase.h"


void GUI::mainMenu() //Prints out main menu
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

void GUI::showaddMenu(){//Prints out add menu.
    cout << "--------Add Menu-----------"<<endl ;
    cout << " \n Please select an option:  "<<endl;
    cout << "\n1. To add a computer scientist." << endl;
    cout << "2. To add a computer." << endl;
    cout << "3. To exit to main menu" << endl;
    cout << "------------------------------"<<endl;
    cout << "Choice: ";
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
    cout << "--------------Display menu--------------" << endl;
    cout << "How would you like to display your persons?" << endl;
    cout << " \n 1. By first name in alphabetical order." << endl;
    cout << " 2. By first name in reverse alphabetical order." << endl;
    cout << " 3. By Last name in alphabetical order." << endl;
    cout << " 4. By Last name in reverse alphabetical order." << endl;
    cout << " 5. By birth year. (Oldest to youngest)" << endl;
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
    display abba;
    char a;
    bool loop = true;

    while(loop == true){
        GUI::showDisplay();
        cin >> a;

        switch(a){
        case '1':
            GUI::showSortMenu();
            GUI::displayMenu();
            break;
        case '2':
            abba.cpuShowResult();
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

void GUI::displayMenu(){
    display print;
    char choice;
    bool error = false;

    while(error == false){
        cin >> choice;
        cout << endl;
        if (isalpha(choice)){ cout << "Error in input, try again." << endl;}
        else { error = true;}
    }

    switch (choice){
        case '1':{
            QSqlDatabase db;
            QSqlQuery query(db);
            cout << "Displaying by first name in alphabetical order." << endl;
            string querySort = "SELECT * FROM Scientists ORDER BY firstName DESC; ";
            if(query.exec(QString(querySort.c_str()))){
               cout << "========== The scientist table sorted successfully! =========="<< endl;}
            else {cout<< "========== Scientist table was NOT sorted :( ==========" << endl;}
            print.showResult();}
            break;
        case '2':
            cout << "Displaying by first name in reverse alphabetical order." << endl;

            break;
        case '3':
            cout << "Displaying by last name in alphabetical order." << endl;

            break;
        case '4':
            cout << "Displaying by last name in alphabetical order." << endl;

            break;
        case '5':
            cout << "Displaying by birth year." << endl;

            break;
        default:
            cout << "You entered a number with an undefined function." << endl
            << "Displaying in alphabetical order." << endl;

            break;
    }
    cout << endl;
}


