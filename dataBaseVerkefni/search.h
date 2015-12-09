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
    void substring();

=======
>>>>>>> bce005b2e8d1b72f337f0424b4f70f302bbd74d2
private:
    string inputName;
    string inputYear;
    string id;
    string firstName;
    string lastName;
    string sex;
    int YoB;
    int YoD;
<<<<<<< HEAD

    string phrase;

=======
>>>>>>> bce005b2e8d1b72f337f0424b4f70f302bbd74d2
};

#endif // SEARCH

