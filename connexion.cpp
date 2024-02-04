#include "connexion.h"
#include "ui_connexion.h"
#include "account.h"
#include "file.h"
// #include <iostream>
#include <QMessageBox>
#include <QCryptographicHash>



Connexion::Connexion(file *f, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Connexion)
{
    ui->setupUi(this);
    this->f = f;
}

Connexion::~Connexion()
{
    delete ui;
}

void Connexion::on_connectButton_clicked()
{

    User *u =new User;
    u->setName("toto");
    u->setPassword("tata");
    //file.read();
    if (ui->usernameLineEdit->text() == "") {
        QMessageBox::warning(
            this,
            tr("Connexion"),
            tr("Username empty") );
    }
    else if (ui->passwordLineEdit->text() == "") {
        QMessageBox::warning(
            this,
            tr("Connexion"),
            tr("Password empty") );
    }
    else if (this->f->getPasswordWithName(ui->usernameLineEdit->text()) == QString::fromUtf8(QCryptographicHash::hash(ui->passwordLineEdit->text().toUtf8(), QCryptographicHash::Sha512))) {
        QMessageBox::information(
            this,
            tr("Connexion"),
            tr("Connected") );
        this->hide();
        Account *a = new Account(this->f);
        a->show();
    }
    else {

        QMessageBox::warning(
            this,
            tr("Connexion"),
            tr("User name or password incorrect") );
    }
}

