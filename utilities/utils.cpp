#include "utilities/utils.h"
#include "utilities/constants.h"

#include <sstream>
#include <cstdlib>

namespace utils {
    std::vector<std::string> split(std::string line, char delimeter)
    {
        std::vector<std::string> result;

        std::string currentWord = "";

        for (unsigned int i = 0; i < line.length(); i++)
        {
            char currentChar = line[i];

            if (currentChar == delimeter)
            {
                if  (currentWord.length())
                {
                    result.push_back(currentWord);
                    currentWord = "";
                }
            }
            else
            {
                if (currentChar != '\n')
                {
                    currentWord += currentChar;
                }
            }
        }

        if (currentWord.length())
        {
            result.push_back(currentWord);
        }

        return result;
    }

    int stringToInt(std::string str)
    {
        return atoi(str.c_str());
    }

    std::string stringToLower(std::string str)
    {
        std::string result = "";

        for (unsigned int i = 0; i < str.length(); i++)
        {
            char currentCharacter = str[i];

            // http://www.asciitable.com/
            if (currentCharacter <= 90 && currentCharacter >= 65)
            {
                result += currentCharacter + 32;
            }
            else
            {
                result += currentCharacter;
            }
        }

        return result;
    }

    std::string intToString(int number)
    {
        std::stringstream stream;
        stream << number;
        return stream.str();
    }

    enum sexType intToSex(int number)
    {
        return static_cast<enum sexType>(number);
    }

    enum computerType intToComputerType(int number)
    {
        return static_cast<enum computerType>(number);
    }

    enum sexType stringToSex(std::string str)
    {
        return intToSex(stringToInt(str));
    }

    QSqlDatabase getDatabaseConnection()
    {
        QString connectionName = "Smuu";
        QSqlDatabase db;

        if(QSqlDatabase::contains(connectionName))
        {
            db = QSqlDatabase::database(connectionName);
        }
        else
        {
            db = QSqlDatabase::addDatabase(constants::DATABASE_TYPE.c_str(), connectionName);
            db.setDatabaseName(constants::DATABASE_NAME.c_str());

            db.open();
        }

        return db;
    }
}
