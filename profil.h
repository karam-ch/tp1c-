#ifndef PROFIL_H
#define PROFIL_H
#include <QString>

class Profil
{
public:
    Profil();
    QString getName();
    int getDb();
    void setName(QString name);
    void setDb(int db);

private:
    QString name;
    int Db;  //Add class Db currently a placeholder
};

#endif // PROFIL_H
