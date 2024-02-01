#ifndef CONNEXION_H
#define CONNEXION_H

#include <QDialog>
#include "file.h"

namespace Ui {
class Connexion;
}

class Connexion : public QDialog
{
    Q_OBJECT

public:
    explicit Connexion(QWidget *parent = nullptr);
    Connexion(file*);
    ~Connexion();

private slots:


    void on_connectButton_clicked();

private:
    Ui::Connexion *ui;
    file *f;
};

#endif // CONNEXION_H
