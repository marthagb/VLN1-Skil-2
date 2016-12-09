#include "servicelayer.h"



ServiceLayer::ServiceLayer()
{

}

vector<Persons> ServiceLayer::listScientists()
{
    return dl.getScientistVector();
}

vector<Computer> ServiceLayer::listComputers()
{
    return dl.getComputerVector();
}

vector<Association> ServiceLayer::listAssociations()
{
    return dl.getAssociationVector();
}

void ServiceLayer::sortScientists(int orderBy, int ascOrDesc)
{
    dl.readScientists(orderBy, ascOrDesc);
}

void ServiceLayer::sortComputers(int orderBy, int ascOrDesc)
{
    dl.readComputers(orderBy, ascOrDesc);
}

void ServiceLayer::sortAssociations(int orderBy, int ascOrDesc)
{
    dl.readAssociations(orderBy, ascOrDesc);
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

vector<int> ServiceLayer::searchAssocBySciName(const string sN)
{
    return dl.searchAssocBySciName(sN);
}

vector<int> ServiceLayer::searchAssocByCompName(const string cN)
{
    return dl.searchAssocByCompName(cN);
}

vector<int> ServiceLayer::searchAssocByYear(const int year)
{
    return dl.searchAssocByYear(year);
}

vector<int> ServiceLayer::searchAssocByYearRange(const int f, const int l)
{
    return dl.searchAssocByYearRange(f,l);
}

vector<int> ServiceLayer::searchAssocByCompType(const string type)
{
    return dl.searchAssocByCompType(type);
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

void ServiceLayer::addAssociation(const Association& a)
{
    dl.addAssociation(a);
}

void ServiceLayer::deleteAssociation(string sN, string cN)
{
    dl.deleteAssociation(sN, cN);
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
       out.width(20);
       out << left << "Name";
       out << "\tYear\tComputer type\t\tBuilt?" << endl;
       out << "______________________________________________________________________" << endl;

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

bool ServiceLayer::saveAssociationsToFile(string input)
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
        out << left << "Scientist\t";
        out.width(20);
        out << left << "Computer\tYear Made\tBuilt?\tComputer Type" << endl;
        out << "______________________________________________________________________" << endl;

        out.seekp(100);
        out << endl;
        for(size_t i = 0; i < dl.getAssociationVector().size(); i++)
        {
             out << dl.getAssociationVector()[i];
        }

     }
            out.close();
            return true;
}
