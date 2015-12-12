#ifndef COMPUTERSERVICE_H
#define COMPUTERSERVICE_H

#include <vector>
#include "repositories/computerrepository.h"

/**
 * @brief The ComputerService acts as a middle layer between the UI and Data layers
 */

class ComputerService
{
public:
    ComputerService();

    /**
     * @brief getAllComputers fetches computers from the ComputerRepository
     * @param orderBy Which column the scientists should be sorted on
     * @param orderAscending Should the list be sorted in ascending order?
     * @return a vector containing all scientists in the repository
     */
    std::vector<Computer> getAllComputers(std::string orderBy, bool orderAscending);

    /**
     * @brief searchForComputers fetches all computers filtered on searchTerm
     * @param searchTerm Contains the input that the user wishes to filter on
     * @return a vector of computers filtered by searchTerm
     */
    std::vector<Computer> searchForComputers(std::string searchTerm);

    /**
     * @brief addComputer saves a computer model to a database
     * @param computer The model to save
     * @return true if it was a success, false if it was a failure
     */
    bool addComputer(Computer computer);

private:
    ComputerRepository computerRepo;
};

#endif // COMPUTERSERVICE_H
