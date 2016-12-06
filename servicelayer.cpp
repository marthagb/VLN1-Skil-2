#include "servicelayer.h"
#include <QtSql>


ServiceLayer::ServiceLayer()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "VLN1.sqlite";
    db.setDatabaseName(dbName);
}

vector<Persons> ServiceLayer::readScientists(int orderBy, int ascOrDesc)
{
    vector<Persons> people;
    db.open();

    QSqlQuery query(db);

    if (orderBy == 0)
    {
        if(ascOrDesc == 1)
        {
            query.exec("SELECT name, gender, birthYear, deathYear FROM Scientists ORDER BY ID");
        }
        else if (ascOrDesc == 2)
        {
            query.exec("SELECT name, gender, birthYear, deathYear FROM Scientists ORDER BY ID DESC");
        }
    }
    else if (orderBy == 1)
    {
        if (ascOrDesc == 1)
        {
            query.exec("SELECT name, gender, birthYear, deathYear FROM Scientists ORDER BY name");
        }
        else if (ascOrDesc == 2)
        {
            query.exec("SELECT name, gender, birthYear, deathYear FROM Scientists ORDER BY name DESC");
        }
    }
    else if (orderBy == 2)
    {
        if (ascOrDesc == 1)
        {
            query.exec("SELECT name, gender, birthYear, deathYear FROM Scientists ORDER BY gender");
        }
        else if (ascOrDesc == 2)
        {
            query.exec("SELECT name, gender, birthYear, deathYear FROM Scientists ORDER BY gender DESC");
        }
    }
    else if (orderBy == 3)
    {
        if (ascOrDesc == 1)
        {
            query.exec("SELECT name, gender, birthYear, deathYear FROM Scientists ORDER BY birthYear");
        }
        else if (ascOrDesc == 2)
        {
            query.exec("SELECT name, gender, birthYear, deathYear FROM Scientists ORDER BY birthYear DESC");
        }
    }
    else if (orderBy == 4)
    {
        if (ascOrDesc == 1)
        {
            query.exec("SELECT name, gender, birthYear, deathYear FROM Scientists ORDER BY deathYear");
        }
        else if (ascOrDesc == 2)
        {
            query.exec("SELECT name, gender, birthYear, deathYear FROM Scientists ORDER BY deathYear DESC");
        }
    }

    while(query.next())
    {
        string name = query.value("name").toString().toStdString();
        string gdr = query.value("gender").toString().toStdString();
        char g = gdr.at(0);
        int bY = query.value("birthYear").toUInt();
        int dY = query.value("deathYear").toUInt();

        Persons p(name, g, bY, dY);
        people.push_back(p);
    }
    db.close();
    return people;
}

vector<Computer> ServiceLayer::readComputers(int orderBy, int ascOrDesc)
{
    vector<Computer> computers;
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

    while(query.next())
    {
        string n = query.value("ComputerName").toString().toStdString();
        int yM = query.value("YearMade").toUInt();
        string t = query.value("Type").toString().toStdString();
        bool b = query.value("BuiltOrNot").toBool();

        Computer c(n, yM, t, b);
        computers.push_back(c);
    }
    db.close();
    return computers;
}

void ServiceLayer::addScientist(const Persons& p)
{
    db.open();

    QSqlQuery query(db);

    query.prepare("INSERT INTO Scientists(name, gender, birthYear, deathYear, alive) "
                          "VALUES (:name, :gender, :birthYear, :deathYear, :alive)");
    query.bindValue(0, QString::fromStdString(p.getName()));
    query.bindValue(1, QVariant(p.getGender()).toChar());
    query.bindValue(2, QVariant(p.getBirthYear()));
    query.bindValue(3, QVariant(p.getDeathYear()));
    query.bindValue(4, QVariant(p.getAlive()).toBool());

    query.exec();

    db.close();
}

