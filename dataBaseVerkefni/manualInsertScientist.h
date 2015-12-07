#ifndef COMPUTERS_H
#define COMPUTERS_H
#include "gui.h"
#include "manualInsertScientist.h"
#include "connectiontodatabase.h"
#include <iostream>
using namespace std;

class Scientists
{
public:
    Scientists();
 void manualInput();
    void display();
    //friend ostream& operator<<(ostream& out, Computers acc);

private:

    string firstName;
    string lastName;
    int yob;
    int yod;

};

#endif //COMPUTERS_H
