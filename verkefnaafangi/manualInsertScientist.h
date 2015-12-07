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
<<<<<<< HEAD
    string YoB;
    string YoD;

=======
    int YoB;
    int YoD;
>>>>>>> 164d4166f55dccc8e0d01206b4ee6984ba400242
};

#endif //COMPUTERS_H
