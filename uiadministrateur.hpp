#ifndef UIADMINISTRATEUR_H
#define UIADMINISTRATEUR_H

#include <QMainWindow>
#include "ui_uiadministrateur.h"

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
    int getUserToRemove();
    void populateForm();


    ~UIAdministrateur();

    void setTableView(QAbstractItemModel *model);

private:
    Ui::UIAdministrateur *ui;
};

#endif // UIADMINISTRATEUR_H
