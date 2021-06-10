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

    int getUserToRemove();
    ~UIAdministrateur();

    void setTableView(QAbstractItemModel *model);

private:
    Ui::UIAdministrateur *ui;
};

#endif // UIADMINISTRATEUR_H
