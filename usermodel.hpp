#ifndef USERMODEL_H
#define USERMODEL_H

#include <QSqlQueryModel>

#include "dbaccess.hpp"
#include <user.hpp>

class UserModel : public QSqlQueryModel
{
private:
    DBAccess *dbAccess;

public:
    UserModel(DBAccess *dbAccess);
    ~UserModel();

    void clear();

    // CRUD methods
    void create(User user);
    void update(User user);
    void remove(uint identifiant);
    bool readBy(QString login);
    bool readBy(int id);
    bool readBy(QString login, QString password, User *user);
    void readAll();
    bool readByLoginSearch(QString login);

};

#endif // USERMODEL_H
