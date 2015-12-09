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
<<<<<<< HEAD
    void searchKeyword();
=======
    void searchCpuName();
    void searchYearBuilt();
    void searchCpuType();
>>>>>>> d1942f5ce805af0ee9580fb53a5a80500949b0e6

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

