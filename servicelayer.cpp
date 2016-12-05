#include "servicelayer.h"
#include <QtSql>


ServiceLayer::ServiceLayer()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "VLN1.sqlite";
    db.setDatabaseName(dbName);
    db.open();

    QSqlQuery query(db);

    query.exec("SELECT ID, name, gender, birthYear, deathYear FROM Scientists");

    while(query.next())
    {
        int id = query.value("ID").toUInt();
        string name = query.value("name").toString().toStdString();
        string g = query.value("gender").toString().toStdString();
        int bY = query.value("birthYear").toUInt();
        int dY = query.value("deathYear").toUInt();

        Persons p(id, name, g, bY, dY);
        people.push_back(p);
    }
    db.close();
    db.removeDatabase("QSQLITE");

}

vector<Persons> ServiceLayer::list()
{
    return people;
}
