#include "service.hpp"

// Here we define the static Service pointer
Service* Service::instance = nullptr;

Service::Service() {
    connection = DBAccess::getInstance()->database().connectionName();
}

Service* Service::getInstance()
{
    if (instance == nullptr) {
       instance = new Service();
    }

    return instance;
}

void Service::release()
{
    if (instance != nullptr) {
        delete instance;
    }
}

bool Service::authentifier (QString login, QString password, User* user)
{
    UserModel userModel(DBAccess::getInstance());

    if (true == userModel.readBy(login, password, user))
    {
        return true;
    }

    return false;
}

void Service::createUser(User user)
{
    UserModel userModel(DBAccess::getInstance());
    userModel.create(user);
}

UserModel* Service::listUsers(){
    UserModel * userModel = new UserModel(DBAccess::getInstance());
    userModel->readAll();
    return userModel;
}

bool Service::doThisUserExists(QString login){
    UserModel userModel(DBAccess::getInstance());
    return userModel.readBy(login);
}

UserModel* Service::findUserByLogin(QString login){
    UserModel* userModel = new UserModel(DBAccess::getInstance());
    userModel->readByLoginSearch(login);
    return userModel;
}
UserModel* Service::findUserById(int id)
{
    UserModel* userModel = new UserModel(DBAccess::getInstance());
    userModel->readBy(id);
    return userModel;
}

void Service::updateUser(User user){
    UserModel userModel(DBAccess::getInstance());
    userModel.update(user);
}

void Service::deleteUser(uint id){
    UserModel userModel(DBAccess::getInstance());
    userModel.remove(id);
}

Service::~Service()
{
    DBAccess::release();
    QSqlDatabase::removeDatabase(connection);
    qDebug() << "Service Object has been deleted!";
}
