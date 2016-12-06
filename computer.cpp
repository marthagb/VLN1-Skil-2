#include "computer.h"
#include <iomanip>

using namespace std;

Computer::Computer()
{

}

Computer::Computer(string n, int yM, string t, bool b)
{
    computerName = n;
    yearMade = yM;
    type = t;
    builtOrNot = b;
}

string Computer::getComputerName() const
{
    return computerName;
}

int Computer::getYearMade() const
{
    return yearMade;
}

string Computer::getType() const
{
    return type;
}

bool Computer::getBuiltOrNot() const
{
    return builtOrNot;
}

ostream& operator << (ostream& out, const Computer& c)
{
    out.width(26);
    out << left << c.getComputerName() << "\t" << c.getYearMade() << "\t" << c.getType()  << "\t";
    if (!c.getBuiltOrNot())
    {
        out << "Not Built" << endl;
    }
    else
    {
        out << "Built" << endl;
    }
    return out;
}
