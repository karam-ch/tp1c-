#include "user.h"

User::User() {

}

void User::setName(QString name) {
    this->name = name;
}

void User::setPassword(QString password) {
    this->password = password;
}

void User::setAdmin(bool admin) {
    this->admin = admin;
}

QString User::getName() {
    return this->name;
}

QString User::getPassword() {
    return this->password;
}

bool User::getAdmin() {
    return this->admin;
}

void User::clear() {
    name = "";
    password = "";
    Profils.clear();
    admin = 0;
}

bool User::profilExist(QString s) {
    for (int i = 0 ; i < this->Profils.size() ; i++) {
        if (this->Profils[i].getName() == s) {
            return true;
        }
    }
    return false;
}

void User::addProfils(Profil profil) {
    this->Profils.push_back(profil);
}

QVector <Profil> User::getProfils() {
    return this->Profils;
}

void User::removeProfil(QString s) {
    // this->Profils.removeIf(this->Profils.begin(), this->Profils.end(), [](QString s) { return s == profil.getName() });
    for (unsigned int i = 0; i < Profils.size(); i++) {
        if (s == Profils[i].getName())
        {
            Profils.removeAt(i);
            break;
        }
    }
}
