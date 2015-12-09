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
    void searchKeyword();
    void searchCpuName();
    void searchYearBuilt();
    void searchCpuType();   
private:
    string inputName;
    string inputYear;
    string id;
    string firstName;
    string lastName;
    string sex;
    string phrase;
    int YoB;
    int YoD;
};

#endif // SEARCH

