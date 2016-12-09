#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "servicelayer.h"
#include "validation.h"

class ConsoleUI
{
    validation valid;
    ServiceLayer serve;
    void scientists();
    void listScientistData();
    void ascOrDescScientists(int orderBy);
    void searchScientist();
    void searchScientistByName();
    void searchScientistByGender();
    void searchScientistByBirthYear();
    void searchScientistByYearRange();
    void addScientist();
    void addScientistManually();
    void addScientistsFromFile();
    void deleteScientist();
    void updateScientist();
    void saveScientistsToFile();
    void printScientistLine();
    bool quitAddingPerson(string n);

    void computers();
    void listComputerData();
    void ascOrDescComputers(int orderBy);
    void searchComputer();
    void searchComputerByName();
    void searchComputerByYearMade();
    void searchComputerByYearRange();
    void searchComputerByType();
    void addComputers();
    void addComputer();
    void addComputerManually();
    void addComputersFromFile();
    void deleteComputer();
    void updateComputer();
    void saveComputersToFile();
    void printComputerLine();

    void associations();
    void listAssociationData();
    void ascOrDescAssoc(int orderBy);
    void searchAssociation();
    void searchAssocBySciName();
    void searchAssocByCompName();
    void searchAssocByYear();
    void searchAssocByYearRange();
    void searchAssocByCompType();
    void addAssociation();
    void deleteAssociation();
    void saveAssocToFile();
    void printAssocLine();

    void clearScreen();
    void onlyTakeOneInput();
    bool validName(const string& s);
    bool genderCheck(char& gender);
    bool birthChecks(int birthYear, int deathYear);
    bool check();
public:
    ConsoleUI();
    void run();
};

#endif // CONSOLEUI_H
