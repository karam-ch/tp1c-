#ifndef USER_H
#define USER_H
#include <QString>
#include <QVector>
#include "profil.h"

class User
{
public:
    User();
    QString getName();
    QString getPassword();
    QVector <Profil> getProfils();
    bool getAdmin();
    void setName(QString name);
    void setPassword(QString password);
    void addProfils(Profil profil);
    void setAdmin(bool admin);
    void clear();
    void removeProfil(QString s);
    bool profilExist(QString s);


private:
    QString name;
    QString password;
    QVector <Profil> Profils;
    bool admin;
};


#endif // USER_H
