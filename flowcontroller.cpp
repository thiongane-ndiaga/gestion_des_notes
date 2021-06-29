#include "flowcontroller.hpp"
#include <QDebug>

FlowController::FlowController() :
    uiAuthentification (nullptr),
    uiAdministrateur (nullptr),
    service (Service::getInstance())
{}

/**
 * @brief onUIAuthentification buttons clicked
 * définit les traitements à exécuter
 * lorsqu'un événement se produit sur l'un des boutons
 * de la fenêtre d'authentification
 */
void FlowController::onUIAuthentificationLogInClicked()
{
    // 1- Récupérer le login et le mot de passe depuis UIAuthentification
    // 2- Demander à la couche Service de valider l'authentification
    // en lui fournissant le login, le password récupérés et le user à renseigner ...

    QString login;
    QString password;

    bool statut = uiAuthentification->getInputs (login, password);
    if (statut == true)
    {
        User user;
        statut = service->authentifier(login, password, &user);
        if (statut == true)
        {
            // 1- Fermer la fenêtre d'authentification ...
            this->uiAuthentification->close();
            // 2- Libérer les ressources ...
            delete uiAuthentification;
            uiAuthentification = nullptr;

            // 3- Ouvrir les interfaces Utilisateurs ...
            // Selon leur type ...
            TypeUser userType = user.getType();
            switch (userType)
            {
                case ADMINISTRATEUR:
                    // On affiche la fenêtre d'administration ...
                    uiAdministrateur = new UIAdministrateur(this);
                    uiAdministrateur->show();
                    // On affiche le profil
                    uiAdministrateur->setProfileInputs(user);
                    // On affiche les donnees sur le tableau
                    uiAdministrateur->setTableView(service->listUsers());
                    break;

                case RESPONSABLE:
                    // On affiche la fenêtre du responsable ...
                    uiResponsable = new UIResponsable(this);
                    uiResponsable->show();
                    break;

                case FORMATEUR:
                    // On affiche la fenêtre du formateur ...
                    uiFormateur = new UIFormateur(this);
                    uiFormateur->show();
                    uiFormateur->setProfileInputs(user);
                    break;

                case ETUDIANT:
                    // On affiche la fenêtre de l'étudiant ...
                    uiEtudiant = new UIEtudiant(this);
                    uiEtudiant->show();
                    break;
                default:;
            }
        }
        else
        {
            this->uiAuthentification->notificationError("Echec d'authentification !");
        }
    }
}

void FlowController::onUIAuthentificationSignUpClicked()
{

}

void FlowController::onUIAuthentificationExitClicked()
{
     this->uiAuthentification->close();
}

/**
 * @brief onUIAdministrateur buttons clicked
 * définit les traitements à exécuter
 * lorsqu'un événement se produit sur l'un des boutons
 * de la fenêtre de l'administrateur
 */
void FlowController::onUIAdministrateurValiderClicked()
{
    int identifiant = -1;
    QString login;
    QString prenom;
    QString nom;
    QString password;
    QString confirmPassword;
    QString type;
    bool operation;

    bool statut = this->uiAdministrateur->getInputs(&identifiant, login, prenom, nom, password, confirmPassword, type, &operation, false);
    if (statut == true)
    {
         qDebug () << "Data recup successfully!";
         User user (nom, prenom, login, password);
         user.setType(type);
        if (operation == true)
        {
            if(service->doThisUserExists(login)){
                this->uiAdministrateur->notificationError("Un utilisateur avec ce login existe déja !");
            }else{
                if(password.compare(confirmPassword) != 0){
                    this->uiAdministrateur->notificationError("Les deux mots de passe ne correspondent pas !");
                } else {
                    // Creation
                    service->createUser(user);

                    this->uiAdministrateur->setTableView(service->listUsers());
                    // On vide les champs
                    this->uiAdministrateur->clearInputs();
                }
            }

        }
        else
        {
            if(password.compare(confirmPassword) != 0){
                this->uiAdministrateur->notificationError("Les deux mots de passe ne correspondent pas !");
            } else {
                // Mise à jour ...
                user.setIdentifiant(identifiant);
                service->updateUser(user);
                this->uiAdministrateur->setTableView(service->listUsers());
            }

        }
    }
}

