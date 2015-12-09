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

    void substring(); //þarf þetta?


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

