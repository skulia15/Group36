#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "services/scientistservice.h"
#include "services/computerservice.h"
#include "services/linkservice.h"

/**
 * @brief Holds commands that are available in the UI
 */

enum command {
    menu,
    add,
    display,
    search,
    sort,
    back,
    quit,
    unknown
};

enum commandType {
    none,
    scientist,
    computer,
    scientistComputerLink
};

class ConsoleUI
{
public:
    ConsoleUI();

    int start();

private:

    /**
     * @brief display serves as a router to according display functions
     */
    void display();

    void displayMenu();

    void displayAddScientistMenu();
    void displayAddComputerMenu();
    void displayAddScientistComputerMenu();

    void displayAllScientists();
    void displayAllComputers();

    void displaySearchMenu(std::string typeToSearchFor);

    void displayScientistSortMenu();
    void displayComputerSortMenu();

    void displayUnknownCommandMenu();

    void displayScientists(std::vector<Scientist> scientists);
    void displayComputers(std::vector<Computer> computers);

    void displayChooseCommandType();
    void displayError(std::string error);

    /**
     * @brief readInput handles user input by settings commands or processing it
     */
    void readInput();

    void noneCommandHandler(std::string userInput);

    /**
     * @brief addCommandHandler calls an add function and notifies the user how it went
     * @param userInput the input the user is trying to create an object from
     */
    void addCommandHandler(std::string userInput);

    /**
     * @brief sortCommandHandler calls a sort function and notifies the user how it went
     * @param userInput the input the user is trying to change sort from
     */
    void sortCommandHandler(std::string userInput);

    /**
     * @brief searchCommandHandler calls a relevant service depending on last command type to display a list of filtered users
     * @param userInput a string sent as input to the search function
     */
    void searchCommandHandler(std::string userInput);

    /**
     * @brief addScientist attempts to add a scientist
     * @param data A string containing the user input
     * @return true if it was a success, false if it was a failure
     */
    bool addScientist(std::string data);

    /**
     * @brief addComputer attempts to add a computer
     * @param data A string containing the user input
     * @return true if it was a success, false if it was a failure
     */
    bool addComputer(std::string data);

    /**
     * @brief addLink attempts to add a computer
     * @param data A string containing the user input
     * @return true if it was a success, false if it was a failure
     */
    bool addLink(std::string data);

    /**
     * @brief setScientistSort attempts to change how scientists will be sorted based on userinput
     * @param sortCommand the sort rule, rules are stored in constants.h
     * @return true if it was a success, false if it was a failure
     */
    bool setScientistSort(std::string sortCommand);

    /**
     * @brief setComputerSort attempts to change how computers will be sorted based on userinput
     * @param sortCommand the sort rule, rules are stored in constants.h
     * @return true if it was a success, false if it was a failure
     */
    bool setComputerSort(std::string sortCommand);

    ScientistService scientistService;
    ComputerService computerService;
    LinkService linkService;

    enum command lastCommand;
    enum commandType lastCommandType;

    std::string sortScientistsBy;
    bool sortScientistsAscending;

    std::string sortComputersBy;
    bool sortComputersAscending;
};

#endif // CONSOLEUI_H
