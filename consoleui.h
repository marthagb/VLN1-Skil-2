#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "servicelayer.h"

class ConsoleUI
{
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
    void saveScientistsToFile();
    void printScientistLine();

    void computers();
    void listComputerData();
    void ascOrDescComputers(int orderBy);
    void searchComputer();
    void searchComputerByName();
    void searchComputerByYearMade();
    void searchComputerByYearRange();
    void searchComputerByType();
    void addComputer();
    void addComputerManually();
    void addComputersFromFile();
    void deleteComputer();
    void saveComputersToFile();
    void printComputerLine();

    void clearScreen();
    void onlyTakeOneInput();
    bool validName(const string& s);
    bool validYear(const string& s, int& year);
    bool genderCheck(char& gender);
    bool birthChecks(int birthYear, int deathYear);
    bool check();
public:
    ConsoleUI();
    void run();
};

#endif // CONSOLEUI_H
