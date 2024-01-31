#ifndef CONNEXION_H
#define CONNEXION_H

#include <QDialog>

namespace Ui {
class Connexion;
}

class Connexion : public QDialog
{
    Q_OBJECT

public:
    explicit Connexion(QWidget *parent = nullptr);
    ~Connexion();

private slots:


    void on_connectButton_clicked();

private:
    Ui::Connexion *ui;
    // void ;
};

#endif // CONNEXION_H
