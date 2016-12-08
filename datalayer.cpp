#include "datalayer.h"
#include <fstream>

DataLayer::DataLayer()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "VLN1.sqlite";
    db.setDatabaseName(dbName);
}

void DataLayer::readScientists(int orderBy, int ascOrDesc)
{
    db.open();

    QSqlQuery query(db);

    if (orderBy == 0)
    {
        if(ascOrDesc == 1)
        {
            query.exec("SELECT Name, Gender, Birthyear, Deathyear FROM Scientists ORDER BY ID");
        }
        else if (ascOrDesc == 2)
        {
            query.exec("SELECT Name, Gender, Birthyear, Deathyear FROM Scientists ORDER BY ID DESC");
        }
    }
    else if (orderBy == 1)
    {
        if (ascOrDesc == 1)
        {
            query.exec("SELECT Name, Gender, Birthyear, Deathyear FROM Scientists ORDER BY Name");
        }
        else if (ascOrDesc == 2)
        {
            query.exec("SELECT Name, Gender, Birthyear, Deathyear FROM Scientists ORDER BY Name DESC");
        }
    }
    else if (orderBy == 2)
    {
        if (ascOrDesc == 1)
        {
            query.exec("SELECT Name, Gender, Birthyear, Deathyear FROM Scientists ORDER BY Gender");
        }
        else if (ascOrDesc == 2)
        {
            query.exec("SELECT Name, Gender, Birthyear, Deathyear FROM Scientists ORDER BY Gender DESC");
        }
    }
    else if (orderBy == 3)
    {
        if (ascOrDesc == 1)
        {
            query.exec("SELECT Name, Gender, Birthyear, Deathyear FROM Scientists ORDER BY Birthyear");
        }
        else if (ascOrDesc == 2)
        {
            query.exec("SELECT Name, Gender, Birthyear, Deathyear FROM Scientists ORDER BY Birthyear DESC");
        }
    }
    else if (orderBy == 4)
    {
        if (ascOrDesc == 1)
        {
            query.exec("SELECT Name, Gender, Birthyear, Deathyear FROM Scientists ORDER BY Deathyear");
        }
        else if (ascOrDesc == 2)
        {
            query.exec("SELECT Name, Gender, Birthyear, Deathyear FROM Scientists ORDER BY Deathyear DESC");
        }
    }

    vector<Persons> S;
    while(query.next())
    {
        string name = query.value("Name").toString().toStdString();
        string gdr = query.value("Gender").toString().toStdString();
        char g = gdr[0];
        int bY = query.value("Birthyear").toUInt();
        int dY = query.value("Deathyear").toUInt();

        Persons p(name, g, bY, dY);
        S.push_back(p);
    }
    db.close();
    scientists = S;
}

void DataLayer::readComputers(int orderBy, int ascOrDesc)
{
    db.open();

    QSqlQuery query(db);

    if (orderBy == 0)
    {
        if (ascOrDesc == 1)
        {
            query.exec("SELECT ComputerName, YearMade, Type, BuiltOrNot FROM Computers ORDER BY ComputerID");
        }
        else if (ascOrDesc == 2)
        {
            query.exec("SELECT ComputerName, YearMade, Type, BuiltOrNot FROM Computers ORDER BY ComputerID DESC");
        }
    }
    else if (orderBy == 1)
    {
        if (ascOrDesc == 1)
        {
            query.exec("SELECT ComputerName, YearMade, Type, BuiltOrNot FROM Computers ORDER BY ComputerName");
        }
        else if (ascOrDesc == 2)
        {
            query.exec("SELECT ComputerName, YearMade, Type, BuiltOrNot FROM Computers ORDER BY ComputerName DESC");
        }
    }
    else if (orderBy == 2)
    {
        if (ascOrDesc == 1)
        {
            query.exec("SELECT ComputerName, YearMade, Type, BuiltOrNot FROM Computers ORDER BY YearMade");
        }
        else if (ascOrDesc == 2)
        {
            query.exec("SELECT ComputerName, YearMade, Type, BuiltOrNot FROM Computers ORDER BY YearMade DESC");
        }
    }
    else if (orderBy == 3)
    {
        if (ascOrDesc == 1)
        {
            query.exec("SELECT ComputerName, YearMade, Type, BuiltOrNot FROM Computers ORDER BY Type");
        }
        else if (ascOrDesc == 2)
        {
            query.exec("SELECT ComputerName, YearMade, Type, BuiltOrNot FROM Computers ORDER BY Type DESC");
        }
    }
    else if (orderBy == 4)
    {
        if (ascOrDesc == 1)
        {
            query.exec("SELECT ComputerName, YearMade, Type, BuiltOrNot FROM Computers ORDER BY BuiltOrNot");
        }
        else if (ascOrDesc == 2)
        {
            query.exec("SELECT ComputerName, YearMade, Type, BuiltOrNot FROM Computers ORDER BY BuiltOrNot DESC");
        }
    }

    vector<Computer> C;
    while(query.next())
    {
        string n = query.value("ComputerName").toString().toStdString();
        int yM = query.value("YearMade").toUInt();
        string t = query.value("Type").toString().toStdString();
        bool b = query.value("BuiltOrNot").toBool();

        Computer c(n, yM, t, b);
        C.push_back(c);
    }
    db.close();
    computers = C;
}

