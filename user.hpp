#ifndef USER_H
#define USER_H

#include <QString>

enum TypeUser {
    ADMINISTRATEUR,
    FORMATEUR,
    ETUDIANT,
    RESPONSABLE
};

class User
{
private:
    uint identifiant;
    QString nom;
    QString prenom;
    QString login;
    QString password;
    QString type;

public:
    User();
    User(uint, QString, QString, QString, QString);
    User(QString, QString, QString, QString);

    uint getIdentifiant() { return identifiant; }
    QString getNom() { return nom; }
    QString getPrenom() { return prenom; }
    QString getLogin() { return login; }
    QString getPassword() { return password; }
    TypeUser getType() ;

    void setIdentifiant(uint identifiant) { this->identifiant = identifiant; }
    void setNom(QString nom) { this->nom = nom; }
    void setPrenom(QString prenom) { this->prenom = prenom; }
    void setLogin(QString login) {  this->login = login; }
    void setPassword(QString password) { this->password = password; }
    void setType(QString type) { this->type = type; }
};

#endif // USER_H
