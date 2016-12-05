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
    /*bool addFromFile(string input);
    vector<int> searchByName(const string name);
    vector<int> searchByGender(const char gender);
    vector<int> searchByYear(const int year);
    vector<int> searchByRange(const int f, const int l);*/
    void deleteScientist(int n);
    void deleteComputer(int n);
    //bool saveToOtherFile(string input);
};

#endif // SERVICELAYER_H
