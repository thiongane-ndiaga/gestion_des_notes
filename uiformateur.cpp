#include "uiformateur.hpp"

UIFormateur::UIFormateur(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UIFormateur)
{
    ui->setupUi(this);
}

UIFormateur::UIFormateur(QObject *controller)
    : ui(new Ui::UIFormateur)
{
    ui->setupUi(this);
}

void UIFormateur::setProfileInputs(User u){
    ui->lineEditIdProfil->setText(QString::number(u.getIdentifiant()));
    ui->lineEditLoginProfil->setText(u.getLogin());
    ui->lineEditPrenomProfil->setText(u.getPrenom());
    ui->lineEditNomProfil->setText(u.getNom());
    ui->lineEditPasswordProfil->setText(u.getPassword());
    ui->lineEditConfirmPasswordProfil->setText(u.getPassword());

    //Utilisateur connecté: Prenom nom
    ui->labelUtilisateurConnecte->setText(u.getPrenom()+" "+u.getNom());
}

UIFormateur::~UIFormateur()
{
    delete ui;
}
