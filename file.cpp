#include "file.h"
#include <QVectorIterator>

file::file() {}

void file::addUser(User user) { //double user !!!
    this->users.append(user);
}

QString file::getPasswordWithName(QString name) {
    QVectorIterator<User> Vi(this->users);
    while (Vi.hasNext()) {
        User u = Vi.next();
        if (u.getName() == name)
            return u.getPassword();
    }
    return "";
}
