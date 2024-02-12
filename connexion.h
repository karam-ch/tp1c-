#ifndef CONNEXION_H
#define CONNEXION_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Connexion;
}

class Connexion : public QDialog
{
    Q_OBJECT

public:
    explicit Connexion(MainWindow* f, QWidget *parent = nullptr);
    ~Connexion();

private slots:


    void on_connectButton_clicked();

private:
    Ui::Connexion *ui;
    MainWindow *w;
};

#endif // CONNEXION_H
