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

int main()
{ 
    vector<scientists> subject;

    subject.push_back(scientists());

    cout << "hello";

    /*person1.inputName();
    person1.inputSex();
    person1.inputYoB();
    person1.inputYoD();*/


    return 0;
}

