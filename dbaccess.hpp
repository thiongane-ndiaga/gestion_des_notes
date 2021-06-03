#ifndef DBACCESS_H
#define DBACCESS_H
#include <QSqlDatabase>

class DBAccess
{
private:
    static DBAccess* instance; // The single instance
    QSqlDatabase db;

    DBAccess(); // private constructor
    ~DBAccess(); // private destructor

public:
    QSqlDatabase database() { return db; }

    bool open();
    void close();

    // How to get the single instance of DBAccess
    static DBAccess* getInstance();

    // How the release the single instance of DBAccess
    static void release();
};

#endif // DBACCESS_H