void DataLayer::addScientist(const Persons& p)
{
    db.open();

    QSqlQuery query(db);

    query.prepare("INSERT INTO Scientists(Name, Gender, Birthyear, Deathyear, Alive) "
                          "VALUES (:Name, :Gender, :Birthyear, :Deathyear, :Alive)");
    query.bindValue(0, QString::fromStdString(p.getName()));
    query.bindValue(1, QVariant(p.getGender()).toChar());
    query.bindValue(2, QVariant(p.getBirthYear()));
    query.bindValue(3, QVariant(p.getDeathYear()));
    if (p.getAlive())
    {
        query.bindValue(4, QString::fromStdString("Yes"));
    }
    else
    {
        query.bindValue(4, QString::fromStdString("No"));
    }

    query.exec();

    db.close();

    scientists.push_back(p);
}

void DataLayer::addComputer(const Computer& c)
{
    db.open();

    QSqlQuery query(db);

    query.prepare("INSERT INTO Computers(ComputerName, YearMade, Type, BuiltOrNot)"
                          "VALUES (:ComputerName, :YearMade, :Type, :BuiltOrNot)");
    query.bindValue(0, QString::fromStdString(c.getComputerName()));
    query.bindValue(1, QVariant(c.getYearMade()));
    query.bindValue(2, QString::fromStdString(c.getType()));
    if (c.getBuiltOrNot())
    {
        query.bindValue(3, QString::fromStdString("Built"));
    }
    else
    {
        query.bindValue(3, QString::fromStdString("Not Built"));
    }
    query.exec();

    db.close();

    computers.push_back(c);
}

bool DataLayer::addScientistsFromFile(string input)
{
    Persons p;
    ifstream in;

    in.open(input);

    if (in.fail())
    {
        in.close();
        return false;
    }
    else
    {
        in.seekg(100);

        while(in >> p)
        {
            //Checks if person is valid, i.e. has a valid name, gender, birthyear and deathyear.
            //An invalid person will not be added.
            Persons compare;
            if (p != compare)
            {
                addScientist(p);
            }
        }
        in.close();

        return true;
    }
}

bool DataLayer::addComputersFromFile(string input)
{
    Computer c;
    ifstream in;

    in.open(input);

    if (in.fail())
    {
        in.close();
        return false;
    }
    else
    {
        in.seekg(100);

        while(in >> c)
        {
            //Checks if person is valid, i.e. has a valid name, gender, birthyear and deathyear.
            //An invalid person will not be added.
            Computer compare;
            if (c != compare)
            {
                addComputer(c);
            }
        }
        in.close();

        return true;
    }
}

vector<int> DataLayer::getScientistIDs()
{
    vector<int> sIDs;
    db.open();

    QSqlQuery query(db);

    query.exec("SELECT ID FROM Scientists ORDER BY Name");

    while (query.next())
    {
        int id = query.value("ID").toUInt();
        sIDs.push_back(id);
    }

    db.close();
    return sIDs;
}

vector<int> DataLayer::getComputerIDs()
{
    vector<int> cIDs;
    db.open();

    QSqlQuery query(db);

    query.exec("SELECT ComputerID FROM Computers ORDER BY ComputerName");

    while (query.next())
    {
        int id = query.value("ComputerID").toUInt();
        cIDs.push_back(id);
    }

    db.close();
    return cIDs;
}

vector<int> DataLayer::searchScientistByName(const string name)
{
    vector<int> vSN;
    vector<int> sIDs = getScientistIDs();
    db.open();

    QSqlQuery query(db);

    query.exec("SELECT * FROM Scientists WHERE Name LIKE '%" + QString::fromStdString(name) + "%' ORDER BY Name");

    while (query.next())
    {
        int id = query.value("ID").toUInt();
        for (unsigned int i = 0; i < sIDs.size(); i++)
        {
            if (id == sIDs[i])
            {
                vSN.push_back(i);
                break;
            }
        }
    }

    db.close();
    return vSN;
}

