#include "uiauthentification.hpp"
#include "ui_uiauthentification.h"

#include <QMessageBox>

UIAuthentification::UIAuthentification(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UIAuthentification)
{
    ui->setupUi(this);
}

UIAuthentification::UIAuthentification(QObject *controller)
    : ui(new Ui::UIAuthentification)
{
    ui->setupUi(this);

    connect(ui->pushButtonLogin, SIGNAL(clicked()),
            controller, SLOT(onUIAuthentificationLogInClicked()));

    connect(ui->pushButtonQuitter, SIGNAL(clicked()),
            controller, SLOT(onUIAuthentificationExitClicked()));
}

bool UIAuthentification::getInputs (QString &login, QString &password)
{
    login = ui->lineEditLogin->text();
    password = ui->lineEditPassword->text();

    if (login.compare("") == 0 ||
            password.compare("") == 0) {

        QMessageBox::critical(this, "Informations manquantes",
                              "Veuillez remplir tous les champs !",
                              QMessageBox::Ok);
        return false;
    }

    return true;
}

void UIAuthentification::notificationError (QString message)
{
    QMessageBox::critical(this, "Error", message, QMessageBox::Ok);
}

void UIAuthentification::notificationInformation (QString message)
{
    QMessageBox::information(this, "Information", message, QMessageBox::Ok);
}

UIAuthentification::~UIAuthentification()
{
    delete ui;
}
