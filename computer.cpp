#include "computer.h"
#include <iomanip>

using namespace std;

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

string Computer::getName() const
{
    return name;
}

int Computer::getBuildYear() const
{
    return buildYear;
}

string Computer::getType() const
{
    return type;
}

bool Computer::getBuilt() const
{
    return built;
}
