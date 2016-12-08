#ifndef VALIDATION_H
#define VALIDATION_H

#include "servicelayer.h"
#include "validation.h"
//#include "consoleui.h"

class validation
{

    //ServiceLayer serve;
    //ConsoleUI console;


public:
    validation();
    void ValidateString(string& n);
    bool validNames(const string& s);
    bool birthChecks(int birthYear, int deathYear);
    bool genderCheck(char& gender);
    void errorCheckSaveToFile(bool &fileOpen);
    bool check();
    bool validYear(const string& s, int& year);
    bool errorCheckGender(char g);
    void onlyTakeOneInput();
};




#endif // VALIDATION_H
