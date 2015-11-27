//gætum þurft að nota seinna, þori ekki að henda


#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>

using namespace std;

class person{

public:
    person();
    void inputName();
    void inputSex();
    void inputYoB();
    void inputYoD();
private:
    string firstName;
    string middleName;
    string lastName;
    char personSex;
    int yearOfBirth;
    int yearOfDeath;
};

#endif // PERSON_H
