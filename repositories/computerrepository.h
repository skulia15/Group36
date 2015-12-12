#ifndef COMPUTERREPOSITORY_H
#define COMPUTERREPOSITORY_H

#include <QtSql>
#include <vector>
#include "models/computer.h"

/**
 * @brief The ComputerRepository class handles reading and writing computers to and from a database
 */

class ComputerRepository
{
public:
    ComputerRepository();

    /**
     * @brief getAllComputers fetches all computers from the database
     * @return a vector containing all computers in the database
     */
    std::vector<Computer> getAllComputers(std::string orderBy, bool orderAscending);

    /**
     * @brief searchForComputers fetches all computers from the database and filters them on searchTerm
     * @param searchTerm Contains the input that the user wishes to filter on
     * @return a vector of computers filtered by searchTerm
     */
    std::vector<Computer> searchForComputers(std::string searchTerm);

    /**
     * @brief addComputer saves a computer model to the database
     * @param computer The model to save
     * @return true if it was a success, false if it was a failure
     */
    bool addComputer(Computer computer);

private:

    /**
     * @brief queryScientistsByComputer queries the database for scientists by computers
     * @param computer A computer to query by
     * @return a vector of scientists
     */
    std::vector<Scientist> queryScientistsByComputer(Computer computer);

    /**
     * @brief queryComputers queries the database for computers
     * @param sqlQuery A query which returns computers
     * @return a vector of computers
     */
    std::vector<Computer> queryComputers(QString sqlQuery);

    QSqlDatabase db;
};

#endif // COMPUTERREPOSITORY_H
