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

void inputInfo(vector<scientists>& subject);

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

    inputInfo(subject);


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
        cout << "Press 1 to add a person" << endl;
        cout << "Press 2 to print all persons" << endl;
        cout << "Press 3 to search" << endl;
        cout << "Press 4 to quit" << endl;

        cin >> a;

        switch(a)
        {
        case '1':
             //input();
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
            callDefaultMenu();
            break;
        }
    }
}

void inputInfo(vector<scientists>& subject){
    scientists scientist1;
    char answer = 0;
    char sex;

    cout << "Person's name: ";
    cin >> scientist1.firstName;
    cout << " ";
    cin >> scientist1.lastName;
    cout << endl;

    while(sex != 'm' || sex != 'f'){
    cout << "Sex: (m/f)";
    cin >> scientist1.personSex;
    sex = scientist1.personSex;
        if (scientist1.personSex != 'm' || scientist1.personSex != 'f'){
            cout << "Enter m for male or f for female";
    }
    cout << endl;
    }

    cout << "Year of Birth: ";
    cin >> scientist1.yearOfBirth;
    cout << endl;

    cout << "Is the person still alive? (y/n) ";
    while (answer != 'n' || answer != 'y'){
        cin >> answer;
    }
    if (answer == 'n'||answer == 'N'){
        cout << "\nYear of Death: ";
        cin >> scientist1.yearOfDeath;
    }
    cout << endl;

    subject.push_back(scientist1);

}
