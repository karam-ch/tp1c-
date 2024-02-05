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

const QString User::getName() {
    return this->name;
}

const QString User::getPassword() {
    return this->password;
}

bool User::getAdmin() {
    return this->admin;
}
