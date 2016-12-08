#include "consoleui.h"
#include <ctime>
#include "consoleui.h"
#include <cstdlib>

#include "servicelayer.h"
#include "validation.h"

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
    bool run = true;

    while (run)
    {
        cout << " ================================" << endl;
        cout << " Press 1 for scientists"           << endl;
        cout << " Press 2 for computers"            << endl;
        cout << " Press 3 for both"                 << endl;
        cout << " Press 4 for exit"                 << endl;
        cout << " ================================" << endl;

        char input = '0';
        cin >> input;
        onlyTakeOneInput();
        int choice = input - '0';

            switch (choice)
            {
                case 1:
                {
                    scientists();
                    break;
                }
                case 2:
                {
                    computers();
                    break;
                }
                case 3:
                {
                    associations();
                    break;
                }
                case 4:
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


void ConsoleUI::scientists()
{
    bool run = true;

    while (run)
    {
       cout << " ================================" << endl;
       cout << " Press 1 to list the scientists"   << endl;
       cout << " Press 2 to search scientists"       << endl;
       cout << " Press 3 to add a scientist"     << endl;
       cout << " Press 4 to remove a scientist"    << endl;
       cout << " Press 5 to save to a custom file" << endl;
       cout << " Press 6 to go back to main menu"  << endl;
       cout << " Press 7 to quit"                  << endl;
       cout << " ================================" << endl;

       char input = '0';
       cin >> input;
       clearScreen();

       onlyTakeOneInput();                                                  // Takes only one letter and flushes the rest.
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
                searchScientist();
                break;
            }
            case 3:
            {
                addScientist();
                break;
            }
            case 4:
            {
                deleteScientist();
                break;
            }
            case 5:
            {
                saveScientistsToFile();
                break;
            }
            case 6:
            {
                run = false;
                break;
            }
            case 7:
            {
                exit(0);
                break;
            }

            default:
            {
                cout << "Error! Invalid input" << endl;
            }
            }
    }
}

// lists all the data from the vector.
//uses the printLine() function, which gives us a nice header.
void ConsoleUI::listScientistData()
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
        clearScreen();
        choice = input - '0';
        input = '1';



        if (choice >= 1 && choice <= 4)
        {
            ascOrDescScientists(choice);
            error = false;
        }
        else if (choice == 5)
        {
            error = false;
        }
        else
        {
            cout << "Error! Invalid input!" << endl;
            error = true;
        }
    }
    while (error);
}

void ConsoleUI::ascOrDescScientists(int orderBy)
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


    if (order == 1 || order == 2)
    {
        printScientistLine();

        serve.sortScientists(orderBy, order);
        for(unsigned int i = 0; i < serve.listScientists().size(); i++)
        {
            cout << serve.listScientists()[i];
        }
        cout << "_____________________________________________________" << endl;
    }
}

// Shows the table for search options.
void ConsoleUI::searchScientist()
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
                error = false;
                break;
            }
            case 4:
            {
                searchScientistByYearRange();
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
    cout << "Enter scientist name: ";
    cin >> ws;
    getline(cin, n);
    serve.sortScientists(1, 1);
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
            cout << serve.listScientists()[vSN[i]];
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
        if (!valid.genderCheck(g))
        {
            cout << "Invalid gender input!" << endl;
            searchScientistByGender();
        }
        else
        {
            serve.sortScientists(1,1);
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
                    cout << serve.listScientists()[vG[i]];
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
    while (!valid.validYear(s, y) || y == 0)
    {
        cout << "Enter year: ";
        cin >> s;
        if(!valid.validYear(s, y) || y == 0) {
            cout << "Invalid input!\n";
        }
    }
    serve.sortScientists(1,1);
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
            cout << serve.listScientists()[vY[i]];
        }
        cout << "________________________________________________________________________" << endl;
    }

}

//We get a whole range of years, both included.
//Note that this is only for birthyear.
void ConsoleUI::searchScientistByYearRange()
{
    int f = 0, l = 0;
    string s = " ";
    while(!valid.validYear(s, f))
    {
        cout << "Enter first year in range: ";
        cin >> s;
        if (!valid.validYear(s, f)) {
            cout << "Invalid input!\n";
        }
    }
    s = " ";
    while(!valid.validYear(s, l) || l < f)
    {
        cout << "Enter last year in range: ";
        cin >> s;
        if(!valid.validYear(s, l) || l < f)
        {
            cout << "Invalid input!\n";
        }
    }
    serve.sortScientists(1,1);
    vector<int> vR = serve.searchScientistByYearRange(f,l);
    if (vR.size() == 0)
    {
        cout << "No results found" << endl;
    }
    else
    {
        printScientistLine();
        for (unsigned int i = 0; i < vR.size(); i++)
        {
            cout << serve.listScientists()[vR[i]];
        }
    }

}

