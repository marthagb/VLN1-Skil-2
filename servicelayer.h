#ifndef SERVICELAYER_H
#define SERVICELAYER_H

#include "persons.h"
#include "computer.h"
#include <vector>
#include <QtSql>

using namespace std;

class ServiceLayer
{
    QSqlDatabase db;
public:
    ServiceLayer();
    vector<Persons> readScientists(int orderBy, int ascOrDesc);
    vector<Computer> readComputers(int orderBy, int ascOrDesc);
    void addScientist(const Persons& p);
    void addComputer(const Computer& c);
    bool addScientistsFromFile(string input);
    bool addComputersFromFile(string input);
    vector<int> searchScientistByName(const string name);
    vector<int> searchScientistByGender(const char gender);
    vector<int> searchScientistByBirthYear(const int year);
    vector<int> searchScientistByRange(const int f, const int l);
    vector<int> searchComputerByName(const string name);
    vector <int> searchComputerByYearMade(const int year);
    vector<int> searchComputerByYearRange(const int f, const int l);
    vector<int> searchComputerByType(const string type);
    void deleteScientist(int n);
    void deleteComputer(int n);
    //bool saveToOtherFile(string input);
};

#endif // SERVICELAYER_H
