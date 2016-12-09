#include "association.h"

Association::Association()
{

}

Association::Association(Persons p, Computer c)
{
    scientist = p;
    computer = c;
}

string Association::getScientistName() const
{
    return scientist.getName();
}

string Association::getComputerName() const
{
    return computer.getComputerName();
}

int Association::getYearMade() const
{
    return computer.getYearMade();
}

bool Association::getBuiltOrNot() const
{
    return computer.getBuiltOrNot();
}

string Association::getComputerType() const
{
    return computer.getType();
}

void Association::operator = (const Association a)
{
    scientist = a.scientist;
    computer = a.computer;
}

bool Association::operator == (const Association a)
{
    return scientist == a.scientist && computer == a.computer;
}

bool Association::operator != (const Association a)
{
    return scientist != a.scientist || computer != a.computer;
}

ostream& operator << (ostream& out, const Association& a)
{
    out.width(26);
    out << left << a.getScientistName() << "\t";
    out.width(16);
    out << left << a.getComputerName() << "\t" << a.getYearMade() << "\t";
    out.width(12);

    if (a.getBuiltOrNot())
    {
        out << "Built" << "\t";
    }
    else
    {
        out << "Not Built" << "\t";
    }
    out << a.getComputerType() << endl;

    return out;
}
