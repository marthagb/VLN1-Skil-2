#include "validation.h"
#include "consoleui.h"

#include <ctime>

#include <cstdlib>

validation::validation()
{

}


bool validation::validName(const string& s)                                                     //komið í console
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
int validation::birthChecks(int birthYear, int deathYear)                                       //komið í console
{
    time_t t = time(NULL);
    tm* TimePtr = localtime(&t);
    int currentYear = TimePtr->tm_year + 1900;

    if(deathYear < birthYear && deathYear != 0)
    {
        return 1;
    }
    if((deathYear - birthYear) > 122)
    {
        return 2;
    }
    if ((currentYear - birthYear) > 122 && deathYear == 0)
    {
        return 3;
    }
    return 0;
}

bool validation::genderCheck(char& gender)                                                       //komið í console
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
/*
bool validation::errorCheckSaveToFile()
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
}*/

//a function which checks whether a certain entered string is a year.
//And whether it's a valid year (AKA not in the future).
bool validation::validYear(const string& s, int& year)                                                  //komið í console
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


