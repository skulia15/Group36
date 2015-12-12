#include "scientistservice.h"

#include <algorithm>

using namespace std;

ScientistService::ScientistService()
{

}

std::vector<Scientist> ScientistService::getAllScientists(string orderBy, bool orderAscending)
{
    return scientistRepo.getAllScientists(orderBy, orderAscending);
}

std::vector<Scientist> ScientistService::searchForScientists(string searchTerm)
{
    return scientistRepo.searchForScientists(searchTerm);
}

bool ScientistService::addScientist(Scientist scientist)
{
    return scientistRepo.addScientist(scientist);
}
