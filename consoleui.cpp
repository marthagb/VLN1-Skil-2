#include "consoleui.h"
#include <ctime>
#include "consoleui.h"
#include <cstdlib>

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
    listScientistData();
    //addPerson();

    bool run = true;
    /*if (serve.list().size() == 0)
    {
        cout << "\nCould not load from file or file was empty\n" << endl;
    }*/
    while (run)
    {
       cout << " ================================" << endl;
       cout << " Press 1 to list the scientists"   << endl;
       cout << " Press 2 to sort the scientists"   << endl;
       cout << " Press 3 to list the computers"    << endl;
       cout << " Press 4 to sort the computers"    << endl;
       cout << " Press 5 to add a scientist"       << endl;
       cout << " Press 6 to search the list of scientists"  << endl;
       cout << " Press 7 to search the list of computers" << endl;
       cout << " Press 8 to remove a scientist or computer"    << endl;
       //cout << " Press 9 to save to a custom file" << endl;
       cout << " Press 0 to exit"                  << endl;
       cout << " ================================" << endl;

       char input = '0';
       cin >> input;
        clearScreen();

       onlyTakeOneInput();  // Takes only one letter and flushes the rest.
       int choice = input - '0';

            switch (choice)
            {
            case 1:
            {
                listScientistData();
                break;
            }
            case 2:
            {
                sortData();
                break;
            }
            case 3:
            {
                listComputerData();
                break;
            }
            case 4:
            {

                break;
            }
            case 5:
            {
                addData();
                break;
            }
            case 6:
            {
                searchData();
                break;
            }
            case 7:
            {
                searchComputer();
                break;
            }
            case 8:
            {
                deleteData();
                break;
            }
            /*case 9:
                //saveToCustomFile();
                break;*/
            case 0:
            {
                run = false;
                break;
            }
            default:
            {
                cout << "Error! Invalid input" << endl;
            }
        }
    }
}

void ConsoleUI:: clearScreen()
{
#ifdef __cplusplus__
  #include <cstdlib>
#else
  #include <stdlib.h>
#endif

if (system("CLS")) system("clear");
}

// lists all the data from the vector.
//uses the printLine() function, which gives us a nice header.
void ConsoleUI::listScientistData()
{
    cout << endl;
    printScientistLine();

    for(unsigned int i = 0; i < serve.readScientists(1, 1).size(); i++)
    {
        cout << serve.readScientists(1, 1)[i];
    }
    cout << "_____________________________________________________" << endl;

}

void ConsoleUI::listComputerData()
{
    cout << serve.readComputers(1, 1).size() << endl;
    for(unsigned int i = 0; i < serve.readComputers(1, 1).size(); i++)
    {
        cout << serve.readComputers(1, 1)[i];
    }
    cout << "_____________________________________________________" << endl;
}

//Here we get to pick the parameter by which we want to sort our data.
void ConsoleUI::sortData()
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
                ascOrDesc(choice);
                error = false;
                break;
            }
             case 2:
            {
                ascOrDesc(choice);
                error = false;
                break;
            }
             case 3:
             {
                ascOrDesc(choice);
                error = false;
                break;
            }
             case 4:
            {
                ascOrDesc(choice);
                error = false;
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

}

void ConsoleUI::ascOrDesc(int orderBy)
{
    char input = '0';
    int order = 1;
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

    printScientistLine();

    if (order == 1 || order == 2)
    {

    for(unsigned int i = 0; i < serve.readScientists(orderBy, order).size(); i++)
    {
        cout << serve.readScientists(orderBy, order)[i];
    }
    cout << "_____________________________________________________" << endl;
    }
}

//We add a person through the console.
//If user does not enter a string with names he gets an error message.
//The first letter becomes uppercase.
//there are error checks for birth Year and death Year.
//If no invalid information is entered, the person is added to the file.
void ConsoleUI::addPerson()
{
    string n = " ", year;
    char g = ' ';
    int bY = 0, dY = 0;

    cout << "Enter name: ";                                 //Adds the name of a person
    cin >> ws;
    getline(cin,n);
    while(!validName(n))
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

    cout << "Enter gender: ";                               //Adds the gender of the person
    cin >> g;
    onlyTakeOneInput();
    while(!genderCheck(g))                                  //Error check for gender
    {
        cout << "Wrong input for gender!" << endl;
        cout << "Enter gender (M/F): ";
        cin  >> g;
        onlyTakeOneInput();
    }

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

    if(!birthChecks(bY, dY))
    {
        //check();                                            // Checks if you want to try to input again.
    }
    else
    {
        Persons p(n, g, bY, dY);
        int a = 0;
        for (unsigned int i = 0; i < serve.readScientists(0,1).size(); i++)
        {
            if (p == serve.readScientists(0,1)[i])
            {
                cout << "Scientist already on list!\n";
                a++;
                break;
            }
        }
        if (a == 0)
        {
            serve.addScientist(p);
            cout << "Scientist added\n";
        }
    }
}

