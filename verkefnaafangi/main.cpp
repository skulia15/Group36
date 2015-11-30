#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;

struct scientists{
    string firstName;
    string lastName;
    string personSex;
    int yearOfBirth;
    int yearOfDeath;
};

void callDefaultMenu(vector<scientists>& subject, int& totalPersons);
void inputInfo(vector<scientists>& subject);
void output(vector<scientists>& subject, int persons);
void print(vector<scientists>& subject);
void readFromFileToVector(vector<scientists>& subject, int& totalPersons);
void searchInVector(vector<scientists>& subject);
void deleteVector(vector<scientists>& subject);

int main()
{
    int totalPersons = 0;
    //ToDo list
    //Check if vector pushes back values correctly.
    //Figure out how to print contents of vector.
    //Create a function to save the info into a file.
    //Print options f.ex alphabetical order
    //Create a function to remove a computer scientist.
    //Error handling.
    //Cool extra features.

    vector<scientists> subject;  //vector of persons

    readFromFileToVector(subject, totalPersons);

    callDefaultMenu(subject, totalPersons);

    return 0;
}

void callDefaultMenu(vector<scientists>& subject, int& totalPersons){
    char a;
    bool loop = true;


    while(loop == true){

    cout << "These are the contents of the vector at the moment!" << endl;
    for(int i = 0; i < subject.size(); i++){
            cout << subject[i].firstName << " ";
            cout << subject[i].lastName << endl;
            cout << subject[i].personSex << endl;
            cout << subject[i].yearOfBirth << endl;
            cout << subject[i].yearOfDeath << endl;
    }
    cout << "END!" << endl;
        cout << "---------Main Menu-----------";
        cout << " \n Please select a option:  "<<endl;
        cout << " \n 1. To add a computer scientist" << endl;
        cout << " 2. To print all persons" << endl;
        cout << " 3. To search" << endl;
        cout << " 4. To quit" << endl;
        cout << "------------------------------"<<endl;
        cout << "Coice: ";
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
        for (int i = 0; i < subject.size(); i++){  //Needs to be modified, not adding persons correctly. 1 off error.
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
        for(int i = 0; i < subject.size(); i++){
            cout << "Name: " << subject[i].firstName << " ";
            cout << subject[i].lastName << endl;
            cout << "Sex: " << subject[i].personSex << endl;
            cout << "Year of birth: " << subject[i].yearOfBirth << endl;
            cout << "Year of death: " << subject[i].yearOfDeath << endl << endl;
        }
}



void searchInVector(vector<scientists>& subject){// Search function
    char a;
    bool loop = true;
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
        cin >> a;

        switch(a){ //Runs through vector and prints out the locations where "i" equals name provided
        case '1':

            cout<<"Please enter a firstname to search for"<<endl;
            cin>> searchFirstName;
            for(unsigned int i=0; i<subject.size(); i++)
            {
                if(subject.at(i).firstName == searchFirstName){
                    cout<< subject.at(i).firstName<<" "
                       <<subject.at(i).lastName<<" "
                       << subject.at(i).personSex<<" "
                       << subject.at(i).yearOfBirth<<" "
                       << subject.at(i).yearOfDeath<<endl;
                }
            }cout<<"Sorry the first name "<< searchFirstName<<" did not match any first names in database. \n";

             break;

        case '2': //Runs through vector and prints out the locations where "i" equals lastname provided
            cin>> searchLastName;
            for(unsigned int i=0; i<subject.size(); i++)
            {
                if(subject.at(i).lastName == searchLastName){
                    cout<< subject.at(i).lastName<<" "
                       <<subject.at(i).firstName<<" "
                       << subject.at(i).personSex<<" "
                       << subject.at(i).yearOfBirth<<" "
                       << subject.at(i).yearOfDeath<<endl;
                }

            }cout<<"Sorry the last name"<< searchLastName<<" did not match any last names in database. \n";
            break;

        case '3': //Runs through vector and prints out the locations where "i" equals birthday provided.
            cin >> searchBirthYear;
            for(unsigned int i = 0; i < subject.size(); i++){
                if(subject.at(i).yearOfBirth == searchBirthYear){
                    cout << subject.at(i).lastName<<" "
                       << subject.at(i).firstName<<" "
                       << subject.at(i).personSex<<" "
                       << subject.at(i).yearOfBirth<<" "
                       << subject.at(i).yearOfDeath<<endl;
                }
            }cout<<"Sorry according to our records nobody was born in "<< searchBirthYear <<endl;
           break;

         case '4':
            cout << "Going back to Main menu." << endl;
            loop = false;
            break;
        }
    }
}

void readFromFileToVector(vector<scientists>& subject, int& totalPersons){
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
            totalPersons++;
        }
    }
    myfile.close();
  }