void ServiceLayer::addComputer(const Computer& c)
{
    db.open();

    QSqlQuery query(db);

    query.prepare("INSERT INTO Computers(ComputerName, YearMade, Type, BuiltOrNot)"
                          "VALUES (:ComputerName, :YearMade, :Type, :BuiltOrNot)");
    query.bindValue(0, QString::fromStdString(c.getComputerName()));
    query.bindValue(1, QVariant(c.getYearMade()));
    query.bindValue(2, QString::fromStdString(c.getType()));
    query.bindValue(3, QVariant(c.getBuiltOrNot()).toBool());
    query.exec();

    db.close();
}

vector<int> ServiceLayer::searchScientistByName(const string name)
{
    vector<int> vSN;
    db.open();

    QSqlQuery query(db);

    query.exec("SELECT ID FROM Scientists WHERE name LIKE '%" + QString::fromStdString(name) + "%'");

    while (query.next())
    {
        int id = query.value("ID").toUInt();
        vSN.push_back(id-1);
    }

    db.close();
    return vSN;
}

vector<int> ServiceLayer::searchScientistByGender(const char gender)
{
    vector<int> vSG;
    db.open();

    QSqlQuery query(db);

    query.exec("SELECT ID FROM Scientists WHERE Gender = '" + QString(QVariant(gender).toChar()) + "'");

    while (query.next())
    {
        int id = query.value("ID").toUInt();
        vSG.push_back(id-1);
    }

    db.close();
    return vSG;
}

vector<int> ServiceLayer::searchScientistByBirthYear(const int year)
{
    vector<int> vSBY;
    db.open();

    QSqlQuery query(db);

    query.exec("SELECT ID FROM Scientists WHERE birthYear = " + QVariant(year).toString());

    while (query.next())
    {
        int id = query.value("ID").toUInt();
        vSBY.push_back(id-1);
    }

    db.close();
    return vSBY;
}

vector<int> ServiceLayer::searchScientistByRange(const int f, const int l)
{
    vector<int> vSBR;
    db.open();

    QSqlQuery query(db);

    query.exec("SELECT ID FROM Scientists WHERE birthYear >= " + QVariant(f).toString() + " AND birthYear <= " + QVariant(l).toString());

    while (query.next())
    {
        int id = query.value("ID").toUInt();
        vSBR.push_back(id-1);
    }

    db.close();
    return vSBR;
}

vector<int> ServiceLayer::searchComputerByName(const string name)
{
    vector<int> vCBN;
    db.open();

    QSqlQuery query(db);

    query.exec("SELECT ComputerID FROM Computers WHERE name LIKE '%" + QString::fromStdString(name) + "%'");

    while (query.next())
    {
        int id = query.value("ComputerID").toUInt();
        vCBN.push_back(id-1);
    }

    db.close();
    return vCBN;
}

vector<int> ServiceLayer::searchComputerByYearMade(const int year)
{
    vector<int> vCYM;
    db.open();

    QSqlQuery query(db);

    query.exec("SELECT ComputerID FROM Computers WHERE buildYear = " + QVariant(year).toString());

    while (query.next())
    {
        int id = query.value("ComputerID").toUInt();
        vCYM.push_back(id-1);
    }

    db.close();
    return vCYM;
}

vector<int> ServiceLayer::searchComputerByType(const string type)
{
    vector<int> vCBT;
    db.open();

    QSqlQuery query(db);

    query.exec("SELECT ComputerID FROM Computers WHERE type LIKE '%" + QString::fromStdString(type) + "%'");

    while (query.next())
    {
        int id = query.value("ComputerID").toUInt();
        vCBT.push_back(id-1);
    }

    db.close();
    return vCBT;
}

void ServiceLayer::deleteScientist(int n)
{
    db.open();

    QSqlQuery query(db);

    query.exec("DELETE FROM Scientists WHERE ID = " + QString::number(n));

    db.close();
}

void ServiceLayer::deleteComputer(int n)
{
    db.open();

    QSqlQuery query(db);

    query.exec("DELETE FROM Computers WHERE ComputerID = " + QString::number(n));

    db.close();
}
