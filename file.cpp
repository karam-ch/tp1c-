#include "file.h"
#include <QVectorIterator>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QObject>
#include <iostream>


File::File() {
    this->users = QVector<User>();
    this->path = "./app.json";
}

void File::addUser(User user) {
    this->users.push_back(user);
}

void File::addProfils(Profil profil) {
    this->profils.push_back(profil);
}

int File::removeProfil(QString profil) {
    if (profilExistInUsers(profil)) {
        return 1;
    }

    for (int i = 0 ; i < this->profils.size(); i++ ) {
        if (this->profils[i].getName() == profil) {
            this->profils.removeAt(i);
            return 0;
        }
    }
}

int File::userExist(QString name)
{
    for (int i = 0; i < this->users.size(); i++) {
        if (this->users[i].getName() == name)
            return 1;
    }
    return 0;
}

bool File::profilExistInUsers(QString profil) {
    for (int i = 0; i < this->users.size(); i++) {
        if (this->users[i].profilExist(profil)) {
            return 1;
}
    }
    return 0;
}


Profil File::getProfil(QString str) {
    for (unsigned int i = 0; i < getNumberProfil(); i++) {
        if (this->profils[i].getName() == str ) {
            return this->profils[i];
        }
    }
    return Profil();
}

User File::getUsersWithIndex(int i) {
    return this->users.at(i);
}

unsigned int File::getNumberUser() {
    return users.size();
}

Profil File::getProfilsWithIndex(int i) {
    return this->profils.at(i);
}

unsigned int File::getNumberProfil() {
    return profils.size();
}

User* File::getUserWithName(QString name) {
    for (int i = 0; i < this->users.size(); i++) {
        if (this->users[i].getName() == name) {
            return &this->users[i];
        }
    }
    return new User();
}

int File::numberAdmin() {
    int nb = 0;
    for (int i = 0 ; i < this->users.size() ; i++ ) {
        if (users[i].getAdmin()) {
            nb++;
        }
    }
    return nb;
}

void File::removeUser(QString u) {
    for (int i = 0; i < this->users.size(); i++) {
        if (this->users[i].getName() == u) {
            this->users[i].clear();
            this->users.remove(i);
            // return 0;
        }
    }
}

int File::write() {
    QJsonObject JO;

    JO.insert("Users",userToJson());
    JO.insert("Profils",profilsToJson());
    QJsonDocument document;
    document.setObject(JO);
    QByteArray bytes = document.toJson(QJsonDocument::Indented);
    QFile file(this->path);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        QTextStream iStream(&file);
        iStream << bytes;
        file.close();
    } else {
        std::cout << "file error when writing" << std::endl;
        return 1;
    }


    return 0;
}


QJsonArray File::userToJson() {
    QJsonArray content;
    QVectorIterator<User> Vi(this->users);
    while (Vi.hasNext()) {
        User u = Vi.next();
        QJsonObject ju;
        ju.insert("name", u.getName());
        ju.insert("password", u.getPassword());
        ju.insert("admin", QString::number(u.getAdmin()));
        ju.insert("profils",userProfilsToJson(u));
        content.push_back(ju);
    }
    return content;
}

QJsonArray File::profilsToJson() {
    QJsonArray content;
    QVectorIterator<Profil> Vi(this->profils);
    while (Vi.hasNext()) {
        Profil p = Vi.next();
        QJsonObject ju;
        ju.insert("name", p.getName());
        ju.insert("db", QString::number(p.getDb()));
        content.push_back(ju);
    }
    return content;
}

QJsonArray File::userProfilsToJson (User u) {
    QJsonArray content;
    QVectorIterator<Profil> Vi(u.getProfils());
    while (Vi.hasNext()) {
        Profil p = Vi.next();
        QJsonObject ju;
        ju.insert("name", p.getName());
        content.push_back(ju);
    }
    return content;
}

int File::read() {
    QFile file(this->path);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        std::cout << "file error when reading" << std::endl;
        return 1;
    }
    QTextStream in(&file);
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    doc.object();
    QJsonArray A = doc.object().value("Profils").toArray();
    for (int i = 0; i < A.size(); i++) {
        Profil f;
        f.setName(A[i].toObject().value("name").toString());
        f.setDb(A[i].toObject().value("db").toString().toInt());
        this->addProfils(f);
    }
    A = doc.object().value("Users").toArray();
    for (int i = 0; i < A.size(); i++) {
        User u;
        u.setName(A[i].toObject().value("name").toString());
        u.setPassword(A[i].toObject().value("password").toString());
        u.setAdmin(A[i].toObject().value("admin").toString().toInt());
        QJsonArray temp = A[i].toObject().value("profils").toArray();
        for (int i = 0 ; i < temp.size() ; i++) {
            u.addProfils(getProfil(temp[i].toObject().value("name").toString()));
        }
        this->addUser(u);
    }

    return 0;
}

// Check if the list of users is empty.
bool File::isEmpty() {
    return this->users.isEmpty();
}

