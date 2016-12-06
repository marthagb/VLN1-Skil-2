#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "servicelayer.h"

class ConsoleUI
{
    ServiceLayer serve;
    void listScientistData(); // Lists the Scientists from the Database.
    void listComputerData();
    void addPerson();
    void addComputer();
    void ascOrDesc(int orderBy);
    bool validName(const string& s);
    bool genderCheck(char& gender);
    void sortData();
    void addData();
    void addPersonManually();
    void addPeopleFromFile();
    void searchData();
    void searchByName();
    void searchByGender();
    void searchByBirthYear();
    void searchByYearRange();
    void deleteData();
    void saveToCustomFile();
    void onlyTakeOneInput();
    void printScientistLine();
public:
    ConsoleUI();
    void run();
};

#endif // CONSOLEUI_H
