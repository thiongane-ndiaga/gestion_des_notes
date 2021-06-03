#ifndef SERVICE_H
#define SERVICE_H
#include "user.hpp"
#include "usermodel.hpp"
#include <QDebug>
#include <QMessageBox>

class Service
{
private:
    static Service* instance; // The single instance
    QString connection;

    Service();
    ~Service();

public:
    // How to get the single instance of Service
    static Service* getInstance();

    // How the release the single instance of DBAccess
    static void release();

    bool authentifier(QString login, QString password, User* user);
    void createUser(User user);
};

#endif // SERVICE_H
