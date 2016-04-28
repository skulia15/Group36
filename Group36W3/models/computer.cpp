#include "computer.h"
#include "utilities/constants.h"

using namespace std;

Computer::Computer()
{

}

Computer::Computer(string name, int type)
{
    id = 0;
    this->name = name;
    this->type = type;
    this->yearBuilt = constants::YEAR_UNSELECTED_VALUE;
}

Computer::Computer(string name, int type, int yearBuilt)
{
    id = 0;
    this->name = name;
    this->type = type;
    this->yearBuilt = yearBuilt;
}

Computer::Computer(unsigned int id, std::string name, int type, int yearBuilt)
{
    this->id = id;
    this->name = name;
    this->type = type;
    this->yearBuilt = yearBuilt;
}

unsigned int Computer::getId()
{
    return id;
}

string Computer::getName()
{
    return name;
}

int Computer::getYearBuilt()
{
    return yearBuilt;
}

int Computer::getType()
{
    return type;
}


bool Computer::wasBuilt()
{
    return yearBuilt != constants::YEAR_UNSELECTED_VALUE;
}

std::vector<Scientist> Computer::getScientists()
{
    return scientists;
}

void Computer::setScientists(std::vector<Scientist> newScientists)
{
    scientists = newScientists;
}
