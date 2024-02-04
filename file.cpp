#include "file.h"
#include <QVectorIterator>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QTextStream>
#include <iostream>

file::file() {
    this->users = QVector<User>();
}

void file::addUser(User user) { //double user !!!
    this->users.push_back(user);

}

QString file::getPasswordWithName(QString name) {
std::cout << "users : " << this->users.size() << std::endl;
    for (int i = 0 ; i < this->users.size(); i++)
    {
        std::cout << "i " << this->users[i].getName().toStdString() << std::endl;
        if (this->users[i].getName() == name) {
            return this->users[i].getPassword();
        }
    }

    // QVectorIterator<User> Vi(this->users);
    // while (Vi.hasNext()) {
    //     User u = Vi.next();
    //     if (u.getName() == name)
    //         return u.getPassword();
    // }
    return "";
}

void file::write() {
    QJsonArray content = toJson();
    //content.insert()
    QJsonDocument document;
    document.setArray(content);
    QByteArray bytes = document.toJson( QJsonDocument::Indented );
    QFile file( "/home/chris/app.json" );
    if( file.open( QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate ) )
    {
        QTextStream iStream( &file );
        // iStream.setCodec( "utf-8" );
        iStream << bytes;
        file.close();
    }
    else
    {
        std::cout << "file open failed: " << std::endl;
    }
}

QJsonArray file::toJson() {
    QJsonArray content;
    QVectorIterator<User> Vi(this->users);
    while (Vi.hasNext()) {
        User u = Vi.next();
        QJsonObject ju;
        ju.insert("name", u.getName());
        ju.insert("password", u.getPassword());
        content.push_back(ju);
    }
    return content;
}


void file::read() {

    QFile file( "/home/chris/app.json" );
    if (!file.open(QFile::ReadOnly | QFile::Text))
        return ;
    QTextStream in(&file);
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    QJsonArray A = doc.array();
    std::cout << "A : " << A.size() << std::endl;
    for (int i = 0 ; i < A.size() ; i++)
    {
        User u;
        u.setName(A[i].toObject().value("name").toString());
        u.setPassword(A[i].toObject().value("password").toString());
        this->addUser(u);
    }

    // std::cout << s.toStdString();
}

bool file::isEmpty() {
    return this->users.isEmpty();
}
