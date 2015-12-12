#include "consoleui.h"
#include "utilities/constants.h"
#include "utilities/utils.h"

#include <iostream>
#include <iomanip>

using namespace std;

ConsoleUI::ConsoleUI()
{
    lastCommand = command::menu;
    lastCommandType = commandType::none;

    sortScientistsBy = "name";
    sortScientistsAscending = true;

    sortComputersBy = "name";
    sortComputersAscending = true;
}

int ConsoleUI::start()
{
    while(lastCommand != command::quit)
    {
        display();
        readInput();
    }

    return 0;
}

void ConsoleUI::display()
{
    switch (lastCommand)
    {
        case command::menu:
            displayMenu();
            break;
        case command::add:
        {
            if (lastCommandType == commandType::none)
            {
                displayChooseCommandType();
            }
            else if (lastCommandType == commandType::scientist)
            {
                displayAddScientistMenu();
            }
            else if (lastCommandType == commandType::computer)
            {
                displayAddComputerMenu();
            }
            else if (lastCommandType == commandType::scientistComputerLink)
            {
                displayAddScientistComputerMenu();
            }
            break;
        }
        case command::display:
        {
            if (lastCommandType == commandType::none)
            {
                displayChooseCommandType();
            }
            else if (lastCommandType == commandType::scientist)
            {
                displayAllScientists();
            }
            else if (lastCommandType == commandType::computer)
            {
                displayAllComputers();
            }
            break;
        }
        case command::search:
        {
            if (lastCommandType == commandType::none)
            {
                displayChooseCommandType();
            }
            else if (lastCommandType == commandType::scientist)
            {
                displaySearchMenu("scientist");
            }
            else if (lastCommandType == commandType::computer)
            {
                displaySearchMenu("computer");
            }
            break;
        }
        case command::sort:
        {
            if (lastCommandType == commandType::none)
            {
                displayChooseCommandType();
            }
            else if (lastCommandType == commandType::scientist)
            {
                displayScientistSortMenu();
            }
            else if (lastCommandType == commandType::computer)
            {
                displayComputerSortMenu();
            }
            break;
        }
        default:
            displayUnknownCommandMenu();
            break;
    }
}

void ConsoleUI::readInput()
{
    if (lastCommand == command::display)
    {
        lastCommand = command::sort;
        return;
    }

    string userInput;
    getline(cin, userInput);

    cout << "\n\n";

    bool shouldTreatInputAsCommand = (lastCommand != command::search);

    if (userInput == "display" && shouldTreatInputAsCommand)
    {
        lastCommand = command::sort;
    }
    else if (userInput == "add" && shouldTreatInputAsCommand)
    {
        lastCommand = command::add;
    }
    else if (userInput == "search" && shouldTreatInputAsCommand)
    {
        lastCommand = command::search;
    }
    else if (userInput == "back")
    {
        lastCommand = command::menu;
        lastCommandType = commandType::none;
    }
    else if (userInput == "quit")
    {
        lastCommand = command::quit;
    }
    else
    {
        if (lastCommandType == commandType::none)
        {
            noneCommandHandler(userInput);
        }
        else if (lastCommand == command::add)
        {
            addCommandHandler(userInput);
        }
        else if (lastCommand == command::sort)
        {
            sortCommandHandler(userInput);
        }
        else if (lastCommand == command::search)
        {
            searchCommandHandler(userInput);
        }
        else
        {
            lastCommand = command::unknown;
        }
    }
}

void ConsoleUI::noneCommandHandler(string userInput)
{
    if (userInput == "1")
    {
        lastCommandType = commandType::scientist;
    }
    else if (userInput == "2")
    {
        lastCommandType = commandType::computer;
    }
    else if (userInput == "3")
    {
        lastCommandType = commandType::scientistComputerLink;
    }
    else
    {
        displayError("Please select one of the options.");
    }
}

void ConsoleUI::addCommandHandler(string userInput)
{
    bool success = false;

    if (lastCommandType == commandType::scientist)
    {
        success = addScientist(userInput);
    }
    else if (lastCommandType == commandType::computer)
    {
        success = addComputer(userInput);
    }
    else if (lastCommandType == commandType::scientistComputerLink)
    {
        success = addLink(userInput);
    }

    if (success)
    {
        cout << "Success.\n\n";
        lastCommand = command::menu;
    }
    else
    {
        displayError("Input was not correct.");
    }
}

