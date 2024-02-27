#ifndef FILE_H
#define FILE_H

#include <QVector>
#include "user.h"
#include <QJsonArray>
#include <QDialog>
#include "profil.h"

class File
{
public:
    File();
    int read();
    int write();
    void addUser(User user);
    User* getUserWithName(QString name);
    User getUsersWithIndex(int i);
    unsigned int getNumberUser();
    bool isEmpty();
    int userExist(QString name);
    void addProfils(Profil profil);
    int removeProfil(QString profil);
    Profil getProfilsWithIndex(int i);
    unsigned int getNumberProfil();
    Profil getProfil(QString s);
    QJsonArray userProfilsToJson(User u);
    int numberAdmin();
    void removeUser(QString u);

private:
    QString path;
    QVector<User> users;
    bool profilExistInUsers(QString profil);
    QJsonArray userToJson();
    QJsonArray profilsToJson();
    QVector <Profil> profils;
};

#endif // FILE_H
