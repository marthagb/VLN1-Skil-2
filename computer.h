#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>
#include <iostream>

using namespace std;

class Computer
{
    string computerName;
    int yearMade;
    string type;
    bool builtOrNot;
public:
    Computer();
    Computer(string n, int yM, string t, bool b);
    string getComputerName() const;
    int getYearMade() const;
    string getType() const;
    bool getBuiltOrNot() const;
};

#endif // COMPUTER_H
