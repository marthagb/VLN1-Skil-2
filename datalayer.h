#ifndef DATALAYER_H
#define DATALAYER_H

#include <vector>
#include <string>
#include <QtSql>
#include "persons.h"
#include "computer.h"
#include "association.h"

using namespace std;

class DataLayer
{
    QSqlDatabase db;
    vector<Persons> scientists;
    vector<Computer> computers;
    vector<Association> associations;

    vector<int> getScientistIDs();
    vector<int> getComputerIDs();
    vector<int> getAssociationIDs();
public:
   DataLayer();

   void readScientists(int orderBy, int ascOrDesc);
   void readComputers(int orderBy, int ascOrDesc);
   void readAssociations(int orderBy, int ascOrDesc);
   vector<int> searchScientistByName(const string n);
   vector<int> searchScientistByGender(const char g);
   vector<int> searchScientistByBirthYear(const int year);
   vector<int> searchScientistByYearRange(const int f, const int l);
   vector<int> searchComputerByName(const string n);
   vector<int> searchComputerByYearMade(const int year);
   vector<int> searchComputerByYearRange(const int f, const int l);
   vector<int> searchComputerByType(const string type);
   vector<int> searchAssocBySciName(const string sN);
   vector<int> searchAssocByCompName(const string cN);
   vector<int> searchAssocByYear(const int year);
   vector<int> searchAssocByYearRange(const int f, const int l);
   vector<int> searchAssocByCompType(const string type);
   void addScientist(const Persons& p);
   void addComputer(const Computer& c);
   void addAssociation(const Association& a);
   bool addScientistsFromFile(string input);
   bool addComputersFromFile(string input);
   void deleteScientist(string n);
   void deleteComputer(string n);
   void deleteAssociation(string sN, string cN);
   vector<Persons> getScientistVector();
   vector<Computer> getComputerVector();
   vector<Association> getAssociationVector();
};

#endif // DATALAYER_H
