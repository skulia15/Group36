#ifndef UTILS_H
#define UTILS_H

#include <cstdlib>
#include <sstream>
#include <vector>
#include <string>
#include <QtSql>

#include "models/scientist.h"
#include "models/computer.h"

/**
 * This file contains reusable utility functions used throughout the application
 */

namespace utils {    
    std::vector<std::string> split(std::string line, char delimeter);

    int stringToInt(std::string str);

    std::string stringToLower(std::string str);

    std::string intToString(int number);

    enum sexType intToSex(int number);

    enum computerType intToComputerType(int number);

    enum sexType stringToSex(std::string str);

    QSqlDatabase getDatabaseConnection();
}

#endif // UTILS_H

