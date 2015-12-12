#ifndef SCIENTISTSERVICE_H
#define SCIENTISTSERVICE_H

#include "repositories/scientistrepository.h"

/**
 * @brief The ScientistService acts as a middle layer between the UI and Data layers
 */

class ScientistService
{
public:
    ScientistService();

    /**
     * @brief getAllScientists fetches scientists from the ScientistRepository
     * @param orderBy Which column the scientists should be sorted on
     * @param orderAscending Should the list be sorted in ascending order?
     * @return a vector containing all scientists in the repository
     */
    std::vector<Scientist> getAllScientists(std::string orderBy, bool orderAscending);

    /**
     * @brief searchForScientists fetches all scientists filtered on searchTerm
     * @param searchTerm Contains the input that the user wishes to filter on
     * @return a vector of scientists filtered by searchTerm
     */
    std::vector<Scientist> searchForScientists(std::string searchTerm);

    /**
     * @brief addScientist saves a scientist model to a database
     * @param scientist The model to save
     * @return true if it was a success, false if it was a failure
     */
    bool addScientist(Scientist scientist);
private:
    ScientistRepository scientistRepo;
};

#endif // SCIENTISTSERVICE_H
