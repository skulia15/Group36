#ifndef SEARCH
#define SEARCH

#include "connectiontodatabase.h"

using namespace std;

class searchData{
public:
    searchData();
    void searchFirstName();
    void searchLastName();
    void searchBirthYear();

private:
    string inputName;
    string inputYear;

    string id;
    string firstName;
    string lastName;
    string sex;
    int YoB;
    int YoD;

};

#endif // SEARCH

