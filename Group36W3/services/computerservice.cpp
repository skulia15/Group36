#include "computerservice.h"

ComputerService::ComputerService()
{

}

std::vector<Computer> ComputerService::getAllComputers(std::string orderBy, bool orderAscending)
{
    return computerRepo.getAllComputers(orderBy, orderAscending);
}

std::vector<Computer> ComputerService::searchForComputers(std::string searchTerm)
{
    return computerRepo.searchForComputers(searchTerm);
}

bool ComputerService::addComputer(Computer computer)
{
    return computerRepo.addComputer(computer);
}
