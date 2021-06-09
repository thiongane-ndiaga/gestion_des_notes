#include "uiadministrateur.hpp"
#include "ui_uiadministrateur.h"
#include <QDebug>
/* Try -> #include "ui_uiadministrateur.h" ; if -> #include "ui_UIAdministrateur.h" not work*/

UIAdministrateur::UIAdministrateur(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UIAdministrateur)
{
    ui->setupUi(this);
}

UIAdministrateur::UIAdministrateur(QObject *controller)
    : ui(new Ui::UIAdministrateur)
{
    ui->setupUi(this);

    connect(ui->pushButtonValider, SIGNAL(clicked()),
            controller, SLOT(onUIAdministrateurValiderClicked()));
}

bool UIAdministrateur::getInputs(int* identifiant, QString &login, QString &prenom, QString &nom, QString &password, QString &type, bool* operation)
{
    if (ui->lineEditId->text().compare("") != 0)
        *identifiant = ui->lineEditId->text().toInt();

    login = ui->lineEditLogin->text();
    prenom = ui->lineEditPrenom->text();
    nom = ui->lineEditNom->text();
    password = ui->lineEditPassword->text();

    type = ui->comboBoxRole->currentText();
    *operation = ui->radioButtonCreate->isChecked(); // true si creation ...

    return true;
}

UIAdministrateur::~UIAdministrateur()
{
    delete ui;
}
