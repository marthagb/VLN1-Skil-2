#include "servicelayer.h"



ServiceLayer::ServiceLayer()
{

}

vector<Persons> ServiceLayer::listScientists()
{
    return dl.getScientistVector();
}

vector<Computer> ServiceLayer::listComputers()
{
    return dl.getComputerVector();
}

vector<Association> ServiceLayer::listAssociations()
{
    return dl.getAssociationVector();
}

void ServiceLayer::sortScientists(int orderBy, int ascOrDesc)
{
    dl.readScientists(orderBy, ascOrDesc);
}

void ServiceLayer::sortComputers(int orderBy, int ascOrDesc)
{
    dl.readComputers(orderBy, ascOrDesc);
}

void ServiceLayer::sortAssociations(int orderBy, int ascOrDesc)
{
    dl.readAssociations(orderBy, ascOrDesc);
}

vector<int> ServiceLayer::searchScientistByName(const string name)
{
    return dl.searchScientistByName(name);
}

vector<int> ServiceLayer::searchScientistByGender(const char gender)
{
    return dl.searchScientistByGender(gender);
}

vector<int> ServiceLayer::searchScientistByBirthYear(const int year)
{
    return dl.searchScientistByBirthYear(year);
}

vector<int> ServiceLayer::searchScientistByYearRange(const int f, const int l)
{
    return dl.searchScientistByYearRange(f, l);
}

vector<int> ServiceLayer::searchComputerByName(const string name)
{
    return dl.searchComputerByName(name);
}

vector<int> ServiceLayer::searchComputerByYearMade(const int year)
{
    return dl.searchComputerByYearMade(year);
}

vector<int> ServiceLayer::searchComputerByYearRange(const int f, const int l)
{
    return dl.searchComputerByYearRange(f, l);
}

vector<int> ServiceLayer::searchComputerByType(const string type)
{
    return dl.searchComputerByType(type);
}

vector<int> ServiceLayer::searchAssocBySciName(const string sN)
{
    return dl.searchAssocBySciName(sN);
}

vector<int> ServiceLayer::searchAssocByCompName(const string cN)
{
    return dl.searchAssocByCompName(cN);
}

vector<int> ServiceLayer::searchAssocByYear(const int year)
{
    return dl.searchAssocByYear(year);
}

vector<int> ServiceLayer::searchAssocByYearRange(const int f, const int l)
{
    return dl.searchAssocByYearRange(f,l);
}

vector<int> ServiceLayer::searchAssocByCompType(const string type)
{
    return dl.searchAssocByCompType(type);
}

bool ServiceLayer::addScientist(const Persons &p)
{
    return dl.addScientist(p);
}

bool ServiceLayer::addScientistsFromFile(string input)
{
    return dl.addScientistsFromFile(input);
}

void ServiceLayer::deleteScientist(string n)
{
    dl.deleteScientist(n);
}

bool ServiceLayer::addComputer(const Computer &c)
{
    return dl.addComputer(c);
}

bool ServiceLayer::addComputersFromFile(string input)
{
    return dl.addComputersFromFile(input);
}

void ServiceLayer::deleteComputer(string n)
{
    dl.deleteComputer(n);
}

bool ServiceLayer::addAssociation(const Association& a)
{
    return dl.addAssociation(a);
}

void ServiceLayer::deleteAssociation(string sN, string cN)
{
    dl.deleteAssociation(sN, cN);
}

bool ServiceLayer::saveScientistsToFile(string input)
{
    return dl.saveScientistsToFile(input);
}


bool ServiceLayer::saveComputersToFile(string input)
{
    return dl.saveComputersToFile(input);
}

bool ServiceLayer::saveAssociationsToFile(string input)
{
    return dl.saveAssociationsToFile(input);
}

