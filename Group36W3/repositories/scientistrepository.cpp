#include "scientistrepository.h"
#include "utilities/utils.h"
#include "utilities/constants.h"

#include <cstdlib>
#include <sstream>
#include <QString>

using namespace std;

ScientistRepository::ScientistRepository()
{
    db = utils::getDatabaseConnection();
}

vector<Scientist> ScientistRepository::queryScientists(QString sqlQuery)
{
    vector<Scientist> scientists;

    db.open();

    if (!db.isOpen())
    {
        return scientists;
    }

    QSqlQuery query(db);

    if (!query.exec(sqlQuery))
    {
        return scientists;
    }

    while (query.next())
    {
        int id = query.value("id").toUInt();
        string name = query.value("name").toString().toStdString();
        enum sexType sex = utils::intToSex(query.value("sex").toInt());
        int yearBorn = query.value("yearBorn").toInt();
        int yearDied = query.value("yearDied").toInt();

        scientists.push_back(Scientist(id, name, sex, yearBorn, yearDied));
    }

    db.close();

    for (unsigned int i = 0; i < scientists.size(); i++)
    {
        Scientist currentScientist = scientists.at(i);
        currentScientist.setComputers(queryComputersByScientist(currentScientist));
    }

    return scientists;
}

vector<Scientist> ScientistRepository::getAllScientists(string orderBy, bool orderAscending)
{
    string ascending = ((orderAscending) ? "ASC" : "DESC");

    stringstream sqlQuery;
    sqlQuery << "SELECT * FROM Scientists ORDER BY " << orderBy << " " << ascending;

    return queryScientists(QString::fromStdString(sqlQuery.str()));
}

vector<Scientist> ScientistRepository::searchForScientists(string searchTerm)
{
    stringstream sqlQuery;
    sqlQuery << "SELECT * FROM Scientists WHERE name LIKE '%" << searchTerm << "%"
           << "' UNION "
           << "SELECT * FROM Scientists WHERE yearBorn LIKE '%" << searchTerm << "%"
           << "' UNION "
           << "SELECT * FROM Scientists WHERE yearDied LIKE '%" << searchTerm << "%'";

    return queryScientists(QString::fromStdString(sqlQuery.str()));
}

bool ScientistRepository::addScientist(Scientist scientist)
{
    db.open();

    if (!db.isOpen())
    {
        return false;
    }

    QSqlQuery query(db);

    stringstream sqlQuery;
    sqlQuery << "INSERT INTO Scientists (name, sex, yearBorn, yearDied) VALUES ("
             << "'" << scientist.getName() << "', "
             << scientist.getSex() << ", "
             << scientist.getYearBorn() << ", "
             << scientist.getYearDied()
             << ")";

    if (!query.exec(QString::fromStdString(sqlQuery.str())))
    {
        return false;
    }

    db.close();

    return true;
}

std::vector<Computer> ScientistRepository::queryComputersByScientist(Scientist scientist)
{
    vector<Computer> computers;

    db.open();

    if (!db.isOpen())
    {
        return computers;
    }

    QSqlQuery query(db);

    stringstream sqlQuery;
    sqlQuery << "SELECT s.* FROM ScientistComputerConnections scc ";
    sqlQuery << "JOIN Computers c ";
    sqlQuery << "ON c.id = scc.computerId ";
    sqlQuery << "WHERE scc.scientistId = " << scientist.getId();

    query.exec(QString::fromStdString(sqlQuery.str()));

    while (query.next())
    {
        int id = query.value("id").toUInt();
        string name = query.value("name").toString().toStdString();
        enum computerType type = utils::intToComputerType(query.value("type").toInt());
        int yearBuilt = query.value("yearBuilt").toInt();

        computers.push_back(Computer(id, name, type, yearBuilt));
    }

    return computers;
}
