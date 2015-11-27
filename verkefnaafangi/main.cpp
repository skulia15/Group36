#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <ostream>
#include <iterator>

using namespace std;

struct scientists{
    string firstName;
    string lastName;
    char personSex;
    int yearOfBirth;
    int yearOfDeath;
};

void callDefaultMenu(vector<scientists>& subject);
void inputInfo(vector<scientists>& subject);
void output(vector<scientists>& subject);

int main()
{ 
    //ToDo list
    //Save the info into a file.
    //print the info inside the file
    //print options f.ex alphabetical order
    //implement a search function
    vector<scientists> subject;

    subject.push_back(scientists()); //default constructor

    callDefaultMenu(subject);

    return 0;
}

void callDefaultMenu(vector<scientists>& subject){
    char a;
    bool loop = true;

    while(loop == true)
    {
        cout << "-----------Menu-----------"<<endl;
        cout << endl;
        cout << " Please select a option  "<<endl;
        cout << " 1. to add a person" << endl;
        cout << " 2. to print all persons" << endl;
        cout << " 3. to search" << endl;
        cout << " 4. to quit" << endl;
        cout << endl;
        cout << "--------------------------"<<endl;
        cin >> a;

        switch(a){
        case '1':
             inputInfo(subject);
             break;
        case '2':
            //print();
            break;
        case '3':
           //search();
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

    cout << "How many persons would you like to add? ";
    cin >> persons;

    for (int i = 0;i < persons; i++){
        if (i == 0){
            cout << "Enter the info for the first person: " << endl;
        }
        else {
            cout << "Enter the info for the next person: " << endl;
        }

        cout << "Person's name: ";
        cin >> scientist1.firstName;
        cout << " ";
        cin >> scientist1.lastName;
        cout << endl;

        cout << "Sex: (m/f) " ;
        cin >> scientist1.personSex;
        cout << endl;

        cout << "Year of Birth: ";
        cin >> scientist1.yearOfBirth;
        cout << endl;

        cout << "Is the person still alive? (y/n) ";
        cin >> answer;

        if (answer == 'n'||answer == 'N'){
            cout << "\nYear of Death: ";
            cin >> scientist1.yearOfDeath;
        }
        cout << endl;

        subject.push_back(scientist1);
        output(subject);
    }
}

void output(vector<scientists>& subject){
    ifstream document;
    ofstream writeToFile;
    writeToFile.open("list.txt", ios::out | ios::app);
    if (writeToFile.is_open()){
         writeToFile << "testing";
         //ostream_iterator<string> output_iterator(writeToFile, "\n");
         //copy(subject.begin(), subject.end(), output_iterator);
    }
    else {
        cout << "Unable to open file." << endl;
    }
    writeToFile.close();
    document.close();
}

