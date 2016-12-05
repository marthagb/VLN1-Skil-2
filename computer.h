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
    string getName() const;
    int getBuildYear() const;
    string getType() const;
    bool getBuilt() const;
};

#endif // COMPUTER_H
