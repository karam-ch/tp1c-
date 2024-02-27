#include "profil.h"

Profil::Profil() {}

QString Profil::getName() {
    return this->name   ;
}

int Profil::getDb() {
    return this->Db;
}

void Profil::setName(QString name) {
    this->name = name;
}

void Profil::setDb(int db) {
    this->Db = db;
}
