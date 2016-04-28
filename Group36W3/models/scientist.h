#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <string>
#include <vector>

/**
 * @brief The data model for scientists
 */

// Forward declaration to let Scientist know that Computer exists
class Computer;

class Scientist
{
public:
    Scientist();
    ~Scientist();
    Scientist(std::string name, int sex, int yearBorn);
    Scientist(std::string name, int sex, int yearBorn, int yearDied);
    Scientist(unsigned int id, std::string name, int sex, int yearBorn, int yearDied);

    unsigned int getId();
    std::string getName() const;
    int getSex() const;
    int getYearBorn() const;
    int getYearDied() const;
    std::vector<Computer*> getComputers() const;

    void setComputers(std::vector<Computer> computers);

    bool contains(std::string searchTerm);

private:
    void destroyComputers();

    unsigned int id;
    std::string name;
    int sex;
    int yearBorn;
    int yearDied;

    // Computer now has to be a pointer
    std::vector<Computer*> computers;
};

#endif // SCIENTIST_H
