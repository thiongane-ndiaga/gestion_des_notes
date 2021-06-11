#include "uiadministrateur.hpp"
#include "ui_uiadministrateur.h"
#include <QMessageBox>
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

void UIAdministrateur::setProfileInputs(User u){
    ui->lineEditIdProfil->setText(QString::number(u.getIdentifiant()));
    ui->lineEditLoginProfil->setText(u.getLogin());
    ui->lineEditPrenomProfil->setText(u.getPrenom());
    ui->lineEditNomProfil->setText(u.getNom());
    ui->lineEditPasswordProfil->setText(u.getPassword());
    ui->lineEditConfirmPasswordProfil->setText(u.getPassword());

}

void UIAdministrateur::clearInputs(){
    ui->lineEditId->setText("");
    ui->lineEditLogin->setText("");
    ui->lineEditPrenom->setText("");
    ui->lineEditNom->setText("");
    ui->lineEditPassword->setText("");
    ui->lineEditConfirmPassword->setText("");
    ui->comboBoxRole->setCurrentIndex(0);
    ui->radioButtonCreate->setChecked(true);
}

int UIAdministrateur::getUserToRemove()
{
    return ui->tableView->selectionModel()->selectedRows(0).value(0).data().toInt();
}


void UIAdministrateur::on_tableView_doubleClicked(const QModelIndex &index)
{
    int currentRow = index.row();
    int id = ui->tableView->model()->index(currentRow,0).data().toInt();

    ui->lineEditId->setText(QString::number(id));
    ui->lineEditLogin->setText(ui->tableView->model()->index(currentRow,1).data().toString());
    ui->lineEditPrenom->setText(ui->tableView->model()->index(currentRow,2).data().toString());
    ui->lineEditNom->setText(ui->tableView->model()->index(currentRow,3).data().toString());
    ui->lineEditPassword->setText(ui->tableView->model()->index(currentRow,4).data().toString());
    ui->lineEditConfirmPassword->setText(ui->tableView->model()->index(currentRow,4).data().toString());
    ui->comboBoxRole->setCurrentIndex(ui->tableView->model()->index(currentRow,5).data().toInt());
    ui->radioButtonModify->setChecked(true);
}

void UIAdministrateur::notificationError (QString message)
{
    QMessageBox::critical(this, "Erreur", message, QMessageBox::Ok);
}

void UIAdministrateur::notificationInformation (QString message)
{
    QMessageBox::information(this, "Information", message, QMessageBox::Ok);
}

UIAdministrateur::~UIAdministrateur()
{
    delete ui;
}