void ConsoleUI::sortCommandHandler(string userInput)
{
    bool success = false;

    if (lastCommandType == commandType::scientist)
    {
        success = setScientistSort(userInput);
    }
    else if (lastCommandType == commandType::computer)
    {
        success = setComputerSort(userInput);
    }

    if (success)
    {
        lastCommand = command::display;
    }
    else
    {
        displayError("Your input did not match any of the sort commands.");
    }
}

void ConsoleUI::searchCommandHandler(string userInput)
{
    if (lastCommandType == commandType::scientist)
    {
        displayScientists(scientistService.searchForScientists(userInput));
    }
    else if (lastCommandType == commandType::computer)
    {
        displayComputers(computerService.searchForComputers(userInput));
    }
    else
    {
        displayChooseCommandType();
    }
}

void ConsoleUI::displayMenu()
{
    cout << "Enter a command:\n\n";
    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << "add:" << "Adds a scientist or a computer\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << "display:" << "Displays scientists or computers\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << "search:" << "Search for a scientist or a computer\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << "quit:" << "Quits the program\n\n";

    cout << "Command: ";
}

void ConsoleUI::displayAddScientistMenu()
{
    cout << "To add a scientist, type in:\n";
    cout << "Name,sex,yearBorn,yearDied (optional)\n";
    cout << "Comma separated like in the example above.\n\n";
    cout << "If you would like to go back to the main menu, please type: back\n";
    cout << "Input: ";
}

void ConsoleUI::displayAddComputerMenu()
{
    cout << "To add a computer, type in:\n";
    cout << "Name,type,yearBuilt (optional)\n";
    cout << "Comma separated like in the example above.\n\n";
    cout << "If you would like to go back to the main menu, please type: back\n";
    cout << "Input: ";
}

void ConsoleUI::displayAddScientistComputerMenu()
{
    cout << "To add a link between a scientist and a computer, type in:\n";
    cout << "ScientistId,ComputerId\n";
    cout << "Comma separated like in the example above.\n\n";
    cout << "If you would like to go back to the main menu, please type: back\n";
    cout << "Input: ";
}

void ConsoleUI::displayAllScientists()
{
    vector<Scientist> scientists = scientistService.getAllScientists(sortScientistsBy, sortScientistsAscending);

    displayScientists(scientists);

    cout << '\n';

    lastCommand = command::display;
}

void ConsoleUI::displayAllComputers()
{
    vector<Computer> computers = computerService.getAllComputers(sortComputersBy, sortComputersAscending);

    displayComputers(computers);

    cout << '\n';

    lastCommand = command::display;
}

void ConsoleUI::displaySearchMenu(string typeToSearchFor)
{
    cout << "Search for a " << typeToSearchFor << ".\n\n";

    cout << "If you would like to go back to the main menu, please type: back\n";
    cout << "Input: ";
}

void ConsoleUI::displayScientistSortMenu()
{
    cout << "How should the list be sorted:\n\n";
    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_SCIENTIST_NAME_ASCENDING << "Sorts by name, ascending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_SCIENTIST_NAME_DESCENDING << "Sorts by name, descending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_SCIENTIST_YEAR_BORN_ASCENDING << "Sorts by year born, ascending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_SCIENTIST_YEAR_BORN_DESCENDING << "Sorts by year born, descending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_SCIENTIST_YEAR_DIED_ASCENDING << "Sorts by year died, ascending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_SCIENTIST_YEAR_DIED_DESCENDING << "Sorts by year died, descending.\n\n";

    cout << "If you would like to go back to the main menu, please type: back\n";

    cout << "Command: ";
}

