#include "consoleui.h"
#include <ctime>
#include "consoleui.h"

using namespace std;

//Default Constructor
ConsoleUI::ConsoleUI()
{

}

// The Function used in the main() function.
// Displays the main menu, and takes you to the
// respective function depending on the choice.
void ConsoleUI::run()
{
    listData();

    /*bool run = true;
    if (serve.list().size() == 0)
    {
        cout << "\nCould not load from file or file was empty\n" << endl;
    }
    while (run)
    {
       cout << " ================================" << endl;
       cout << " Press 1 to list the scientists"   << endl;
       cout << " Press 2 to sort the scientists"   << endl;
       cout << " Press 3 to add a scientist"       << endl;
       cout << " Press 4 to search the list"       << endl;
       cout << " Press 5 to remove a scientist"    << endl;
       cout << " Press 6 to save to a custom file" << endl;
       cout << " Press 7 to exit"                  << endl;
       cout << " ================================" << endl;

       char input = '0';
       cin >> input;

       onlyTakeOneInput();  // Takes only one letter and flushes the rest.
       int choice = input - '0';

            switch (choice)
            {
            case 1:
            {
                listData();
                break;
            }
            case 2:
            {
                sortData();
                break;
            }
            case 3:
            {
                addData();
                break;
            }
            case 4:
            {
                searchData();
                break;
            }
            case 5:
            {
                deleteData();
                break;
            }
            case 6:
                saveToCustomFile();
                break;
            case 7:
            {
                run = false;
                break;
            }
            default:
            {
                cout << "Error! Invalid input" << endl;
            }
        }
    }*/
}

// lists all the data from the vector.
//uses the printLine() function, which gives us a nice header.
void ConsoleUI::listData()
{
    cout << endl;
    printLine();

    for(unsigned int i = 0; i < serve.list().size(); i++)
    {
        cout << serve.list()[i];
    }
    cout << "_____________________________________________________" << endl;

}

