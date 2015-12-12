#ifndef SCIENTISTREPOSITORY_H
#define SCIENTISTREPOSITORY_H

#include <QtSql>
#include <vector>
#include <string>

#include "models/scientist.h"

/**
 * @brief The ScientistRepository class handles reading and writing scientists to and from a database
 */
class ScientistRepository
{
public:
    ScientistRepository();

    /**
     * @brief getAllScientists fetches all scientists from the database
     * @return a vector containing all scientists in the database
     */
    std::vector<Scientist> getAllScientists(std::string orderBy, bool orderAscending);

    /**
     * @brief searchForScientists fetches all scientists from the database and filters them on searchTerm
     * @param searchTerm Contains the input that the user wishes to filter on
     * @return a vector of scientists filtered by searchTerm
     */
    std::vector<Scientist> searchForScientists(std::string searchTerm);

    /**
     * @brief addScientist saves a scientist model to the database
     * @param scientist The model to save
     * @return true if it was a success, false if it was a failure
     */
    bool addScientist(Scientist scientist);

private:

    /**
     * @brief queryComputersByScientist queries the database for computers by scientists
     * @param scientist A scientist to query by
     * @return a vector of computers
     */
    std::vector<Computer> queryComputersByScientist(Scientist scientist);

    /**
     * @brief queryScientists queries the database for scientists
     * @param sqlQuery A query which returns scientists
     * @return a vector of scientists
     */
    std::vector<Scientist> queryScientists(QString sqlQuery);

    QSqlDatabase db;
};

#endif // SCIENTISTREPOSITORY_H
