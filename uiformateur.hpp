#ifndef UIFORMATEUR_HPP
#define UIFORMATEUR_HPP

#include <QMainWindow>
#include "ui_uiformateur.h"
#include "user.hpp"

namespace Ui {
class UIFormateur;
}

class UIFormateur : public QMainWindow
{
    Q_OBJECT

public:
     UIFormateur(QWidget *parent = nullptr);
     UIFormateur(QObject *controller);
    ~UIFormateur();

     bool getInputs(int* identifiant, QString &login, QString &prenom, QString &nom, QString &password, QString &confirmPassword, QString &type, bool* operation, bool isProfile);
     void setProfileInputs(User u);
     void clearInputs();
     void getTextSearch(QString &login);
     void getIdSearch(int* id);
     QString searchMode();
     int getUserToRemove();

     void setTableView(QAbstractItemModel *model);
     void clearTableView();
     void notificationError (QString message);
     void notificationInformation (QString message);

private:
    Ui::UIFormateur *ui;
};

#endif // UIFORMATEUR_HPP
