#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "servicelayer.h"

class ConsoleUI
{
    ServiceLayer serve;
    void clearScreen();
    void listScientistData(); // Lists the Scientists from the Database.
    void listComputerData();
    void addPerson();
    void addComputer();
    void ascOrDesc(int orderBy);
    bool validName(const string& s);
    bool validYear(const string& s, int& year);
    bool genderCheck(char& gender);
    void sortData();
    void addData();
    void addPersonManually();
    //void addPeopleFromFile();
    void searchData();
    void searchScientistByName();
    void searchScientistByGender();
    void searchScientistByBirthYear();
    void searchScientistByYearRange();
    void searchComputer();
    void searchComputerByName();
    void searchComputerByYearMade();
    void searchComputerByType();
    void deleteData();
    void saveToCustomFile();
    void onlyTakeOneInput();
    void printScientistLine();
    void printComputerLine();
public:
    ConsoleUI();
    void run();
};

#endif // CONSOLEUI_H
