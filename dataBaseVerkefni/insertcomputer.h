#ifndef INSERTCOMPUTER
#define INSERTCOMPUTER
#include "connectiontodatabase.h"

#include <iostream>

using namespace std;

class Computers
{
public:
    Computers();
    void insertCPU();

private:
    string cpuName;
    string built;
    int yearBuilt;
    string cpuType;

};

#endif // INSERTCOMPUTER

