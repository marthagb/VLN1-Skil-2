#include "persons.h"
#include <iomanip>
#include <QtSql>


//Default Constructor.
//If a person is ever read in as this, it will be skipped.
//(see readFromFile() and readFromOtherFile(string input) in datalayer.cpp)
Persons::Persons()
{
    name = "John Doe";
    gender = 'M';
    birthYear = 1980;
    deathYear = 0;
    alive = true;
}

//Constructor.
//if deathyear == 0, the person will be alive.
Persons::Persons(int id, string n, char g, int bY, int dY)
{
    ID = id;
    name = n;
    gender = g;
    birthYear = bY;
    deathYear = dY;
    if (dY == 0)
    {
        alive = true;
    }
    else
    {
        alive = false;
    }
}

//Checks for a valid name by whether the string 's' is empty
//or contains characters other than letters and spaces
/*bool Persons::validName(const string& s)
{
    string::const_iterator it = s.begin();
    while (it != s.end() && (isalpha(*it) || *it == ' '))
    {
        ++it;
    }

    return !s.empty() && it == s.end();
}

//Checks whether the gender is valid.
bool Persons::genderCheck(char& gender)
{

    if (gender == 'm' || gender == 'M' || gender == 'f' || gender == 'F')
    {
        if(gender == 'm')
        {
            gender = 'M';
        }
        if(gender == 'f')
        {
            gender = 'F';
        }
        return true;
    }
    else
    {
        return false;
    }
}

//makes sure that the given year is a number and not letters
//and that the year is positive and equal to or lower than the current year.
bool Persons::validYear(const string& s, int& year)
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

//We compare the birth year and death year and make sure that the person is not too old
//as in that he/she died before he/she was born and that the person's death year is not before
//its birth year.
bool Persons::birthChecks(int birthYear, int deathYear)
{
    time_t t = time(NULL);
    tm* TimePtr = localtime(&t);
    int currentYear = TimePtr->tm_year + 1900;
    return ((deathYear - birthYear) >= 0 && (deathYear -birthYear) < 123) ||(deathYear == 0 && (currentYear - birthYear) < 123);
}*/



string Persons::getName() const
{
    return name;
}

int Persons::getBirthYear() const
{
    return birthYear;
}

int Persons::getDeathYear() const
{
    return deathYear;
}

char Persons::getGender() const
{
    return gender;
}

bool Persons::getAlive() const
{
    return alive;
}

//Overloads the = operator. Basic stuff.
void Persons::operator = (const Persons& p)
{
    name = p.name;
    gender = p.gender;
    birthYear = p.birthYear;
    deathYear = p.deathYear;
    alive = p.alive;
}

//Overloads the == and != operators.
//Two persons are equal if and only if each
//parameter is equal.
bool Persons::operator == (const Persons& p)
{
    return name == p.name && gender == p.gender && birthYear == p.birthYear && deathYear == p.deathYear;
}
bool Persons::operator != (const Persons& p)
{
    return name != p.name || gender != p.gender || birthYear != p.birthYear || deathYear != p.deathYear;
}

//Overloads the << (output) operator.
//writes out the name, gender, and birthyear.
//Writes out the deathyear or, if the person is alive
//writes "Alive".
ostream& operator << (ostream& out, const Persons& p)
{
    out.width(26);
    out << left << p.getName() << "\t" << p.getGender() << "\t" << p.getBirthYear()  << "\t";
    if (!p.getAlive())
    {
        out << p.getDeathYear() << endl;
    }
    else
    {
        out << "Alive " << endl;
    }
    return out;
}

//Overloads the >> (input) operator.
//Reads the name which we know ends at a ;
//Then reads the gender and birthyear.
//Reads either "Alive" or the deathyear.
/*istream& operator >> (istream& in, Persons& p)
{
    string n = " ", gdr = " ", b = " ", d = " ";
    char g = ' ';
    int bY = 0, dY =0;
    Persons def;
    in >> ws;
    getline(in, n, ';'); //The Name is read in, and we stop at the ';'.
    in >> gdr >> b >> d; //The Gender, birthYear, and either deathYear or "Alive" is read in.
    if (p.validName(n))
    {
        if (gdr.length() == 1) //checks the length of the gender
        {
            g = gdr.at(0);
            if (p.genderCheck(g)) //Makes sure that the gender is valid.
            {
                if (p.validYear(b, bY)) //checks for a valid birth year.
                {
                    if ((d == "Alive" || d == "alive") && p.birthChecks(bY, dY)) //checks whether the person is alive, and whether his age is consistent with human age.
                    {
                        p.name = n;
                        p.gender = g;
                        p.birthYear = bY;
                        p.alive = true;
                        p.deathYear = 0;
                    }
                    else if(p.validYear(d, dY) && p.birthChecks(bY, dY)) //Checks whether the death year is valid, and whether it's consistent with the birth year.
                    {
                        p.name = n;
                        p.gender = g;
                        p.birthYear = bY;
                        p.deathYear = dY;
                        p.alive = false;
                    }
                    //Each of these, if it fails the validity checks, will make p a person equal to a person with
                    //the default constructor, which, when being loaded, will be skipped.
                    else p = def;
                }
                else p = def;
            }
            else p = def;
        }
        else p = def;
    }
    else p = def;

    return in;
}*/
