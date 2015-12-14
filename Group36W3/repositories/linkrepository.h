#ifndef LINKREPOSITORY_H
#define LINKREPOSITORY_H

#include <QtSql>
#include <vector>
#include <string>

/**
 * @brief The LinkRepository handles connections between scientists and computers in the database
 */

class LinkRepository
{
public:
    LinkRepository();

    /**
     * @brief addLink saves a link between scientist and computer to the database
     * @param scientistId The scientist id to connect to
     * @param computerId The computer id to connect to
     * @return true if it was a success, false if it was a failure
     */
    bool addLink(std::string scientistId, std::string computerId);
private:
    QSqlDatabase db;
};

#endif // LINKREPOSITORY_H
