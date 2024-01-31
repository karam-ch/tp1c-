#ifndef USER_H
#define USER_H
#include <QString>
#include <QVector>
#include "profil.h"

class User
{
public:
    User();
    const QString getName();
    const QString getPassword();
    const QVector <Profil> getProfils();
    void setName(QString name);
    void setPassword(QString password);
    void addProfils(Profil profil);
    // void removeProfil();

private:
    QString name;
    QString password;
    QVector <Profil> Profils;
};


#endif // USER_H
