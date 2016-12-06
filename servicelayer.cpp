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

    if (orderBy == 1)
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

    if (orderBy == 1)
    {
        if (ascOrDesc == 1)
        {
            query.exec("SELECT ComputerName, YearMade, Type, BuiltOrNot FROM Computers ORDER BY name");
        }
        else if (ascOrDesc == 2)
        {
            query.exec("SELECT ComputerName, YearMade, Type, BuiltOrNot FROM Computers ORDER BY name DESC");
        }
    }
    else if (orderBy == 2)
    {
        if (ascOrDesc == 1)
        {
            query.exec("SELECT ComputerName, YearMade, Type, BuiltOrNot FROM Computers ORDER BY buildYear");
        }
        else if (ascOrDesc == 2)
        {
            query.exec("SELECT ComputerName, YearMade, Type, BuiltOrNot FROM Computers ORDER BY buildYear DESC");
        }
    }
    else if (orderBy == 3)
    {
        if (ascOrDesc == 1)
        {
            query.exec("SELECT ComputerName, YearMade, Type, BuiltOrNot FROM Computers ORDER BY type");
        }
        else if (ascOrDesc == 2)
        {
            query.exec("SELECT ComputerName, YearMade, Type, BuiltOrNot FROM Computers ORDER BY type DESC");
        }
    }
    else if (orderBy == 4)
    {
        if (ascOrDesc == 1)
        {
            query.exec("SELECT ComputerName, YearMade, Type, BuiltOrNot FROM Computers ORDER BY built");
        }
        else if (ascOrDesc == 2)
        {
            query.exec("SELECT ComputerName, YearMade, Type, BuiltOrNot FROM Computers ORDER BY built DESC");
        }
    }

    while(query.next())
    {
        string n = query.value("ComputerName").toString().toStdString();
        int bY = query.value("YearMade").toUInt();
        string t = query.value("Type").toString().toStdString();
        bool b = query.value("BuiltOrNot").toBool();

        Computer c(n, bY, t, b);
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

    query.prepare("INSERT INTO Computers(name, buildYear, type, built)"
                          "VALUES (:name, :buildYear, :type, :built)");
    query.bindValue(0, QString::fromStdString(c.getName()));
    query.bindValue(1, QVariant(c.getBuildYear()));
    query.bindValue(2, QString::fromStdString(c.getType()));
    query.bindValue(3, QVariant(c.getBuilt()).toBool());
    query.exec();

    db.close();
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

    query.exec("DELETE FROM Computers WHERE ID = " + QString::number(n));

    db.close();
}
