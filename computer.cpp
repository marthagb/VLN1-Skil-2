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

//makes sure that the given year is a number and not letters
//and that the year is positive and equal to or lower than the current year.
bool Computer::validYear(const string& s, int& year)
{
    string::const_iterator it = s.begin();
    //Checks if the string 's' is a number
    while (it != s.end() && isdigit(*it)) ++it;
    if (s.empty() || it != s.end())
    {
        return false;
    }
    //Checks whether 'year' is positive and lower or equal to the current year
    year = atoi(s.c_str());
    time_t t = time(NULL);
    tm* TimePtr = localtime(&t);
    int currentYear = TimePtr->tm_year + 1900;

    return year >= 0 && year <= currentYear;
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

void Computer::operator = (const Computer& c)
{
    computerName = c.computerName;
    yearMade = c.yearMade;
    type = c.type;
    builtOrNot = c.builtOrNot;
}

bool Computer::operator == (const Computer& c)
{
    return computerName == c.computerName && yearMade == c.yearMade && type == c.type && builtOrNot == c.builtOrNot;
}

bool Computer::operator != (const Computer& c)
{
    return computerName != c.computerName || yearMade != c.yearMade || type != c.type || builtOrNot != c.builtOrNot;
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

istream& operator >> (istream& in, Computer& c)
{
    string n = " ", yM = " ", t = " ", b = " ";
    int year = 0;
    Computer def;
    in >> ws;
    getline(in, n, ';');
    in >> yM >> t >> b;
    if (c.validYear(yM, year))
    {
        if (b == "Built" || b == "built")
        {
            c.computerName = n;
            c.yearMade = year;
            c.type = t;
            c.builtOrNot = true;
        }
        else if (b == "Not built" || b == "not built")
        {
            c.computerName = n;
            c.yearMade = year;
            c.type = t;
            c.builtOrNot = false;
        }
        else c = def;
    }
    else c = def;

    return in;
}
