#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

struct scientists{
    string firstName;
    string middleName;
    string lastName;
    char personSex;
    int yearOfBirth;
    int yearOfDeath;
};

void callDefaultMenu();

void inputInfo(vector<scientists> subject);

int main()
{ 
    //ToDo list
    //Be able to enter info into the struct and push it back into the vector
    //Save the info into a file.
    //print the info inside the file
    //print options f.ex alphabetical order
    //implement a search function
    vector<scientists> subject;

    subject.push_back(scientists()); //default constructor

    callDefaultMenu();


    /*person1.inputName();
    person1.inputSex();
    person1.inputYoB();
    person1.inputYoD();*/

    return 0;
}

void callDefaultMenu(){
    char a;
    bool loop = true;

    while(loop == true)
    {


            cout << "-----------Menu-----------"<<endl;
            cout <<endl;
            cout << " Please select a option  "<<endl;
            cout << " 1 to add a person" << endl;
            cout << " 2 to print all persons" << endl;
            cout << " 3 to search" << endl;
            cout << " 4 to quit" << endl;
            cout <<endl;
            cout << "--------------------------"<<endl;
            cin >> a;

            switch(a)
            {
            case '1':
                 inputInfo(vector<scientists> subject);
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
                cout << "Error in command, try again." << endl;
                break;
            }

        }
    }


void inputInfo(vector<scientists> subject){
    scientists scientist1;
    char answer;

    cout << "Person's name: ";
    cin >> scientist1.firstName;
    cout << " ";
    cin >> scientist1.lastName;
    cout << endl;

    cout << "Sex: (m/f)";
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
    cout << "Person's name: ";
    cout << scientist1.firstName;
    cout << " ";
    cout << scientist1.lastName;
    cout << endl;

    cout << "Sex: (m/f)";
    cout << scientist1.personSex;
    cout << endl;

    cout << "Year of Birth: ";
    cout << scientist1.yearOfBirth;
    cout << endl;

    if (answer == 'n'||answer == 'N'){
        cout << "Year of Death: ";
        cout << scientist1.yearOfDeath;
    }
    cout << endl;
}
