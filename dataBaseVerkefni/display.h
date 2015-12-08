#ifndef DISPLAY_H
#define DISPLAY_H
#include "connectiontodatabase.h"
using namespace std;


class display{
public:
    display();
    void showResult();
    void cpuShowResult();
   // friend ostream& operator<<(ostream& out, display acc);
private:
};

#endif // DISPLAY_H
