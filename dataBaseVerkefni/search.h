#ifndef SEARCH
#define SEARCH

#include "connectiontodatabase.h"

using namespace std;

class Searchdata{
public:
    Searchdata();
    void searchFirstName();
    void searchLastName();
    void searchBirthYear();
    void substring();

private:
    string inputName;
    string inputYear;

    string id;
    string firstName;
    string lastName;
    string sex;
    int YoB;
    int YoD;

    string phrase;

};

#endif // SEARCH

