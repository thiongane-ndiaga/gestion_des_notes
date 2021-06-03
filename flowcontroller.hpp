#ifndef FRONTCONTROLLER_H
#define FRONTCONTROLLER_H

#include "uiauthentification.hpp"
#include "uiadministrateur.hpp"
#include "service.hpp"

class FlowController : public QObject
{
    Q_OBJECT

private:
    // Les interfaces graphiques (UIComponent)
    UIAuthentification* uiAuthentification;
    UIAdministrateur* uiAdministrateur;

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

public:
    void exec();

    FlowController();
    ~FlowController();
};

#endif // FLOWTCONTROLLER_H
