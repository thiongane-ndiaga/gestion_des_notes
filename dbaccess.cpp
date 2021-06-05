#include "dbaccess.hpp"
#include <QDebug>

// Here we define the static DBAccess pointer
DBAccess* DBAccess::instance = nullptr;

DBAccess* DBAccess::getInstance() {
   if (instance == nullptr) {
      instance = new DBAccess();
   }

   return instance;
}

void DBAccess::release() {
   if (instance != nullptr) {
      delete instance;
   }
}

DBAccess::DBAccess()
{
    /*
     * Créer une base de données SQLITE avec "DB browser for SQLite"
     */
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Programme C++/gestion-des-notes/gestion_notes.db");

    qDebug() << "DBAccess Object created and 'gestion_notes.db' has been added as default database!";
}

bool DBAccess::open()
{
    if (db.isOpen()) return true;

    if (db.open())
    {
       qDebug() << "Connection opened with QSQLITE Database [OK]";
       return true;
    }
    else
    {
       qDebug() << "Connection failure with QSQLITE Database [KO]";
       return false;
    }
}

void DBAccess::close()
{
    if (!db.isOpen()) return;

    db.close();
    qDebug() << "Connection closed with QSQLITE Database [OK]";
}

DBAccess::~DBAccess()
{
    qDebug() << "DBAccess Object has been deleted!";
}
