#include "validation.h"
#include "consoleui.h"

#include "consoleui.h"
#include <ctime>
#include "consoleui.h"
#include <cstdlib>

validation::validation()
{

}

void validation::ValidateString(string& n)
{
    while(!validNames(n))
    {
        cout << "Wrong input for name!" << endl;
        cout << "Enter name: ";
        cin  >> ws;
        getline(cin,n);
    }
    if(!isupper(n[0]))                                      //Converts lower case letter to upper case if first is lower case
    {
        n[0] = toupper(n[0]);
    }

}

bool validation::validNames(const string& s)
{
    //Checks if 's' is empty or contains characters other than letters and spaces
    string::const_iterator it = s.begin();
    while (it != s.end() && (isalpha(*it) || *it == ' '))
    {
        it++;
    }

    return !s.empty() && it == s.end();
}


//Errorchecks for whether certain years entered by the user are valid.
//sadly, it can't be a 300 year old dude. No vampires.
bool validation::birthChecks(int birthYear, int deathYear)
{
    time_t t = time(NULL);
    tm* TimePtr = localtime(&t);
    int currentYear = TimePtr->tm_year + 1900;

    if(deathYear < birthYear && deathYear != 0)
    {
        cout << "The scientist cannot die before they are born!" << endl;
        return false;
    }
    if((deathYear - birthYear) > 122)
    {
        cout << "That is too old, the oldest woman was 122 years old!" << endl;
        return false;
    }
    if ((currentYear - birthYear) > 122 && deathYear == 0)
    {
        cout << "That is too old, the oldest woman was 122 years old!" << endl;
        return false;
    }
    return true;
}

bool validation::genderCheck(char& gender)
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

void validation::errorCheckSaveToFile(bool& fileOpen)
{

    cout << "Error! Failed to open file" << endl;
    char continuel;
    bool cont = true;
    while (cont)
    {
        cout << "Do you want to try again? (Y for yes and N for no) " ;
        cin  >> continuel;
        if(continuel == 'Y' && continuel == 'y')
        {
            fileOpen = true;
            cont = false;
        }
        else if (continuel == 'N' && continuel == 'n')
        {
            fileOpen = false;
            cont = false;
        }
        else
        {
            cout << "Error! Invalid input" << endl;
            cont = true;
        }
}
}

bool validation::check()
{
    char continuel;
    cout << "Do you want to try again? (Y for yes and N for no) " ;
    cin  >> continuel;
    if(continuel == 'Y' || continuel == 'y')
    {
        //console.addPerson();
        return true;
    }
    else
    {
       return false;
    }
}

//a function which checks whether a certain entered string is a year.
//And whether it's a valid year (AKA not in the future).
bool validation::validYear(const string& s, int& year)
{
    string::const_iterator it = s.begin();
    //Checks if the string 's' is a number
    while (it != s.end() && isdigit(*it))
    {
        it++;
    }
    if (s.empty() || it != s.end())
    {
        return false;
    }
    //Checks if 'year' is positive and lower than current year
    year = atoi(s.c_str());
    time_t t = time(NULL);
    tm* TimePtr = localtime(&t);
    int currentYear = TimePtr->tm_year + 1900;

    return year >= 0 && year <= currentYear;
}

void validation::errorCheckGender(char g)
{
    while(!genderCheck(g))                                  //Error check for gender
    {
        cout << "Wrong input for gender!" << endl;
        cout << "Enter gender (M/F): ";
        cin  >> g;
        onlyTakeOneInput();
    }
}
//If the user entered too many commands, the rest will just be flushed. Fun stuff.
void validation::onlyTakeOneInput()
{
    cin.clear();
    fflush(stdin);
}

void validation::yearBornCheck(string year, int bY)
{
    while(!validYear(year, bY) || bY == 0)                  //Adds the birth year and error checks
    {
        cout << "Enter birth year: ";
        cin >> year;
        onlyTakeOneInput();
        if (!validYear(year, bY) || bY == 0)
        {
            cout << "Invalid input!\n";
        }
    }
    year = " ";
}
void validation::deathYearCheck(string year, int dY)
{
    while(!validYear(year, dY))                             //Adds the death year and error checks
    {
        cout << "Enter death year (0 for living person): ";
        cin >> year;
        onlyTakeOneInput();
        if(!validYear(year, dY))
        {
            cout << "Invalid input!\n";
        }
    }
}