void ConsoleUI::addComputer()
{
    string n = " ", t = " ", built = " ";
    int yM = 0;
    bool b;
    cout << "Enter name: ";
    cin >> ws;

    getline(cin, n);
    cout << "Enter build year: ";
    cin >> yM;
    cout << "Enter type: ";
    cin >> t;
    cout << "Enter B if the computer was built and any other character if it wasn't";
    cin >> built;
    if (built == "B" || built == "b") b = true;
    else b = false;
    Computer c(n, yM, t, b);
    serve.addComputer(c);
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
            addPerson();
            error = false;
            break;
        }
        case 2:
        {
            //addPeopleFromFile();
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

/*
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
*/

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
                searchScientistByName();
                error = false;
                break;
            }
            case 2:
            {
                searchScientistByGender();
                error = false;
                break;
            }
            case 3:
            {
                searchScientistByBirthYear();
                break;
            }
            case 4:
            {
                searchScientistByYearRange();
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
void ConsoleUI::searchScientistByName()
{
    string n = " ";
    cout << "Enter name: ";
    cin >> ws;
    getline(cin, n);
    if(!isupper(n[0]))
    {
        n[0] = toupper(n[0]);
    }
    vector<int> vSN = serve.searchScientistByName(n);
    if (vSN.size() == 0)
    {
        cout << "No results found\n";
    }
    else
    {
        printScientistLine();
        for (unsigned int i = 0; i < vSN.size(); i++)
        {
            cout << serve.readScientists(0,1)[vSN[i]];
        }
    }

}

//We can search by gender. Yay.
void ConsoleUI::searchScientistByGender()
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
            searchScientistByGender();
        }
        else
        {
            vector<int> vG = serve.searchScientistByGender(g);
            if (vG.size() == 0)
            {
                cout << "No results found" << endl;
            }
            else
            {
                printScientistLine();
                for (unsigned int i = 0; i < vG.size(); i++)
                {
                    cout << serve.readScientists(0,1)[vG[i]];
                }
            }
        }
    }
    else
    {
        cout << "Invalid input" << endl;
        searchScientistByGender();
    }
}

//We search for people born in a certain year.
void ConsoleUI::searchScientistByBirthYear()
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
    vector<int> vY = serve.searchScientistByBirthYear(y);
    if (vY.size() == 0)
    {
        cout << "No results found\n";
    }
    else
    {
        printScientistLine();
        for (unsigned int i = 0; i < vY.size(); i++)
        {
            cout << serve.readScientists(0,1)[vY[i]];
        }
    }

}

//We get a whole range of years, both included.
//Note that this is only for birthyear.
void ConsoleUI::searchScientistByYearRange()
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
    vector<int> vR = serve.searchScientistByRange(f,l);
    if (vR.size() == 0)
    {
        cout << "No results found" << endl;
    }
    else
    {
        printScientistLine();
        for (unsigned int i = 0; i < vR.size(); i++)
        {
            cout << serve.readScientists(0,1)[vR[i]];
        }
    }

}