vector<int> DataLayer::searchScientistByGender(const char gender)
{
    vector<int> vSG;
    db.open();

    QSqlQuery query(db);

    query.exec("SELECT ID FROM Scientists WHERE Gender = '" + QString(QVariant(gender).toChar()) + "' ORDER BY Name");

    while (query.next())
    {
        int id = query.value("ID").toUInt();
        for (unsigned int i = 0; i < getScientistIDs().size(); i++)
        {
            if (id == getScientistIDs()[i])
            {
                vSG.push_back(i);
                break;
            }
        }
    }

    db.close();
    return vSG;
}

vector<int> DataLayer::searchScientistByBirthYear(const int year)
{
    vector<int> vSBY;
    db.open();

    QSqlQuery query(db);

    query.exec("SELECT ID FROM Scientists WHERE birthYear = " + QVariant(year).toString() + " ORDER BY Name");

    while (query.next())
    {
        int id = query.value("ID").toUInt();
        for (unsigned int i = 0; i < getScientistIDs().size(); i++)
        {
            if (id == getScientistIDs()[i])
            {
                vSBY.push_back(i);
                break;
            }
        }
    }

    db.close();
    return vSBY;
}

vector<int> DataLayer::searchScientistByYearRange(const int f, const int l)
{
    vector<int> vSBR;
    db.open();

    QSqlQuery query(db);

    query.exec("SELECT ID FROM Scientists WHERE birthYear >= " + QVariant(f).toString() + " AND birthYear <= " + QVariant(l).toString() + " ORDER BY Name");

    while (query.next())
    {
        int id = query.value("ID").toUInt();
        for (unsigned int i = 0; i < getScientistIDs().size(); i++)
        {
            if (id == getScientistIDs()[i])
            {
                vSBR.push_back(i);
                break;
            }
        }
    }

    db.close();
    return vSBR;
}

vector<int> DataLayer::searchComputerByName(const string name)
{
    vector<int> vCBN;
    db.open();

    QSqlQuery query(db);

    query.exec("SELECT ComputerID FROM Computers WHERE ComputerName LIKE '%" + QString::fromStdString(name) + "%' ORDER BY ComputerName");

    while (query.next())
    {
        int id = query.value("ComputerID").toUInt();
        for (unsigned int i = 0; i < getComputerIDs().size(); i++)
        {
            if (id == getComputerIDs()[i])
            {
                vCBN.push_back(i);
                break;
            }
        }
    }

    db.close();
    return vCBN;
}

vector<int> DataLayer::searchComputerByYearMade(const int year)
{
    vector<int> vCYM;
    db.open();

    QSqlQuery query(db);

    query.exec("SELECT ComputerID FROM Computers WHERE YearMade = " + QVariant(year).toString() + " ORDER BY ComputerName");

    while (query.next())
    {
        int id = query.value("ComputerID").toUInt();
        for (unsigned int i = 0; i < getComputerIDs().size(); i++)
        {
            if (id == getComputerIDs()[i])
            {
                vCYM.push_back(i);
                break;
            }
        }
    }

    db.close();
    return vCYM;
}

vector<int> DataLayer::searchComputerByYearRange(const int f, const int l)
{
    vector<int> vCYR;
    db.open();

    QSqlQuery query(db);

    query.exec("SELECT ComputerID FROM Computers WHERE YearMade >= " + QVariant(f).toString() + " AND YearMade <= " + QVariant(l).toString() + " ORDER BY ComputerName");

    while (query.next())
    {
        int id = query.value("ComputerID").toUInt();
        for (unsigned int i = 0; i < getComputerIDs().size(); i++)
        {
            if (id == getComputerIDs()[i])
            {
                vCYR.push_back(i);
                break;
            }
        }
    }

    db.close();
    return vCYR;
}

vector<int> DataLayer::searchComputerByType(const string type)
{
    vector<int> vCBT;
    db.open();

    QSqlQuery query(db);

    query.exec("SELECT ComputerID FROM Computers WHERE Type LIKE '%" + QString::fromStdString(type) + "%' ORDER BY ComputerName");

    while (query.next())
    {
        int id = query.value("ComputerID").toUInt();
        for (unsigned int i = 0; i < getComputerIDs().size(); i++)
        {
            if (id == getComputerIDs()[i])
            {
                vCBT.push_back(i);
                break;
            }
        }
    }

    db.close();
    return vCBT;
}

void DataLayer::deleteScientist(string n)
{
    db.open();

    QSqlQuery query(db);

    query.exec("DELETE FROM Scientists WHERE Name LIKE '%" + QString::fromStdString(n) + "%'");

    db.close();
}

void DataLayer::deleteComputer(string n)
{
    db.open();

    QSqlQuery query(db);

    query.exec("DELETE FROM Computers WHERE ComputerName LIKE '%" + QString::fromStdString(n) + "%'");

    db.close();
}

vector<Persons> DataLayer::getScientistVector()
{
    return scientists;
}

vector<Computer> DataLayer::getComputerVector()
{
    return computers;
}
