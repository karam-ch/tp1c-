#ifndef FILE_H
#define FILE_H
#include <QVector>
#include "user.h"
#include <QJsonArray>

class file
{
public:
    file();
    void read();
    void write();
    void addUser(User user);
    User getUserWithName(QString name);
    bool isEmpty();

private:
    QVector<User> users;
    QJsonArray toJson();
};

#endif // FILE_H
