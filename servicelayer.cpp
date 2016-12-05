#include "servicelayer.h"
#include <QtSql>

ServiceLayer::ServiceLayer()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "VLN1.sqlite";
    db.setDatabaseName(dbName);
}
