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

    connect(ui->pushButtonLister, SIGNAL(clicked()),
            controller, SLOT(onUIAdministrateurListerClicked()));

    connect(ui->pushButtonSupprimer, SIGNAL(clicked()),
            controller, SLOT(onUIAdministrateurSupprimerClicked()));

    connect(ui->tableView->selectionModel(), SIGNAL(selectionChanged(const QModelIndex &, const QModelIndex &)),
            controller, SLOT(onUIAdministrateurProfilClicked()));
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

void UIAdministrateur::setTableView(QAbstractItemModel *model){
    ui->tableView->setModel(model);
}

int UIAdministrateur::getUserToRemove()
{
    return ui->tableView->selectionModel()->selectedRows(0).value(0).data().toInt();
}

void UIAdministrateur::populateForm(){
    qDebug() << "----------" << ui->tableView->selectionModel()->selectedRows(0).value(0).data().toString();
   // ui->lineEditNom->setText(ui->tableView->selectionModel()->selectedRows(0).value(0).data().toString());
}

UIAdministrateur::~UIAdministrateur()
{
    delete ui;
}
