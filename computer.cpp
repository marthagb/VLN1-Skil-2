#include "computer.h"

Computer::Computer()
{

}

Computer::Computer(string n, int bY, string t, bool b)
{
    name = n;
    buildYear = bY;
    type = t;
    built = b;
}

string Computer::getComputerName() const
{
    return name;
}

int Computer::getYearMade() const
{
    return buildYear;
}

string Computer::getType() const
{
    return type;
}

bool Computer::getBuiltOrNot() const
{
    return built;
}