void FlowController::onUIAdministrateurListerClicked()
{
    // On affiche les donnees sur le tableau
    this->uiAdministrateur->setTableView(service->listUsers());
}

void FlowController::onUIAdministrateurEffacerClicked()
{
    //this->uiAdministrateur->clearTableView();
}

void FlowController::onUIAdministrateurSupprimerClicked()
{
    int id = this->uiAdministrateur->getUserToRemove();
    qDebug () <<"ID TO REMOVE" << id;
    service->deleteUser(id);
    // On affiche les donnees sur le tableau
    this->uiAdministrateur->setTableView(service->listUsers());
}

void FlowController::onUIAdministrateurExitClicked()
{
    this->uiAdministrateur->close();
}

void FlowController::onUIAdministrateurRechercherClicked()
{
    int identifiant = -1;
    QString login;

    if("id" == this->uiAdministrateur->searchMode())
    {
        this->uiAdministrateur->getIdSeacrh(&identifiant);
        this->uiAdministrateur->setTableView(service->findUserById(identifiant));

    }
    else
    {
        this->uiAdministrateur->getTextSeacrh(login);
        this->uiAdministrateur->setTableView(service->findUserByLogin(login));

    }
}

void FlowController::onUIAdministrateurModifierProfilClicked()
{
    int identifiant = -1;
    QString login;
    QString prenom;
    QString nom;
    QString password;
    QString confirmPassword;
    QString type;
    bool operation;

    bool statut = this->uiAdministrateur->getInputs(&identifiant, login, prenom, nom, password, confirmPassword, type, &operation, true);
    if (statut == true){
        qDebug () << "Je suis entrain de modifier !";
        User user (nom, prenom, login, password);
        user.setType(type);
        if(password.compare(confirmPassword) != 0){
            this->uiAdministrateur->notificationError("Les deux mots de passe ne correspondent pas !");
        } else {
            // Mise à jour ...
            user.setIdentifiant(identifiant);
            service->updateUser(user);
            this->uiAdministrateur->setTableView(service->listUsers());
        }
    }
}

void FlowController::exec()
{
    uiAuthentification = new UIAuthentification(this);
    uiAuthentification->show();
}

FlowController::~FlowController()
{
    if (uiAuthentification != nullptr)
    {
        delete uiAuthentification;
    }

    if (uiAdministrateur != nullptr)
    {
        delete uiAdministrateur;
    }

    if (service != nullptr)
    {
        Service::release();
    }
}


/**
 * @brief onUIResponsable buttons clicked
 * définit les traitements à exécuter
 * lorsqu'un événement se produit sur l'un des boutons
 * de la fenêtre du responsable
 */

void FlowController::onUIResponsableValiderClicked()
{

}
//void onUIResponsableModifierClicked();
void FlowController::onUIResponsableListerClicked()
{

}
void FlowController::onUIResponsableEffacerClicked()
{

}
void FlowController::onUIResponsableSupprimerClicked()
{

}
void FlowController::onUIResponsableExitClicked()
{

}
void FlowController::onUIResponsableRechercherClicked()
{

}
void FlowController::onUIResponsableProfilClicked()
{

}


/**
  @brief onUIFormateur buttons clicked
 * définit les traitements à exécuter
 * lorsqu'un événement se produit sur l'un des boutons
 * de la fenêtre du formateur
 */

void FlowController::onUIFormateurValiderClicked()
{

}
void FlowController::onUIFormateurListerClicked()
{

}
void FlowController::onUIFormateurEffacerClicked()
{

}
void FlowController::onUIFormateurSupprimerClicked()
{

}
void FlowController::onUIFormateurExitClicked()
{

}
void FlowController::onUIFormateurRechercherClicked()
{

}
void FlowController::onUIFormateurProfilClicked()
{

}

/**
  @brief onUIEtudiant buttons clicked
 * définit les traitements à exécuter
 * lorsqu'un événement se produit sur l'un des boutons
 * de la fenêtre de l'étudiant
 */

void FlowController::onUIEtudiantModifierClicked()
{

}
void FlowController::onUIEtudiantListerClicked()
{

}
