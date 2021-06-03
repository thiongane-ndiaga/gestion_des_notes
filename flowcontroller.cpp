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
                    break;

                case RESPONSABLE:
                    // On affiche la fenêtre du responsable ...
                    this->uiAuthentification->notificationInformation("UIResponsable :: Working on it !");
                    break;

                case FORMATEUR:
                    // On affiche la fenêtre du formateur ...
                    this->uiAuthentification->notificationInformation("UIFormateur :: Working on it !");
                    break;

                case ETUDIANT:
                    // On affiche la fenêtre de l'étudiant ...
                    this->uiAuthentification->notificationInformation("UIEtudiant :: Working on it !");
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
    QString password;
    QString type;
    bool operation;

    bool statut = this->uiAdministrateur->getInputs(&identifiant, login, password, type, &operation);
    if (statut == true)
    {
        if (operation == true)
        {
            // Creation
            User user ("", "", login, password);
            user.setType(type);

            service->createUser(user);
        }
        else
        {
            // Mise à jour ...
        }
    }
}

void FlowController::onUIAdministrateurListerClicked()
{

}

void FlowController::onUIAdministrateurEffacerClicked()
{

}

void FlowController::onUIAdministrateurSupprimerClicked()
{

}

void FlowController::onUIAdministrateurExitClicked()
{

}

void FlowController::onUIAdministrateurRechercherClicked()
{

}

void FlowController::onUIAdministrateurProfilClicked()
{

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
