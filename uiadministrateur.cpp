#include "uiadministrateur.hpp"
#include "ui_uiadministrateur.h"
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

    connect(ui->pushButtonConfirm, SIGNAL(clicked()),
            controller, SLOT(onUIAdministrateurValiderClicked()));
}

bool UIAdministrateur::getInputs(int* identifiant, QString &login, QString &password, QString &type, bool* operation)
{
    if (ui->lineEditId_3->text().compare("") != 0)
        *identifiant = ui->lineEditId_3->text().toInt();

    login = ui->lineEditUsername_3->text();
    password = ui->lineEditPassword_3->text();
    type = ui->comboBoxRole_3->itemText(0);
    *operation = ui->radioButtonCreate->isChecked(); // true si creation ...

    return true;
}

UIAdministrateur::~UIAdministrateur()
{
    delete ui;
}
