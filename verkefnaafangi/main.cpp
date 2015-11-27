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

void inputInfo();

int main()
{ 
    vector<scientists> subject;

    subject.push_back(scientists()); //default constructor

    //callDefaultMenu();

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

void inputInfo(){

}
