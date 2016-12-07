#ifndef SERVICELAYER_H
#define SERVICELAYER_H

#include "datalayer.h"

using namespace std;

class ServiceLayer
{
    DataLayer dl;
public:
    ServiceLayer();
    vector<Persons> listScientists(int orderBy, int ascOrDesc);
    vector<Computer> listComputers(int orderBy, int ascOrDesc);
    vector<int> searchScientistByName(const string name);
    vector<int> searchScientistByGender(const char gender);
    vector<int> searchScientistByBirthYear(const int year);
    vector<int> searchScientistByYearRange(const int f, const int l);
    vector<int> searchComputerByName(const string name);
    vector <int> searchComputerByYearMade(const int year);
    vector<int> searchComputerByYearRange(const int f, const int l);
    vector<int> searchComputerByType(const string type);
    void addScientist(const Persons& p);
    bool addScientistsFromFile(string input);
    void deleteScientist(string n);
    void addComputer(const Computer& c);
    bool addComputersFromFile(string input);
    void deleteComputer(string n);
    bool saveScientistsToFile(string input);
    bool saveComputersToFile(string input);
};

#endif // SERVICELAYER_H
