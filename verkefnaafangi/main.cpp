#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct scientists{
    string firstName;
    string lastName;
    string personSex;
    int yearOfBirth;
    int yearOfDeath;
};

void callDefaultMenu(vector<scientists>& subject);
void inputInfo(vector<scientists>& subject);
void output(vector<scientists>& subject, int persons);
void print(vector<scientists>& subject);
void printSearch(vector<scientists>& subject, int i);
void readFromFileToVector(vector<scientists>& subject);
void searchInVector(vector<scientists>& subject);
void clearVector(vector<scientists>& subject);
void sortVector(vector<scientists>& subject);



int main()
{
    //ToDo list

    //Print options f.ex alphabetical order
    //Create a function to remove a computer scientist.
    //Sorting
    //function that deletes one person from file and vector
    //function that searches for substrings
    //Error handling.
    //Cool extra features.

    vector<scientists> subject;  //vector of persons

    readFromFileToVector(subject);

    callDefaultMenu(subject);

    return 0;
}

void callDefaultMenu(vector<scientists>& subject){
    char a;
    bool loop = true;

    while(loop == true){
        cout << "---------Main Menu-----------";
        cout << " \n Please select an option:  "<<endl;
        cout << " \n 1. To add a computer scientist." << endl;
        cout << " 2. To print all persons." << endl;
        cout << " 3. To search." << endl;
        cout << " 4. To delete all data." << endl;
        cout << " 5. To quit." << endl;
        cout << "------------------------------"<<endl;
        cout << "Choice: ";
        cin >> a;

        switch(a){
        case '1':
             inputInfo(subject);
             break;
        case '2':
            print(subject);
            break;
        case '3':
            searchInVector(subject);
           break;
        case '4':
            clearVector(subject);
            break;
        case '5':
            cout << "Quitting." << endl;
            loop = false;
            break;
        default:
            cout << "Error in command, try again." << endl << endl;
            break;
        }
     }
}

void inputInfo(vector<scientists>& subject){
    scientists scientist1;
    char answer = 0;
    int persons;
    bool error = false;
    string sex;
    char sexTemp;

    while(error == false){
        cout << "How many persons would you like to add? ";
        cin >> persons;
        if (isdigit(persons)){ //this if else statement is not working correctly, needs fix.
            cout << "Error in input, try again." << endl;
        }
        if (!isdigit(persons)){
              error = true;
        }
    }

    for (int i = 1;i <= persons; i++){
        if (i == 1){
            cout << "\nEnter the info for the first person: " << endl;}
        else {
            cout << "Enter the info for the next person: " << endl;}

        cout << "Person's first name: ";
        cin >> scientist1.firstName;
        cout << "Last name: ";
        cin >> scientist1.lastName;
        cout << endl;

        do{
            cout << "Sex: (m/f) " ;
            cin >> sexTemp;
            if (sexTemp == 'm'){ sex = "Male"; error = true;}
            else if (sexTemp == 'f'){ sex = "Female"; error = true;}
            else cout << "Input was invalid try again." << endl;
        } while (error == false);
        scientist1.personSex = sex;
        cout << endl;

        cout << "Year of Birth: ";
        cin >> scientist1.yearOfBirth;
        cout << endl;

        error = false;
        do{
            cout << "Is the person still alive? (y/n) ";
            cin >> answer;
            if (answer == 'n'||answer == 'N'){
                cout << "\nYear of Death: ";
                cin >> scientist1.yearOfDeath;
                error = true;}
            else if (answer == 'y'||answer == 'Y'){
                scientist1.yearOfDeath = 0;
                error = true;}
            else cout << "Input was invalid try again." << endl;
        } while (error == false);
        cout << endl;

        subject.push_back(scientist1);  //The struct is pushed on to the vector
    }
    output(subject, persons);
}

void output(vector<scientists>& subject, int persons){
    ofstream myfile;
    myfile.open("save.txt", ios::out | ios::app); //For adding without overwriting
    if (myfile.is_open()){
        for (unsigned int i = 0; i < subject.size(); i++){  //Needs to be modified, not adding persons correctly. 1 off error.
            myfile << subject[i].firstName << endl;
            myfile << subject[i].lastName << endl;
            myfile << subject[i].personSex << endl;
            myfile << subject[i].yearOfBirth << endl;
            if(subject[i].yearOfDeath == 0){  //if still alive then marks as "Still Alive"
                myfile << "still alive." << endl;}
            else {
                myfile << subject[i].yearOfDeath << endl;}
        }
        myfile.close();
    }
    else cout << "Unable to open file";
}

