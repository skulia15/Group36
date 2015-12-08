#ifndef INSERTCOMPUTER
#define INSERTCOMPUTER
#include "connectiontodatabase.h"

#include <iostream>

class Computers{
public:
    Computers();
    void insertCPU();
    void deleteCPU();
private:
    string cpuName;
    string built;
    int yearBuilt;
    string cpuType;
};

#endif // INSERTCOMPUTER