//Here we get to pick the parameter by which we want to sort our data.
/*void ConsoleUI::sortData()
{
    char input = '0';
    int choice = 0;
    bool error = false;

    do
    {
        cout << "How would you like to sort the list?" << endl;
        cout << " ================================"    << endl;
        cout << " Press 1 to sort by name"             << endl;
        cout << " Press 2 to sort by gender"           << endl;
        cout << " Press 3 to sort by birth year "      << endl;
        cout << " Press 4 to sort by death year"       << endl;
        cout << " Press 5 to Cancel"                   << endl;
        cout << " ================================"    << endl;

        cin >> input;
        onlyTakeOneInput();
        choice = input - '0';
        input = '1';

            switch (choice)
            {
            case 1:
            {
                sortByName(input, error);
                break;
            }
             case 2:
            {
                sortByGender(input, error);
                break;
            }
             case 3:
             {
                sortByBirthYear(input, error);
                break;
            }
             case 4:
            {
                sortByDeathYear(input, error);
                break;
            }
             case 5:
            {
                error = false;
                break;
            }
             default:
            {
                 cout << "Error! Invalid input!" << endl;
                 error = true;
            }
        }
    }
    while (error);

    if (choice != 5) //if you press cancel, you don't want to see the list, do you?
    {
        listData();
    }
}

//We sort by name, and want to know whether you want to sort reversed or not.
void ConsoleUI::sortByName(char input, bool& error)
{
    int order = 0;
    do
    {
        cout << "Regular or Reversed sorting?"      << endl;
        cout << " ================================" << endl;
        cout << "Press 1 for regular sorting"       << endl;
        cout << "Press 2 for reversed sorting"      << endl;
        cout << "Press 3 to cancel"                 << endl;
        cout << " ================================" << endl;

        cin >> input;
        onlyTakeOneInput();
        if (input != '1' && input != '2' && input != '3')
        {
            cout << "Error! Invalid input" << endl;
        }
    }
    while (input != '1' && input != '2' && input != '3');
    order = input - '0';

    if (order == 1 || order == 2)
    {
        serve.sortByName(order);
        error = false;
    }
    else
    {
        error = true;
    }
}

//Do you want to see all the ladies first? Or maybe the men?
//Then this function is for you!!
void ConsoleUI::sortByGender(char input, bool& error)
{
    int order = 0;
    do
    {
        cout << "Sort by Males or Females?"         << endl;
        cout << " ================================" << endl;
        cout << "Press 1 to sort by females first"  << endl;
        cout << "Press 2 to sort by males first"    << endl;
        cout << "Press 3 to cancel"                 << endl;
        cout << " ================================" << endl;

        cin >> input;
        onlyTakeOneInput();
        if (input != '1' && input != '2' && input != '3')
        {
            cout << "Error! Invalid input" << endl;
        }
    }
    while (input != '1' && input != '2' && input != '3');
    order = input - '0';

    if (order == 1 || order == 2)
    {
        serve.sortByGender(order);
        error = false;
    }
    else
    {
        error = true;
    }
}

//We sort by birthyear, and want to know whether we want to sort reversed or not.
void ConsoleUI::sortByBirthYear(char input, bool& error)
{
    int order = 0;
    do
    {
        if (input != '1' && input != '2' && input != '3')
        {
            cout << "Error! Invalid input" << endl;
        }
        cout << "Ascending or Descending sorting?"    << endl;
        cout << " ================================"   << endl;
        cout << "Press 1 to sort by ascending order"  << endl;
        cout << "Press 2 to sort by descending order" << endl;
        cout << "Press 3 to cancel"                   << endl;
        cout << " ================================"   << endl;
        cin >> input;
        onlyTakeOneInput();
    }
    while (input != '1' && input != '2' && input != '3');
    order = input - '0';

    if (order == 1 || order == 2)
    {
        serve.sortByBirthYear(order);
        error = false;
    }
    else
    {
        error = true;
    }
}

//We sort by death year, and want to know whether we want to sort reversed or not.
//Alive people will be listed last (or first for reversed).
void ConsoleUI::sortByDeathYear(char input, bool& error)
{
    int order = 0;
    do
    {
        if (input != '1' && input != '2' && input != '3')
        {
            cout << "Error! Invalid input" << endl;
        }
        cout << "Ascending or Descending sorting?"    << endl;
        cout << " ================================"   << endl;
        cout << "Press 1 to sort by ascending order"  << endl;
        cout << "Press 2 to sort by descending order" << endl;
        cout << "Press 3 to cancel"                   << endl;
        cout << " ================================"   << endl;

        cin >> input;
        onlyTakeOneInput();
    }
    while (input != '1' && input != '2' && input != '3');
    order = input - '0';

    if (order == 1 || order == 2)
    {
        serve.sortByDeathYear(order);
        error = false;
    }
    else
    {
        error = true;
    }
}

// Asks you to enter whether you want to add data manually or from a file.
void ConsoleUI::addData()
{
    bool error = false;
    do
    {
        cout << " ================================" << endl;
        cout << " Press 1 to add manually"          << endl;
        cout << " Press 2 to add from file"         << endl;
        cout << " Press 3 to cancel"                << endl;
        cout << " ================================" << endl;

        char input = '0';
        cin >> input;
        onlyTakeOneInput();
        int choice = input - '0';

        switch (choice)
        {
        case 1:
        {
            addPersonManually();
            error = false;
            break;
        }
        case 2:
        {
            addPeopleFromFile();
            error = false;
            break;
        }
        case 3:
        {
            error = false;
            break;
        }
        default:
        {
            cout << "Error! Invalid input" << endl;
            error = true;
            break;
        }
        }
    }
    while (error);
}

//We add a person through the console.
//If user does not enter a string with names he gets an error message.
//The first letter becomes uppercase.
//there are error checks for birth Year and death Year.
//If no invalid information is entered, the person is added to the file.
void ConsoleUI::addPersonManually()
{
    string name, year;
    char gender;
    int birthYear;
    int deathYear;

    cout << "Enter name: ";
    cin >> ws;
    getline(cin,name);
    while(!validName(name))
    {
        cout << "Wrong input for name!" << endl;
        cout << "Enter name: ";
        cin  >> ws;
        getline(cin,name);
    }
    if(!isupper(name[0]))
    {
        name[0] = toupper(name[0]);
    }
    cout << "Enter gender (M/F): ";
    cin >> gender;
    onlyTakeOneInput();
    while(!genderCheck(gender))
    {
        cout << "Wrong input for gender!" << endl;
        cout << "Enter gender (M/F): ";
        cin  >> gender;
        onlyTakeOneInput();
    }
    while(!validYear(year, birthYear) || birthYear == 0)
    {
        cout << "Enter birth year: ";
        cin >> year;
        onlyTakeOneInput();
        if (!validYear(year, birthYear) || birthYear == 0)
        {
            cout << "Invalid input!\n";
        }
    }
    year = " ";
    while(!validYear(year, deathYear))
    {
        cout << "Enter death year (0 for living person): ";
        cin >> year;
        onlyTakeOneInput();
        if(!validYear(year, deathYear))
        {
            cout << "Invalid input!\n";
        }
    }
    if(!birthChecks(birthYear, deathYear))
    {
        check();    // Checks if you want to try to input again.
    }
    else
    {
        Persons newPerson(name, gender, birthYear, deathYear);
        int a = 0;
        for (unsigned int i = 0; i < serve.list().size(); i++)
        {
            if (newPerson == serve.list()[i])
            {
                cout << "Scientist already on list!\n";
                a++;
                break;
            }
        }
        if (a == 0)
        {
            serve.add(newPerson);
            cout << "Scientist added\n";
        }
    }

}

// Asks user to enter path to file. This WILL overwrite the default file.
void ConsoleUI::addPeopleFromFile()
{
    string fileName = "";
    bool fileOpen = false;

    do
    {
        cout << "Enter the full path of the file, or the name of the file, if the file is in the same directory: " << endl;
        cin >> fileName;
        if(serve.addFromFile(fileName))
        {
            cout << "Success!" << endl;
            fileOpen = false;
        }
        else
        {
            cout << "Error! Failed to open file" << endl;
            char continuel;
            bool cont = true;
            while (cont)
            {
                cout << "Do you want to try again? (Y for yes and N for no) " ;
                cin  >> continuel;
                if(continuel == 'Y' || continuel == 'y')
                {
                    fileOpen = true;
                    cont = false;
                }
                else if (continuel == 'N' || continuel == 'n')
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
    }
    while (fileOpen);
}

// Shows the table for search options.
void ConsoleUI::searchData()
{
    bool error = false;
    do
    {
        cout << "How would you like to search the data?"  << endl;
        cout << " ====================================="  << endl;
        cout << " Press 1 to search by name"              << endl;
        cout << " Press 2 to search by gender"            << endl;
        cout << " Press 3 to search by birth year"        << endl;
        cout << " Press 4 to search by birth year range"  << endl;
        cout << " Press 5 to cancel"                      << endl;
        cout << " ======================================" << endl;

        char input = '0';
        cin >> input;
        onlyTakeOneInput();
        int choice = input - '0';

        switch(choice)
        {
            case 1:
            {
                searchByName();
                error = false;
                break;
            }
            case 2:
            {
                searchByGender();
                error = false;
                break;
            }
            case 3:
            {
                searchByBirthYear();
                break;
            }
            case 4:
            {
                searchByYearRange();
                break;
            }

            case 5:
            {
                error = false;
                break;
            }
            default:
            {
                cout << "Error! Invalid input" << endl;
                error = true;
            }
        }
    }
    while (error);
}

//searches the vector for the string which the user enters
//and displays every result.
void ConsoleUI::searchByName()
{
    string n = " ";
    cout << "Enter name: ";
    cin >> ws;
    getline(cin, n);
    if(!isupper(n[0]))
    {
        n[0] = toupper(n[0]);
    }
    vector<int> vN = serve.searchByName(n);
    if (vN.size() == 0)
    {
        cout << "No results found\n";
    }
    else
    {
        printLine();
        for (unsigned int i = 0; i < vN.size(); i++)
        {
            cout << serve.list()[vN[i]];
        }
    }

}

//We can search by gender. Yay.
void ConsoleUI::searchByGender()
{
    string gender = " ";
    cout << "Enter gender (M/F): ";
    cin >> gender;

    if (gender.length() == 1)
    {
        char g = gender.at(0);
        if (!genderCheck(g))
        {
            cout << "Invalid gender input!" << endl;
            searchByGender();
        }
        else
        {
            vector<int> vG = serve.searchByGender(g);
            if (vG.size() == 0)
            {
                cout << "No results found" << endl;
            }
            else
            {
                printLine();
                for (unsigned int i = 0; i < vG.size(); i++)
                {
                    cout << serve.list()[vG[i]];
                }
            }
        }
    }
    else
    {
        cout << "Invalid input" << endl;
        searchByGender();
    }
}

//We search for people born in a certain year.
void ConsoleUI::searchByBirthYear()
{
    int y = 0;
    string s = " ";
    while (!validYear(s, y) || y == 0)
    {
        cout << "Enter year: ";
        cin >> s;
        if(!validYear(s, y) || y == 0) {
            cout << "Invalid input!\n";
        }
    }
    vector<int> vY = serve.searchByYear(y);
    if (vY.size() == 0)
    {
        cout << "No results found\n";
    }
    else
    {
        printLine();
        for (unsigned int i = 0; i < vY.size(); i++)
        {
            cout << serve.list()[vY[i]];
        }
    }

}

//We get a whole range of years, both included.
//Note that this is only for birthyear.
void ConsoleUI::searchByYearRange()
{
    int f = 0, l = 0;
    string s = " ";
    while(!validYear(s, f))
    {
        cout << "Enter first year in range: ";
        cin >> s;
        if (!validYear(s, f)) {
            cout << "Invalid input!\n";
        }
    }
    s = " ";
    while(!validYear(s, l) || l < f)
    {
        cout << "Enter last year in range: ";
        cin >> s;
        if(!validYear(s, l) || l < f)
        {
            cout << "Invalid input!\n";
        }
    }
    vector<int> vR = serve.searchByRange(f,l);
    if (vR.size() == 0)
    {
        cout << "No results found" << endl;
    }
    else
    {
        printLine();
        for (unsigned int i = 0; i < vR.size(); i++)
        {
            cout << serve.list()[vR[i]];
        }
    }

}

//This deletes a scientist. RIP. He/she probably didn't belong on the list anyway.
void ConsoleUI::deleteData()
{
    cout << "Enter name of scientist(s) you would like to delete: ";
    string n = " ";
    cin >> ws;
    getline(cin, n);
    if(!isupper(n[0]))
    {
        n[0] = toupper(n[0]);
    }
    vector<int> v = serve.searchByName(n);
    int s = v.size();
    if (s > 0)
    {
        bool d = false;
        while (!d)
        {
            cout << endl;
            cout << "Are you sure you would like to delete the following scientist(s)? (y/n)\n" << endl;
            printLine();
            for (int i = 0; i < s; i++)
            {

                cout << serve.list()[v[i]];
            }
            char a = ' ';
            cin >> a;
            if (a == 'y' || a == 'Y')
            {
                for (int i = s-1; i >= 0; i--)
                {
                    serve.deletePerson(v[i]);
                }
                cout << "Scientist(s) deleted\n";
                d = true;
            }
            else if (a == 'n' || a == 'N')
            {
                cout << "Delete cancelled\n";
                d = true;
            }
            else
            {
                cout << "Invalid input!\n";
            }
        }
    }
    else
    {
        cout << "No match for " << n << endl;
    }
}

//Here, the user puts in a string, where it will be attempted to save the list to.
void ConsoleUI::saveToCustomFile()
{
    bool fileOpen = false;
    string fileName;
    do
    {
        cout << "WARNING: This will overwrite everything in the file selected!" << endl;
        cout << "If the File Doesn't exist, it will create a new file." << endl << endl;
        cout << "Enter the full path of the file, or the name of the file, if the file is in the same directory: " << endl;
        cin >> fileName;
        if(serve.saveToOtherFile(fileName))
        {
            cout << "Success!" << endl;
            fileOpen = false;
        }
        else
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
    }
    while (fileOpen);
}

//a function which checks whether a certain entered string is a year.
//And whether it's a valid year (AKA not in the future).
bool ConsoleUI::validYear(const string& s, int& year)
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

//we check whether a name entered by the user is valid
// i.e. that it's not empty, no numbers.
bool ConsoleUI::validName(const string& s)
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
bool ConsoleUI::birthChecks(int birthYear, int deathYear)
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

//in the addData() function, errors will call upon this function.
//it then loops back into said function if you want.
bool ConsoleUI::check()
{
    char continuel;
    cout << "Do you want to try again? (Y for yes and N for no) " ;
    cin  >> continuel;
    if(continuel == 'Y' || continuel == 'y')
    {
        addData();
        return true;
    }
    else
    {
       return false;
    }
}

//Errorcheck for whether the entered char is a recognised gender.
bool ConsoleUI::genderCheck(char& gender)
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

//If the user entered too many commands, the rest will just be flushed. Fun stuff.
void ConsoleUI::onlyTakeOneInput()
{
    cin.clear();
    fflush(stdin);
}*/

//The header used when we list scientists.
void ConsoleUI::printLine()
{
    cout.width(26);
    cout << left << "Name";
    cout <<  "\tGender\tBorn\tDied" << endl;
    cout << "_____________________________________________________" << endl;
}