void ConsoleUI::searchComputer()
{
    bool error = false;
    do
    {
        cout << "How would you like to search the data?"  << endl;
        cout << " ====================================="  << endl;
        cout << " Press 1 to search by name"              << endl;
        cout << " Press 2 to search by year made"            << endl;
        cout << " Press 3 to search by year range" << endl;
        cout << " Press 4 to search by type"        << endl;
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
                searchComputerByName();
                error = false;
                break;
            }
            case 2:
            {
                searchComputerByYearMade();
                error = false;
                break;
            }
            case 3:
            {
                searchComputerByYearRange();
                error = false;
                break;
            }
            case 4:
            {
                searchComputerByType();
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

void ConsoleUI::searchComputerByName()
{
    string n = " ";
    cout << "Enter name: ";
    cin >> ws;
    getline(cin, n);
    vector<int> vCN = serve.searchComputerByName(n);
    if (vCN.size() == 0)
    {
        cout << "No results found\n";
    }
    else
    {
        printComputerLine();
        for (unsigned int i = 0; i < vCN.size(); i++)
        {
            cout << serve.readComputers(0,1)[vCN[i]];
        }
    }
}

void ConsoleUI::searchComputerByYearMade()
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
    vector<int> vY = serve.searchComputerByYearMade(y);
    if (vY.size() == 0)
    {
        cout << "No results found\n";
    }
    else
    {
        printComputerLine();
        for (unsigned int i = 0; i < vY.size(); i++)
        {
            cout << serve.readComputers(0,1)[vY[i]];
        }
    }
}

void ConsoleUI::searchComputerByYearRange()
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
    vector<int> vR = serve.searchComputerByYearRange(f,l);
    if (vR.size() == 0)
    {
        cout << "No results found" << endl;
    }
    else
    {
        printComputerLine();
        for (unsigned int i = 0; i < vR.size(); i++)
        {
            cout << serve.readComputers(0,1)[vR[i]];
        }
    }
}

void ConsoleUI::searchComputerByType()
{
    string t = " ";
    cout << "Enter type: ";
    cin >> ws;
    getline(cin, t);
    vector<int> vCT = serve.searchComputerByType(t);
    if (vCT.size() == 0)
    {
        cout << "No results found\n";
    }
    else
    {
        printComputerLine();
        for (unsigned int i = 0; i < vCT.size(); i++)
        {
            cout << serve.readComputers(0,1)[vCT[i]];
        }
    }
}

void ConsoleUI::deleteData()
{
    bool error = false;
    do
    {
        cout << " Would you like to delete a scientist or a computer?" << endl;
        cout << " ====================================="  << endl;
        cout << " Press 1 for scientist" << endl;
        cout << " Press 2 for computer" << endl;
        cout << " ====================================="  << endl;
        char input = '0';
        cin >> input;
        onlyTakeOneInput();
        int choice = input - '0';

        switch (choice)
        {
            case 1:
            {
                deleteScientist();
                error = false;
                break;
            }
            case 2:
            {
                deleteComputer();
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

//This deletes a scientist. RIP. He/she probably didn't belong on the list anyway.
void ConsoleUI::deleteScientist()
{
    cout << "Enter name of scientist(s) you would like to delete: ";
    string n = " ";
    cin >> ws;
    getline(cin, n);
    if(!isupper(n[0]))
    {
        n[0] = toupper(n[0]);
    }
    vector<int> v = serve.searchScientistByName(n);
    int s = v.size();
    if (s > 0)
    {
        bool d = false;
        while (!d)
        {
            cout << endl;
            cout << "Are you sure you would like to delete the following scientist(s)? (y/n)\n" << endl;
            printScientistLine();
            for (int i = 0; i < s; i++)
            {

                cout << serve.readScientists(0,1)[v[i]];
            }
            char a = ' ';
            cin >> a;
            if (a == 'y' || a == 'Y')
            {
                for (int i = s-1; i >= 0; i--)
                {
                    serve.deleteScientist(v[i]);
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

void ConsoleUI::deleteComputer()
{
    cout << "Enter name of computer(s) you would like to delete: ";
    string n = " ";
    cin >> ws;
    getline(cin, n);
    vector<int> v = serve.searchComputerByName(n);
    int s = v.size();
    if (s > 0)
    {
        bool d = false;
        while (!d)
        {
            cout << endl;
            cout << "Are you sure you would like to delete the following computer(s)? (y/n)\n" << endl;
            printComputerLine();
            for (int i = 0; i < s; i++)
            {
                cout << serve.readComputers(0,1)[v[i]];
            }
            char a = ' ';
            cin >> a;
            if (a == 'y' || a == 'Y')
            {
                for (int i = s-1; i >= 0; i--)
                {
                    serve.deleteComputer(v[i]);
                }
                cout << "Computer(s) deleted\n";
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
/*void ConsoleUI::saveToCustomFile()
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
}*/

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
/*
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
*/
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
}

//The header used when we list scientists.
void ConsoleUI::printScientistLine()
{
    cout.width(26);
    cout << left << "Name";
    cout <<  "\tGender\tBorn\tDied" << endl;
    cout << "_____________________________________________________" << endl;
}

//The header used when we list computers.
void ConsoleUI::printComputerLine()
{
    cout.width(26);
    cout << left << "Name";
    cout <<  "\tYear Made\tType" << endl;
    cout << "_____________________________________________________" << endl;
}
