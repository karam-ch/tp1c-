#ifndef FILE_H
#define FILE_H

#include <QVector>
#include "user.h"
#include <QJsonArray>
#include <QDialog>

class File
{
public:
    File();
    int read();
    int write();
    void addUser(User user);
    User getUserWithName(QString name);
    bool isEmpty();

private:
    QVector<User> users;
    QJsonArray toJson();
};

#endif // FILE_H