void print(vector<scientists>& subject){
    for(unsigned int i = 0; i < subject.size(); i++){
        cout << "Name: " << subject[i].firstName << " ";
        cout << subject[i].lastName << endl;
        cout << "Sex: " << subject[i].personSex << endl;
        cout << "Year of birth: " << subject[i].yearOfBirth << endl;
        if (subject[i].yearOfDeath == 0){
            cout << "Alive" << endl;
        }
        else{
        cout << "Year of death: " << subject[i].yearOfDeath << endl;}
        cout << endl;
    }
}
void printSearch(vector<scientists>& subject, int i){
        cout << "Keyword was found for: " << endl;
        cout << "Name: " << subject[i].firstName << " ";
        cout << subject[i].lastName << endl;
        cout << "Sex: " << subject[i].personSex << endl;
        cout << "Year of birth: " << subject[i].yearOfBirth << endl;
        if (subject[i].yearOfDeath == 0){
            cout << "Alive" << endl;
        }
        else{
            cout << "Year of death: " << subject[i].yearOfDeath << endl;}
        cout << endl;
}

void searchInVector(vector<scientists>& subject){// Search function
    //ATH við viljum líka finna substring!!
    char input;
    bool loop = true;
    bool found = false;
    string searchFirstName;
    string searchLastName;
    int searchBirthYear;

    while(loop == true){
        cout << "--------Search Menu-----------";
        cout << " \n Please select a search option:  "<<endl;
        cout << " \n 1. To search by first name" << endl;
        cout << " 2. To search by last name" << endl;
        cout << " 3. To search by birth year" << endl;
        cout << " 4. To exit to main menu" << endl;
        cout << "-----------------------------"<<endl;
        cout << "Search by:  ";
        cin >> input;

        switch(input){ //Runs through vector and prints out the locations where "i" equals name provided
        case '1':
            cout << "Please enter a first name to search for: ";
            cin >> searchFirstName;
            cout << endl;
            for(unsigned int i = 0; i < subject.size(); i++){
                if(subject[i].firstName == searchFirstName){
                    printSearch(subject, i);
                    found = true;
                }
            }
            if (found == false){
                cout << "Sorry the first name \"" << searchFirstName << "\" did not match any first names in database. \n";
            }
            break;

        case '2': //Runs through vector and prints out the locations where "i" equals last name provided
            cout << "Please enter a last name to search for: ";
            cin >> searchLastName;
            for(unsigned int i = 0; i < subject.size(); i++)
            {
                if(subject.at(i).lastName == searchLastName){
                    printSearch(subject, i);
                    found = true;
                }
            }
            if (found == false){
                cout << "Sorry the last name \""<< searchLastName << "\" did not match any last names in database. \n";}
            break;

        case '3': //Runs through vector and prints out the locations where "i" equals birthday provided.
            cout << "Enter birth year: ";
            cin >> searchBirthYear;
            for(unsigned int i = 0; i < subject.size(); i++){
                if(subject.at(i).yearOfBirth == searchBirthYear){
                    printSearch(subject, i);
                    found = true;
                }
            }
            if (found == false){
                    cout <<"Sorry according to our records nobody was born in " << searchBirthYear << endl;
            }
           break;

         case '4':
            cout << "Going back to Main menu." << endl;
            loop = false;
            break;
        }
    }
}

void readFromFileToVector(vector<scientists>& subject){
    ifstream myfile;
    scientists scientist1;
    myfile.open("save.txt");

    while (!myfile.eof()){

        string first, second, sex, YoB, YoD;
        getline(myfile, first, '\n');
        getline(myfile, second,'\n');
        getline(myfile, sex,'\n');
        getline(myfile, YoB,'\n');
        getline(myfile, YoD,'\n');
        if (!myfile.eof()){
            scientist1.firstName = first;
            scientist1.lastName = second;
            scientist1.personSex = sex;
            scientist1.yearOfBirth = atoi(YoB.c_str());
            scientist1.yearOfDeath = atoi(YoD.c_str());
            subject.push_back(scientist1);
        }
    }
    myfile.close();
  }

void clearVector(vector<scientists>& subject){
    char answer;
    cout << "Are you sure you want to delete all data? (y/n) ";
    cin >> answer;

    if(answer == 'y'){
        subject.clear();
        cout << "Vector cleared of all elements." << endl;
        ofstream myfile;
        myfile.open("save.txt");
        myfile << "";
        myfile.close();

    }
    else{
        callDefaultMenu(subject);
    }
}
void sortVector(vector<scientists>& subject){
   // sort(subject.begin(), subject.end() );
}
