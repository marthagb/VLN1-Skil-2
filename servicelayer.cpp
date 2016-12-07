#include "servicelayer.h"
#include <fstream>


ServiceLayer::ServiceLayer()
{

}

vector<Persons> ServiceLayer::listScientists(int orderBy, int ascOrDesc)
{
    dl.readScientists(orderBy, ascOrDesc);
    return dl.getScientistVector();
}

vector<Computer> ServiceLayer::listComputers(int orderBy, int ascOrDesc)
{
    dl.readComputers(orderBy, ascOrDesc);
    return dl.getComputerVector();
}

vector<int> ServiceLayer::searchScientistByName(const string name)
{
    return dl.searchScientistByName(name);
}

vector<int> ServiceLayer::searchScientistByGender(const char gender)
{
    return dl.searchScientistByGender(gender);
}

vector<int> ServiceLayer::searchScientistByBirthYear(const int year)
{
    return dl.searchScientistByBirthYear(year);
}

vector<int> ServiceLayer::searchScientistByYearRange(const int f, const int l)
{
    return dl.searchScientistByYearRange(f, l);
}

vector<int> ServiceLayer::searchComputerByName(const string name)
{
    return dl.searchComputerByName(name);
}

vector<int> ServiceLayer::searchComputerByYearMade(const int year)
{
    return dl.searchComputerByYearMade(year);
}

vector<int> ServiceLayer::searchComputerByYearRange(const int f, const int l)
{
    return dl.searchComputerByYearRange(f, l);
}

vector<int> ServiceLayer::searchComputerByType(const string type)
{
    return dl.searchComputerByType(type);
}

void ServiceLayer::addScientist(const Persons &p)
{
    dl.addScientist(p);
}

bool ServiceLayer::addScientistsFromFile(string input)
{
    return dl.addScientistsFromFile(input);
}

void ServiceLayer::deleteScientist(string n)
{
    dl.deleteScientist(n);
}

void ServiceLayer::addComputer(const Computer &c)
{
    dl.addComputer(c);
}

bool ServiceLayer::addComputersFromFile(string input)
{
    return dl.addComputersFromFile(input);
}

void ServiceLayer::deleteComputer(string n)
{
    dl.deleteComputer(n);
}

bool ServiceLayer::saveScientistsToFile(string input)
{
   ofstream out;
   out.open(input);

   if(out.fail())
   {
               return false;
   }
    else
   {
       out.width(26);
       out << left << "Name";
       out << "\tGender\tBorn\tDied" << endl;
       out << "_____________________________________________________" << endl;

       out.seekp(100);
       for(size_t i = 0; i < dl.getScientistVector().size(); i++)
       {

       out << dl.getScientistVector()[i];

       }

    }
           out.close();
           return true;

}

bool ServiceLayer::saveComputersToFile(string input)
{
   ofstream out;
   out.open(input);

   if(out.fail())
   {
         return false;
   }
    else
   {
       out.width(30);
       out << left << "Name";
       out << "\tBuilding Year\tComputer type\tBuilt?" << endl;
       out << "_____________________________________________________" << endl;

       out.seekp(100);
       out << endl;
       for(size_t i = 0; i < dl.getComputerVector().size(); i++)
       {
            out << dl.getComputerVector()[i];
       }

    }
           out.close();
           return true;

}
