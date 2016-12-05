#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "servicelayer.h"

class ConsoleUI
{
    ServiceLayer serve;
    void listData(); // Lists the data from the vector.
    /*void sortData();
    void sortByName(char input, bool &error);
    void sortByGender(char input, bool& error);
    void sortByBirthYear(char input, bool &error);
    void sortByDeathYear(char input, bool& error);
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
    bool validYear(const string& s, int& year);
    bool birthChecks(int birthYear, int deathYear);
    bool validName(const string& s);
    bool check();
    bool genderCheck(char &gender);
    void onlyTakeOneInput();*/
    void printLine();
public:
    ConsoleUI();
    void run();
};

#endif // CONSOLEUI_H
