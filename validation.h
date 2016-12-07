#ifndef VALIDATION_H
#define VALIDATION_H
#include "servicelayer.h"

#include "consoleui.h"

class validation
{

    ServiceLayer serve;
    ConsoleUI console;
    void ValidateString(string& n);
    bool validNames(const string& s);
    bool birthChecks(int birthYear, int deathYear);
    bool genderCheck(char& gender);
    void errorCheckSaveToFile(bool &fileOpen);
    bool check();
    bool validYear(const string& s, int& year);
    void errorCheckGender(char g);
    void onlyTakeOneInput();
    void yearBornCheck(string year, int bY);
    void deathYearCheck(string year, int dY);
public:
    validation();
};




#endif // VALIDATION_H
