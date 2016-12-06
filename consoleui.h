#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "servicelayer.h"

class ConsoleUI
{
    ServiceLayer serve;
    void scientists();
    void computers();
    void clearScreen();
    void listScientistData(); // Lists the Scientists from the Database.
    void listComputerData();
    void addPerson();
    void addComputer();
    void ascOrDesc(int orderBy);
    bool validName(const string& s);
    bool validYear(const string& s, int& year);
    bool genderCheck(char& gender);
    bool birthChecks(int birthYear, int deathYear);
    bool check();
    void sortData();
    void addData();
    void addPeopleFromFile();
    void addComputersFromFile();
    void searchData();
    void searchScientistByName();
    void searchScientistByGender();
    void searchScientistByBirthYear();
    void searchScientistByYearRange();
    void searchComputer();
    void searchComputerByName();
    void searchComputerByYearMade();
    void searchComputerByYearRange();
    void searchComputerByType();
    void deleteData();
    void deleteScientist();
    void deleteComputer();
    void saveToCustomFile();
    void onlyTakeOneInput();
    void printScientistLine();
    void printComputerLine();
    void saveToFile();
public:
    ConsoleUI();
    void run();
};

#endif // CONSOLEUI_H