void ConsoleUI::displayComputerSortMenu()
{
    cout << "How should the list be sorted:\n\n";
    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_COMPUTER_NAME_ASCENDING << "Sorts by name, ascending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_COMPUTER_NAME_DESCENDING << "Sorts by name, descending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_COMPUTER_TYPE_ASCENDING << "Sorts by computer type, ascending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_COMPUTER_TYPE_DESCENDING << "Sorts by computer type, descending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_COMPUTER_YEAR_BUILT_ASCENDING << "Sorts by year built, ascending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_COMPUTER_YEAR_BUILT_DESCENDING << "Sorts by year built, descending.\n\n";

    cout << "If you would like to go back to the main menu, please type: back\n";

    cout << "Command: ";
}

void ConsoleUI::displayUnknownCommandMenu()
{
    displayError("Unknown command.");
    cout << "Command: ";
}

void ConsoleUI::displayScientists(std::vector<Scientist> scientists)
{
    if (scientists.size() == 0)
    {
        cout << "No scientist found.\n";
        return;
    }

    cout << "\nPrinting all scientists:\n";

    cout << setw(5)  << std::left << "Id:"
         << setw(20) << std::left << "Name:"
         << setw(8)  << std::left << "Sex:"
         << setw(12) << std::left << "Year born:"
         << setw(12) << std::left << "Year died:"
         << setw(20) << std::left << "Computers:" << endl;

    for (unsigned int i = 0; i < scientists.size(); i++) {
        string scientistSex = (scientists.at(i).getSex() == sexType::male) ? "Male" : "Female";

        int yearDied = scientists.at(i).getYearDied();
        string died = (yearDied == constants::YEAR_UNSELECTED_VALUE) ? "Alive" : utils::intToString(yearDied);
        std::vector<Computer*> computers = scientists.at(i).getComputers();

        cout << setw(5)  << std::left << scientists.at(i).getId()
             << setw(20) << std::left << scientists.at(i).getName()
             << setw(8)  << std::left << scientistSex
             << setw(12) << std::left << scientists.at(i).getYearBorn()
             << setw(12) << std::left << died;
        for(unsigned int j = 0; j < computers.size(); j++)
        {
            if(j == 0)
            {
                cout << setw(20) << std::left << computers.at(j)->getName() << endl;
            }
            else
            {
                cout << setw(55) << " " << setw(20) << std::left << computers.at(j)->getName() << endl;
            }
        }
    }
}

void ConsoleUI::displayComputers(std::vector<Computer> computers)
{
    if (computers.size() == 0)
    {
        cout << "No computer found.\n";
        return;
    }

    cout << "\nPrinting all computers:\n";

    cout << setw(5)  << std::left << "Id:"
         << setw(20) << std::left << "Name:"
         << setw(15) << std::left << "Type:"
         << setw(15) << std::left << "Year built:"
         << setw(20) << std::left << "Scientists:" << endl;

    for (unsigned int i = 0; i < computers.size(); i++) {
        int yearBuilt = computers.at(i).getYearBuilt();
        string built = (yearBuilt == constants::YEAR_UNSELECTED_VALUE) ? "Not built" : utils::intToString(yearBuilt);
        std::vector<Scientist> scientists = computers.at(i).getScientists();

        cout << setw(5)  << std::left << computers.at(i).getId()
             << setw(20) << std::left << computers.at(i).getName()
             << setw(15) << std::left << computers.at(i).getTypeName()
             << setw(15) << std::left << built;
        for(unsigned int j = 0; j < scientists.size(); j++)
        {
            if(j == 0)
            {
                cout << setw(20) << std::left << scientists.at(j).getName() << endl;
            }
            else
            {
                cout << setw(55) << " " << setw(20) << std::left << scientists.at(j).getName() << endl;
            }
        }
    }
}

bool ConsoleUI::addScientist(string data)
{
    vector<string> fields = utils::split(data, ',');

    if (fields.size() > 2 && fields.size() < 5)
    {
        string name = fields.at(0);

        enum sexType sex;
        if (fields.at(1) == "male")
        {
            sex = sexType::male;
        }
        else
        {
            sex = sexType::female;
        }

        int yearBorn = utils::stringToInt(fields.at(2));

        if (fields.size() == 3)
        {
            return scientistService.addScientist(Scientist(name, sex, yearBorn));
        }
        else
        {
            int yearDied = utils::stringToInt(fields.at(3));

            return scientistService.addScientist(Scientist(name, sex, yearBorn, yearDied));
        }
    }

    return false;
}

