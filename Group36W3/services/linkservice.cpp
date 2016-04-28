#include "linkservice.h"

#include <string>

using namespace std;

LinkService::LinkService()
{

}

bool LinkService::addLink(string scientistId, string computerId)
{
    return linkRepo.addLink(scientistId, computerId);
}

bool LinkService::removeLink(string scientistId, string computerId)
{
    return linkRepo.removeLink(scientistId, computerId);
}
