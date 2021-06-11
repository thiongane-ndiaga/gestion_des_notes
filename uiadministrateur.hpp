#ifndef UIADMINISTRATEUR_H
#define UIADMINISTRATEUR_H

#include <QMainWindow>
#include "ui_uiadministrateur.h"
#include "user.hpp"

namespace Ui {
    class UIAdministrateur;
}

class UIAdministrateur : public QMainWindow
{
    Q_OBJECT

public:
    UIAdministrateur(QWidget *parent = nullptr);
    UIAdministrateur(QObject *controller = nullptr);

    bool getInputs(int* identifiant, QString &login, QString &prenom, QString &nom, QString &password, QString &type, bool* operation);
    void setProfileInputs(User u);
    void clearInputs();
    void getTextSeacrh(QString &login);
    void getIdSeacrh(int* id);
    QString searchMode();
    int getUserToRemove();


    ~UIAdministrateur();

    void setTableView(QAbstractItemModel *model);
    void notificationError (QString message);
    void notificationInformation (QString message);

private slots:
    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    Ui::UIAdministrateur *ui;
};

#endif // UIADMINISTRATEUR_H
