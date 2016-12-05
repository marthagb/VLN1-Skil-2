#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "servicelayer.h"

class ConsoleUI
{
    ServiceLayer serve;
    void listData(); // Lists the data from the vector.
    void addPerson();
    void addComputer();
    /*void sortData();
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
    void onlyTakeOneInput();*/
    void printLine();
public:
    ConsoleUI();
    void run();
};

#endif // CONSOLEUI_H
