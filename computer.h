#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>

using namespace std;

class Computer
{
    string name;
    int buildYear;
    string type;
    bool built;
public:
    Computer();
    Computer(string n, int bY, string t, bool b);
    string getComputerName() const;
    int getYearMade() const;
    string getType() const;
    bool getBuiltOrNot() const;
};

#endif // COMPUTER_H