// Asks you to enter whether you want to add data manually or from a file.
void ConsoleUI::addScientist()
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
            addScientistManually();
            error = false;
            break;
        }
        case 2:
        {
            addScientistsFromFile();
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
void ConsoleUI::addScientistManually()
{
    string n = " ", year = " ";
    char g = ' ';
    int bY = 0, dY = 0;
    cout << "Type q and enter to cancel at anytime\n" << endl;
    cout << "Enter name: ";                                     //Adds the name of a person
    cin >> ws;    

    getline(cin,n);

    if(n == "q" || n == "Q")
    {
        cout << "Adding new scientist cancelled" << endl;
    }
    else
    {
        while(!valid.validName(n))                                  //error checks name through validation layer
        {
            cout << "Wrong input for name!" << endl;
            cout << "Enter name: ";
            cin  >> ws;
            getline(cin,n);
            if(n == "q" || n == "Q")
            {
                cout << "Adding new scientist cancelled" << endl;
                break;
            }
        }
        if(!isupper(n[0]))                                          //Converts lower case letter to upper case if first is lower case
        {
            n[0] = toupper(n[0]);
        }

        cout << "Enter gender: ";                                   //Adds the gender of the person through validation layer
        cin >> g;
        onlyTakeOneInput();

        if(g == 'q' || g == 'Q')
        {
                cout << "Adding new scientist cancelled" << endl;
        }
        else
        {
            while(!valid.genderCheck(g))                                //Error check for gender through validation layer
            {
                cout << "Wrong input for gender!" << endl;
                cout << "Enter gender (M/F): ";
                cin  >> g;
                onlyTakeOneInput();
                if(g == 'q' || g == 'Q')
                {
                        cout << "Adding new scientist cancelled" << endl;
                        break;
                }
            }
            if (valid.genderCheck(g))
            {
                while(!valid.validYear(year, bY) || bY == 0)                //Adds the birth year and error checks through validation layer
                {
                    cout << "Enter birth year: ";
                    cin >> year;
                    onlyTakeOneInput();
                    if(year == "q" || year == "Q")
                    {
                        cout << "Adding new scientist cancelled" << endl;
                        break;
                    }
                    if (!valid.validYear(year, bY) || bY == 0)
                    {
                        cout << "Invalid input!\n";
                    }
                }
                if (valid.validYear(year, bY))
                {
                    year = " ";
                    while(!valid.validYear(year, dY))                             //Adds the death year and error checks through validation layer
                    {
                        cout << "Enter death year (0 for living person): ";
                        cin >> year;
                        if(year == "q" || year == "Q")
                        {
                            cout << "Adding new scientist cancelled" << endl;
                            break;
                        }
                        onlyTakeOneInput();
                        if(!valid.validYear(year, dY))
                        {
                            cout << "Invalid input!\n";
                        }
                    }
                    if (valid.validYear(year, dY))
                    {
                        if(valid.birthChecks(bY, dY) == 1)                                          //error checks in validatioin for correct year input
                        {

                            cout << "The scientist cannot die before they are born!" << endl;
                            check();                                                                // Checks if you want to try to input again.
                        }
                        else if(valid.birthChecks(bY, dY) == 2)
                        {
                            cout << "That is too old, the oldest woman was 122 years old!" << endl;
                            check();
                        }
                        else if (valid.birthChecks(bY,dY) == 3)
                        {
                            cout << "That is too old, the oldest woman was 122 years old!" << endl;
                            check();
                        }
                        else
                        {
                            Persons p(n, g, bY, dY);                                                //adds new scientist to datab
                            int a = 0;
                            for (unsigned int i = 0; i < serve.listScientists().size(); i++)
                            {
                                if (p == serve.listScientists()[i])
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
                }
            }
        }
    }
}



// Asks user to enter path to file. This WILL overwrite the default file.
void ConsoleUI::addScientistsFromFile()
{
    string fileName = "";
    bool fileOpen = false;

    do
    {

        cout << "Enter the full path of the file, or the name of the file, if the file is in the same directory: " << endl;
        cout << "Type q and enter to cancel adding scientists from file \n" ;
        cin >> fileName;
        if(fileName == "q" || fileName == "Q")
        {
            cout << "Adding scientists from file canceled " << endl;
            scientists();
        }
        if(serve.addScientistsFromFile(fileName))
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

//This deletes a scientist. RIP. He/she probably didn't belong on the list anyway.
void ConsoleUI::deleteScientist()
{
    cout << "Enter name of scientist(s) you would like to delete: ";
    string n = " ";
    cin >> ws;
    getline(cin, n);
    serve.sortScientists(1,1);
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
                cout << serve.listScientists()[v[i]];
            }
            char a = ' ';
            cin >> a;
            if (a == 'y' || a == 'Y')
            {
                for (int i = s-1; i >= 0; i--)
                {
                    serve.deleteScientist(n);
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

void ConsoleUI::saveScientistsToFile()
{
    bool fileOpen = false;
    string fileName;
    do
    {
        cout << "WARNING: This will overwrite everything in the file selected!" << endl;
        cout << "If the File Doesn't exist, it will create a new file." << endl << endl;
        cout << "Enter the full path of the file, or the name of the file, if the file is in the same directory: " << endl;
        cin >> fileName;
        if(serve.saveScientistsToFile(fileName))
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

//The header used when we list scientists.
void ConsoleUI::printScientistLine()
{
    cout.width(26);
    cout << left << "Name";
    cout <<  "\tGender\tBorn\tDied" << endl;
    cout << "_____________________________________________________" << endl;
}




void ConsoleUI::computers()
{
    bool run = true;

    while (run)
    {
        cout << " ================================" << endl;
        cout << " Press 1 to list the computers"    << endl;
        cout << " Press 2 to search computers"        << endl;
        cout << " Press 3 to add a computer"       << endl;
        cout << " Press 4 to remove a computer"    << endl;
        cout << " Press 5 to save to a custom file" << endl;
        cout << " Press 6 to go back to main menu"  << endl;
        cout << " Press 7 to quit"                  << endl;
        cout << " ================================" << endl;

        char input = '0';
        cin >> input;
        clearScreen();

        onlyTakeOneInput();                                                  // Takes only one letter and flushes the rest.
        int choice = input - '0';

        switch (choice)
           {
           case 1:
           {
               listComputerData();
               break;
           }
           case 2:
           {
               searchComputer();
               break;
           }
           case 3:
           {
               addComputers();
               break;
           }
           case 4:
           {
               deleteComputer();
               break;
           }
           case 5:
           {
               saveComputersToFile();
               break;
           }
           case 6:
           {
                run = false;
                break;
           }
           case 7:
           {
                exit (0);
                break;
           }

           default:
           {
               cout << "Error! Invalid input" << endl;
           }
           }
    }
}

void ConsoleUI::listComputerData()
{
    char input = '0';
    int choice = 0;
    bool error = false;

    do
    {
        cout << "How would you like to sort the list?"   << endl;
        cout << " =================================="    << endl;
        cout << " Press 1 to sort by name"               << endl;
        cout << " Press 2 to sort by year made"         << endl;
        cout << " Press 3 to sort by type"               << endl;
        cout << " Press 4 to sort by whether it was built" << endl;
        cout << " Press 5 to Cancel"                     << endl;
        cout << " =================================="    << endl;

        cin >> input;
        onlyTakeOneInput();
        clearScreen();
        choice = input - '0';
        input = '1';



        if (choice >= 1 && choice <= 4)
        {
            ascOrDescComputers(choice);
            error = false;
        }
        else if (choice == 5)
        {
            error = false;
        }
        else
        {
            cout << "Error! Invalid input!" << endl;
            error = true;
        }
    }
    while (error);
}

void ConsoleUI::ascOrDescComputers(int orderBy)
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

    if (order == 1 || order == 2)
    {
        printComputerLine();

        serve.sortComputers(orderBy, order);
        for(unsigned int i = 0; i < serve.listComputers().size(); i++)
        {
            cout << serve.listComputers()[i];
        }
        cout << "_____________________________________________________" << endl;
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
    cout << "Enter computer name: ";
    cin >> ws;
    getline(cin, n);
    serve.sortComputers(1,1);
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
            cout << serve.listComputers()[vCN[i]];
        }
    }
}

void ConsoleUI::searchComputerByYearMade()
{
    int y = 0;
    string s = " ";
    while (!valid.validYear(s, y) || y == 0)
    {
        cout << "Enter year: ";
        cin >> s;
        if(!valid.validYear(s, y) || y == 0) {
            cout << "Invalid input!\n";
        }
    }
    serve.sortComputers(1,1);
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
            cout << serve.listComputers()[vY[i]];
        }
    }
}

void ConsoleUI::searchComputerByYearRange()
{
    int f = 0, l = 0;
    string s = " ";
    while(!valid.validYear(s, f))
    {
        cout << "Enter first year in range: ";
        cin >> s;
        if (!valid.validYear(s, f)) {
            cout << "Invalid input!\n";
        }
    }
    s = " ";
    while(!valid.validYear(s, l) || l < f)
    {
        cout << "Enter last year in range: ";
        cin >> s;
        if(!valid.validYear(s, l) || l < f)
        {
            cout << "Invalid input!\n";
        }
    }
    serve.sortComputers(1,1);
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
            cout << serve.listComputers()[vR[i]];
        }
    }
}

void ConsoleUI::searchComputerByType()
{
    string t = " ";
    cout << "Enter type: ";
    cin >> ws;
    getline(cin, t);
    serve.sortComputers(1,1);
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
            cout << serve.listComputers()[vCT[i]];
        }
    }
}
// Asks you to enter whether you want to add data manually or from a file.
void ConsoleUI::addComputers()
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
            addComputerManually();
            error = false;
            break;
        }
        case 2:
        {
            addComputersFromFile();
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

void ConsoleUI::addComputerManually()
{
    string n = " ",y = " ", t = " ", built = " ";
    int yM = 0;
    bool b;
    cout << "Type Q and enter to cancel at anytime\n" << endl;
    cout << "Enter name: ";
    cin >> ws;
    getline(cin, n);
    if(n == "q" || n == "Q")
    {
        cout << "Adding new computer cancelled" << endl;
    }
    else
    {
        while(!valid.validName(n))                           //error checks name through validation layer
        {
            cout << "Wrong input for name!" << endl;
            cout << "Enter name: ";
            cin  >> ws;
            getline(cin,n);
            if (n == "q" || n == "Q")
            {
                cout << "Adding new computer cancelled" << endl;
                break;
            }
        }
        if (valid.validName(n))
        {
            cout << "Enter build year: ";
            cin >> y;
            onlyTakeOneInput();
            if (y == "q" || y == "Q")
            {
                cout << "Adding new computer cancelled" << endl;
            }
            else
            {
                while (!valid.validYear(y, yM))
                {
                    cout << "Invalid input!" << endl;
                    cout << "Enter build year: ";
                    cin >> y;
                    onlyTakeOneInput();
                    if (y == "q" || y == "Q")
                    {
                        cout << "Adding new computer cancelled" << endl;
                        break;
                    }
                }
                if (valid.validYear(y, yM))
                {
                    cout << "Enter type: ";
                    cin >> ws;
                    getline(cin, t);
                    if(t == "q" || t == "Q")
                    {
                        cout << "Adding new computer cancelled" << endl;
                    }
                    else
                    {
                        cout << "Enter B if the computer was built and any other character (except for Q) if it wasn't: ";
                        cin >> built;
                        if(built == "q" || built == "Q")
                        {
                            cout << "Adding new computer cancelled" << endl;
                        }
                        else
                        {
                            if (built == "B" || built == "b")
                            {
                                b = true;
                            }
                            else
                            {
                                b = false;
                            }
                            Computer c(n, yM, t, b);
                            int a = 0;
                            for (unsigned int i = 0; i < serve.listComputers().size(); i++)
                            {
                                if (c == serve.listComputers()[i])
                                {
                                    a++;
                                    cout << "Computer already on list!\n";
                                    break;
                                }
                            }
                            if (a==0)
                            {
                                serve.addComputer(c);
                                cout << "Computer added!\n";
                            }
                        }
                    }
                }
            }
        }
    }
}

// Asks user to enter path to file. This WILL overwrite the default file.
void ConsoleUI::addComputersFromFile()
{

    string fileName = "";
    bool fileOpen = false;

    do
    {
        cout << "Enter the full path of the file, or the name of the file, if the file is in the same directory: " << endl;
        cout << "Type q and enter to cancel \n" << endl;
        cin >> fileName;
        if(fileName == "q" || fileName == "Q")
        {
            cout << "Adding computer from file canceled " << endl;
            computers();
        }
        if(serve.addComputersFromFile(fileName))
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

void ConsoleUI::deleteComputer()
{
    cout << "Enter name of computer(s) you would like to delete: ";
    string n = " ";
    cin >> ws;
    getline(cin, n);
    serve.sortComputers(1,1);
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
                cout << serve.listComputers()[v[i]];
            }
            char a = ' ';
            cin >> a;
            if (a == 'y' || a == 'Y')
            {
                for (int i = s-1; i >= 0; i--)
                {
                    serve.deleteComputer(n);
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

void ConsoleUI::saveComputersToFile()
{
    bool fileOpen = false;
    string fileName;
    do
    {
        cout << "WARNING: This will overwrite everything in the file selected!" << endl;
        cout << "If the File Doesn't exist, it will create a new file." << endl << endl;
        cout << "Enter the full path of the file, or the name of the file, if the file is in the same directory: " << endl;
        cin >> fileName;
        if(serve.saveComputersToFile(fileName))
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

//The header used when we list computers.
void ConsoleUI::printComputerLine()
{
    cout.width(30);
    cout << left << "Name";
    cout << "\tYear Made\tComputer Type\tBuilt?" << endl;
    cout << "_____________________________________________________" << endl;
}

void ConsoleUI::associations()
{
    bool run = true;

    while (run)
    {
        cout << " ================================" << endl;
        cout << " Press 1 to list the associations"    << endl;
        cout << " Press 2 to search associations"        << endl;
        cout << " Press 3 to add an association"       << endl;
        cout << " Press 4 to remove an association"    << endl;
        cout << " Press 5 to save to a custom file" << endl;
        cout << " Press 6 to go back to main menu"  << endl;
        cout << " Press 7 to quit"                  << endl;
        cout << " ================================" << endl;

        char input = '0';
        cin >> input;
        clearScreen();

        onlyTakeOneInput();                                                  // Takes only one letter and flushes the rest.
        int choice = input - '0';

        switch (choice)
           {
           case 1:
           {
               listAssociationData();
               break;
           }
           case 2:
           {
               searchAssociation();
               break;
           }
           case 3:
           {
               addAssociation();
               break;
           }
           case 4:
           {
               deleteAssociation();
               break;
           }
           case 5:
           {
               saveAssocToFile();
               break;
           }
           case 6:
           {
                run = false;
                break;
           }
           case 7:
           {
                exit (0);
                break;
           }

           default:
           {
               cout << "Error! Invalid input" << endl;
           }
           }
    }
}

void ConsoleUI::listAssociationData()
{
    char input = '0';
    int choice = 0;
    bool error = false;

    do
    {
        cout << "How would you like to sort the list?"   << endl;
        cout << " =================================="    << endl;
        cout << " Press 1 to sort by scientist name"               << endl;
        cout << " Press 2 to sort by computer name"         << endl;
        cout << " Press 3 to sort by year made"  << endl;
        cout << " Press 4 to sort by whether it was built"               << endl;
        cout << " Press 5 to sort by computer type" << endl;
        cout << " Press 6 to Cancel"                     << endl;
        cout << " =================================="    << endl;

        cin >> input;
        onlyTakeOneInput();
        clearScreen();
        choice = input - '0';
        input = '1';

        if (choice >= 1 && choice <= 5)
        {
            ascOrDescAssoc(choice);
            error = false;
        }
        else if (choice == 6)
        {
            error = false;
        }
        else
        {
            cout << "Error! Invalid input!" << endl;
            error = true;
        }
    }
    while (error);
}

void ConsoleUI::ascOrDescAssoc(int orderBy)
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

    if (order == 1 || order == 2)
    {
        printAssocLine();

        serve.sortAssociations(orderBy, order);
        for(unsigned int i = 0; i < serve.listAssociations().size(); i++)
        {
            cout << serve.listAssociations()[i];
        }
        cout << "_____________________________________________________" << endl;
    }
}

void ConsoleUI::searchAssociation()
{
    bool error = false;
    do
    {
        cout << "How would you like to search the data?"  << endl;
        cout << " ====================================="  << endl;
        cout << " Press 1 to search by scientist name"              << endl;
        cout << " Press 2 to search by computer name" << endl;
        cout << " Press 3 to search by year made"            << endl;
        cout << " Press 4 to search by year range" << endl;
        cout << " Press 5 to search by type"        << endl;
        cout << " Press 6 to cancel"                      << endl;
        cout << " ======================================" << endl;

        char input = '0';
        cin >> input;
        onlyTakeOneInput();
        int choice = input - '0';

        switch(choice)
        {
            case 1:
            {
                searchAssocBySciName();
                error = false;
                break;
            }
            case 2:
            {
                searchAssocByCompName();
                error = false;
                break;
            }
            case 3:
            {
                searchAssocByYear();
                error = false;
                break;
            }
            case 4:
            {
                searchAssocByYearRange();
                error = false;
                break;
            }
            case 5:
            {
                searchAssocByCompType();
                break;
            }
            case 6:
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

void ConsoleUI::searchAssocBySciName()
{
    string n = " ";
    cout << "Enter name: ";
    cin >> ws;
    getline(cin, n);
    serve.sortAssociations(0, 1);
    vector<int> vASN = serve.searchAssocBySciName(n);
    if (vASN.size() == 0)
    {
        cout << "No results found\n";
    }
    else
    {
        printAssocLine();
        for (unsigned int i = 0; i < vASN.size(); i++)
        {
            cout << serve.listAssociations()[vASN[i]];
        }
    }
}

void ConsoleUI::searchAssocByCompName()
{
    string n = " ";
    cout << "Enter name: ";
    cin >> ws;
    getline(cin, n);
    serve.sortAssociations(0,1);
    vector<int> vACN = serve.searchAssocByCompName(n);
    if (vACN.size() == 0)
    {
        cout << "No results found\n";
    }
    else
    {
        printAssocLine();
        for (unsigned int i = 0; i < vACN.size(); i++)
        {
            cout << serve.listAssociations()[vACN[i]];
        }
    }
}

void ConsoleUI::searchAssocByYear()
{
    int y = 0;
    string s = " ";
    while (!valid.validYear(s, y) || y == 0)
    {
        cout << "Enter year: ";
        cin >> s;
        if(!valid.validYear(s, y) || y == 0) {
            cout << "Invalid input!\n";
        }
    }
    serve.sortAssociations(0,1);
    vector<int> vAY = serve.searchAssocByYear(y);
    if (vAY.size() == 0)
    {
        cout << "No results found\n";
    }
    else
    {
        printAssocLine();
        for (unsigned int i = 0; i < vAY.size(); i++)
        {
            cout << serve.listAssociations()[vAY[i]];
        }
    }
}

void ConsoleUI::searchAssocByYearRange()
{
    int f = 0, l = 0;
    string s = " ";
    while(!valid.validYear(s, f))
    {
        cout << "Enter first year in range: ";
        cin >> s;
        if (!valid.validYear(s, f)) {
            cout << "Invalid input!\n";
        }
    }
    s = " ";
    while(!valid.validYear(s, l) || l < f)
    {
        cout << "Enter last year in range: ";
        cin >> s;
        if(!valid.validYear(s, l) || l < f)
        {
            cout << "Invalid input!\n";
        }
    }
    serve.sortAssociations(0,1);
    vector<int> vAR = serve.searchAssocByYearRange(f,l);
    if (vAR.size() == 0)
    {
        cout << "No results found" << endl;
    }
    else
    {
        printAssocLine();
        for (unsigned int i = 0; i < vAR.size(); i++)
        {
            cout << serve.listAssociations()[vAR[i]];
        }
    }
}

void ConsoleUI::searchAssocByCompType()
{
    string t = " ";
    cout << "Enter type: ";
    cin >> ws;
    getline(cin, t);
    serve.sortAssociations(0,1);
    vector<int> vACT = serve.searchAssocByCompType(t);
    if (vACT.size() == 0)
    {
        cout << "No results found\n";
    }
    else
    {
        printAssocLine();
        for (unsigned int i = 0; i < vACT.size(); i++)
        {
            cout << serve.listAssociations()[vACT[i]];
        }
    }
}

void ConsoleUI::addAssociation()
{
    string sN = " ", cN = " ";
    bool error = true;
    while (error)
    {
        cout << "Enter scientist name: ";
        cin >> ws;
        getline(cin, sN);
        if (serve.searchScientistByName(sN).size() == 0)
        {
            cout << "Scientist not found!";
        }
        else error = false;
    }
    error = true;
    while (error)
    {
        cout << "Enter computer name: ";
        cin >> ws;
        getline(cin, cN);
        if (serve.searchComputerByName(cN).size() == 0)
        {
            cout << "Computer not found!";
        }
        else error = false;
    }
    serve.sortScientists(1,1);
    Persons s = serve.listScientists()[serve.searchScientistByName(sN)[0]];
    serve.sortComputers(1,1);
    Computer c = serve.listComputers()[serve.searchComputerByName(cN)[0]];
    error = true;
    while (error)
    {
        cout << "Are you sure you want to associate " << s.getName() << " and " << c.getComputerName() << "? (Y/N)" << endl;
        char choice = ' ';
        cin >> choice;
        onlyTakeOneInput();
        if (choice == 'y' || choice == 'Y')
        {
            Association a(s, c);
            int x = 0;
            for (unsigned int i = 0; i < serve.listAssociations().size(); i++)
            {
                if(a == serve.listAssociations()[i])
                {
                    x++;
                    cout << "Association already on list!\n";
                    break;
                }
            }
            if (x == 0)
            {
                serve.addAssociation(a);
                cout << "Association added" << endl;
            }
            error = false;
        }
        else if (choice == 'n' || choice == 'N')
        {
            cout << "Association cancelled" << endl;
            error = false;
        }
        else
        {
            cout << "Invalid input!" << endl;
        }
    }
}

void ConsoleUI::deleteAssociation()
{
    string sN = " ", cN = " ";
    bool error = true;
    while (error)
    {
        while (error)
        {
            cout << "Enter scientist name: ";
            cin >> ws;
            getline(cin, sN);
            if (serve.searchScientistByName(sN).size() == 0)
            {
                cout << "Scientist not found!";
            }
            else error = false;
        }
        error = true;
        while (error)
        {
            cout << "Enter computer name: ";
            cin >> ws;
            getline(cin, cN);
            if (serve.searchComputerByName(cN).size() == 0)
            {
                cout << "Computer not found!";
            }
            else error = false;
        }
        serve.sortScientists(1,1);
        Persons s = serve.listScientists()[serve.searchScientistByName(sN)[0]];
        serve.sortComputers(1,1);
        Computer c = serve.listComputers()[serve.searchComputerByName(cN)[0]];
        Association a(s, c);
        for (unsigned int i = 0; i < serve.listAssociations().size(); i++)
        {
            if (a == serve.listAssociations()[i])
            {
                error = true;
                while (error)
                {
                    cout << "Are you sure you want to delete the following association?" << endl << a << endl << "Enter Y for yes or N for no" << endl;
                    char choice = ' ';
                    cin >> choice;
                    onlyTakeOneInput();
                    if (choice == 'y' || choice == 'Y')
                    {
                        serve.deleteAssociation(a.getScientistName(), a.getComputerName());
                        cout << "Association deleted" << endl;
                        error = false;
                        break;
                    }
                    else if (choice == 'n' || choice == 'N')
                    {
                        cout << "Delete cancelled" << endl;
                        error = false;
                        break;
                    }
                    else
                    {
                        cout << "Invalid input!" << endl;
                    }
                }
            }
        }
    }
}

void ConsoleUI::saveAssocToFile()
{
    bool fileOpen = false;
    string fileName;
    do
    {
        cout << "WARNING: This will overwrite everything in the file selected!" << endl;
        cout << "If the File Doesn't exist, it will create a new file." << endl << endl;
        cout << "Enter the full path of the file, or the name of the file, if the file is in the same directory: " << endl;
        cin >> fileName;
        if(serve.saveAssociationsToFile(fileName))
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

void ConsoleUI::printAssocLine()
{
    cout.width(26);
    cout << left << "Scientist\t";
    cout.width(20);
    cout << left << "Computer\tYear Made\t";
    cout.width(12);
    cout << "Built?\tComputer Type" << endl;
    cout << "_____________________________________________________" << endl;
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

//If the user entered too many commands, the rest will just be flushed. Fun stuff.
void ConsoleUI::onlyTakeOneInput()
{
    cin.clear();
    fflush(stdin);
}

//in the addScientistManually() function, errors will call upon this function.
//it then loops back into said function if you want.
bool ConsoleUI::check()
{
    char continuel;
    cout << "Do you want to try again? (Y for yes and N for no) " ;
    cin  >> continuel;
    if(continuel == 'Y' || continuel == 'y')
    {
        addScientistManually();
        return true;
    }
    else
    {
       return false;
    }
}
