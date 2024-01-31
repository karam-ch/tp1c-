#ifndef FILE_H
#define FILE_H
#include <QVector>
#include "user.h"

class file
{
public:
    file();
    void read();
    void write();
    void addUser(User user);
    QString getPasswordWithName(QString name);


private:
     QVector<User> users;
};

#endif // FILE_H
