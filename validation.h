#ifndef VALIDATION_H
#define VALIDATION_H

#include "servicelayer.h"

class validation
{

    //ServiceLayer serve;
    //ConsoleUI console;


public:
    validation();
    bool validName(const string& s);
    int birthChecks(int birthYear, int deathYear);
    bool genderCheck(char& gender);
    bool errorCheckSaveToFile();
    bool validYear(const string& s, int& year);
};




#endif // VALIDATION_H