bool ConsoleUI::addComputer(string data)
{
    vector<string> fields = utils::split(data, ',');

    if (fields.size() > 1 && fields.size() < 4)
    {
        string name = fields.at(0);

        enum computerType type;
        string typeString = fields.at(1);
        if (typeString == "electronic")
        {
            type = computerType::electronic;
        }
        else if (typeString == "mechatronic")
        {
            type = computerType::mechatronic;
        }
        else if (typeString == "transistor")
        {
            type = computerType::transistor;
        }
        else
        {
            type = computerType::other;
        }

        if (fields.size() == 2)
        {
            return computerService.addComputer(Computer(name, type));
        }
        else
        {
            int yearBuilt = utils::stringToInt(fields.at(2));
            return computerService.addComputer(Computer(name, type, yearBuilt));
        }
    }

    return false;
}

bool ConsoleUI::addLink(string data)
{
    vector<string> fields = utils::split(data, ',');

    if (fields.size() > 1 && fields.size() < 4)
    {
        string scientistId = fields.at(0);
        string computerId = fields.at(1);

        return linkService.addLink(scientistId, computerId);
    }

    return false;
}

bool ConsoleUI::setScientistSort(string sortCommand)
{
    if (sortCommand == constants::SORT_SCIENTIST_NAME_ASCENDING)
    {
        sortScientistsBy = "name";
        sortScientistsAscending = true;
    }
    else if (sortCommand == constants::SORT_SCIENTIST_NAME_DESCENDING)
    {
        sortScientistsBy = "name";
        sortScientistsAscending = false;
    }
    else if (sortCommand == constants::SORT_SCIENTIST_YEAR_BORN_ASCENDING)
    {
        sortScientistsBy = "yearBorn";
        sortScientistsAscending = true;
    }
    else if (sortCommand == constants::SORT_SCIENTIST_YEAR_BORN_DESCENDING)
    {
        sortScientistsBy = "yearBorn";
        sortScientistsAscending = false;
    }
    else if (sortCommand == constants::SORT_SCIENTIST_YEAR_DIED_ASCENDING)
    {
        sortScientistsBy = "yearDied";
        sortScientistsAscending = true;
    }
    else if (sortCommand == constants::SORT_SCIENTIST_YEAR_DIED_DESCENDING)
    {
        sortScientistsBy = "yearDied";
        sortScientistsAscending = false;
    }
    else
    {
        return false;
    }

    return true;
}

bool ConsoleUI::setComputerSort(std::string sortCommand)
{
    if (sortCommand == constants::SORT_COMPUTER_NAME_ASCENDING)
    {
        sortComputersBy = "name";
        sortComputersAscending = true;
    }
    else if (sortCommand == constants::SORT_COMPUTER_NAME_DESCENDING)
    {
        sortComputersBy = "name";
        sortComputersAscending = false;
    }
    else if (sortCommand == constants::SORT_COMPUTER_TYPE_ASCENDING)
    {
        sortComputersBy = "type";
        sortComputersAscending = true;
    }
    else if (sortCommand == constants::SORT_COMPUTER_TYPE_DESCENDING)
    {
        sortComputersBy = "type";
        sortComputersAscending = false;
    }
    else if (sortCommand == constants::SORT_COMPUTER_YEAR_BUILT_ASCENDING)
    {
        sortComputersBy = "yearBuilt";
        sortComputersAscending = true;
    }
    else if (sortCommand == constants::SORT_COMPUTER_YEAR_BUILT_DESCENDING)
    {
        sortComputersBy = "yearBuilt";
        sortComputersAscending = false;
    }
    else
    {
        return false;
    }

    return true;
}

void ConsoleUI::displayChooseCommandType()
{
    cout << "Before continuing, please choose a type:\n";
    cout << "1: Scientist\n";
    cout << "2: Computer\n";
    cout << "3: Link\n";
    cout << "Choice: ";
}

void ConsoleUI::displayError(std::string error)
{
    cout << "There was an error: " << error << "\n";
    cout << "Please try again or type 'back' to go back.\n\n";
}
