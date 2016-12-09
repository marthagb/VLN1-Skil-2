#ifndef SERVICELAYER_H
#define SERVICELAYER_H

#include "datalayer.h"

using namespace std;

class ServiceLayer
{
    DataLayer dl;
public:
    ServiceLayer();
    vector<Persons> listScientists();
    vector<Computer> listComputers();
    vector<Association> listAssociations();

    void sortScientists(int orderBy, int ascOrDesc);
    void sortComputers(int orderBy, int ascOrDesc);
    void sortAssociations(int orderBy, int ascOrDesc);

    vector<int> searchScientistByName(const string name);
    vector<int> searchScientistByGender(const char gender);
    vector<int> searchScientistByBirthYear(const int year);
    vector<int> searchScientistByYearRange(const int f, const int l);
    vector<int> searchComputerByName(const string name);
    vector<int> searchComputerByYearMade(const int year);
    vector<int> searchComputerByYearRange(const int f, const int l);
    vector<int> searchComputerByType(const string type);
    vector<int> searchAssocBySciName(const string sN);
    vector<int> searchAssocByCompName(const string cN);
    vector<int> searchAssocByYear(const int year);
    vector<int> searchAssocByYearRange(const int f, const int l);
    vector<int> searchAssocByCompType(const string type);

    bool addScientist(const Persons& p);
    bool addScientistsFromFile(string input);
    void deleteScientist(string n);

    bool addComputer(const Computer& c);
    bool addComputersFromFile(string input);
    void deleteComputer(string n);

    bool addAssociation(const Association& a);
    void deleteAssociation(string sN, string cN);

    bool saveScientistsToFile(string input);
    bool saveComputersToFile(string input);
    bool saveAssociationsToFile(string input);

    void updateScientist(int variable, string value, string name);
    void updateComputer(int variable, string value, string name);
};

#endif // SERVICELAYER_H
