#ifndef COMPUTERS_H
#define COMPUTERS_H
#include "gui.h"
#include "manualInsertScientist.h"
#include "connectiontodatabase.h"
#include <iostream>

using namespace std;

class Scientists{
public:
    Scientists();
    void manualInput();
    //friend ostream& operator<<(ostream& out, Computers acc);

private:
    string id;
    string firstName;
    string lastName;
    string sex;
    string YoB;
    string YoD;




};

#endif //COMPUTERS_H
