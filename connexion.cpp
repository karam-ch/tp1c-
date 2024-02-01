#include "connexion.h"
#include "ui_connexion.h"
#include "account.h"
#include "file.h"
// #include <iostream>
#include <QMessageBox>


Connexion::Connexion(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Connexion)
{
    ui->setupUi(this);
}

Connexion::Connexion(file *f){
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
    else if (f->getPasswordWithName(ui->usernameLineEdit->text()) == ui->passwordLineEdit->text()) {
        QMessageBox::information(
            this,
            tr("Connexion"),
            tr("Connected") );
            this->hide();
        Account *a = new Account;
        a->show();
    }
    else {

        QMessageBox::warning(
            this,
            tr("Connexion"),
            tr(f->getPasswordWithName(ui->usernameLineEdit->text()).toStdString().c_str()) );
    }
}

