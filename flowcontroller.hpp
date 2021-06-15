#ifndef FRONTCONTROLLER_H
#define FRONTCONTROLLER_H

#include "uiauthentification.hpp"
#include "uiadministrateur.hpp"
#include "uiresponsable.hpp"
#include "uietudiant.hpp"
#include "uiformateur.hpp"
#include "service.hpp"

class FlowController : public QObject
{
    Q_OBJECT

private:
    // Les interfaces graphiques (UIComponent)
    UIAuthentification* uiAuthentification;
    UIAdministrateur* uiAdministrateur;
    UIResponsable* uiResponsable;
    UIEtudiant* uiEtudiant;
    UIFormateur* uiFormateur;
    // Couche Service (BusinessLayerComponent)
    Service* service;

private slots:

    /**
     * @brief onUIAuthentification buttons clicked
     * définit les traitements à exécuter
     * lorsqu'un événement se produit sur l'un des boutons
     * de la fenêtre d'authentification
     */
    void onUIAuthentificationLogInClicked();
    void onUIAuthentificationSignUpClicked();
    void onUIAuthentificationExitClicked();

    /**
     * @brief onUIAdministrateur buttons clicked
     * définit les traitements à exécuter
     * lorsqu'un événement se produit sur l'un des boutons
     * de la fenêtre de l'administrateur
     */
    void onUIAdministrateurValiderClicked();
    void onUIAdministrateurListerClicked();
    void onUIAdministrateurEffacerClicked();
    void onUIAdministrateurSupprimerClicked();
    void onUIAdministrateurExitClicked();
    void onUIAdministrateurRechercherClicked();
    void onUIAdministrateurProfilClicked();

    /**
     * @brief onUIResponsable buttons clicked
     * définit les traitements à exécuter
     * lorsqu'un événement se produit sur l'un des boutons
     * de la fenêtre du responsable
     */

    void onUIResponsableValiderClicked();
    //void onUIResponsableModifierClicked();
    void onUIResponsableListerClicked();
    void onUIResponsableEffacerClicked();
    void onUIResponsableSupprimerClicked();
    void onUIResponsableExitClicked();
    void onUIResponsableRechercherClicked();
    void onUIResponsableProfilClicked();

    /**
      @brief onUIFormateur buttons clicked
     * définit les traitements à exécuter
     * lorsqu'un événement se produit sur l'un des boutons
     * de la fenêtre du formateur
     */

    void onUIFormateurValiderClicked();
    void onUIFormateurListerClicked();
    void onUIFormateurEffacerClicked();
    void onUIFormateurSupprimerClicked();
    void onUIFormateurExitClicked();
    void onUIFormateurRechercherClicked();
    void onUIFormateurProfilClicked();

    /**
      @brief onUIEtudiant buttons clicked
     * définit les traitements à exécuter
     * lorsqu'un événement se produit sur l'un des boutons
     * de la fenêtre de l'étudiant
     */

    void onUIEtudiantModifierClicked();
    void onUIEtudiantListerClicked();

public:
    void exec();

    FlowController();
    ~FlowController();
};

#endif // FLOWTCONTROLLER_H
