#include "person.h"

person::person()
{
}

void person::inputName(){
    cout << "Person's name: ";
    cin >> firstName;
    cout << " ";
    cin >> lastName;
    cout << endl;
}

void person::inputSex(){
    cout << "Sex: (m/f)";
    cin >> personSex;
    cout << endl;
}

void person::inputYoB(){
    cout << "Year of Birth: ";
    cin >> yearOfBirth;
    cout << endl;
}

void person::inputYoD(){
    char answer;
    cout << "Is the person still alive? (y/n) ";
    cin >> answer;
    if (answer == 'n'||answer == 'N'){
        cout << "Year of Death: ";
        cin >> yearOfBirth;
    }
    cout << endl;

}
