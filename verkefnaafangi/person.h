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
private:
    string firstName;
    string middleName;
    string lastName;
    char sex;
    int yearOfBirth;
    int yearOfDeath;
};

#endif // PERSON_H
