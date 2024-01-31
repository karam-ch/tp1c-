#include "connexion.h"
#include "ui_connexion.h"
#include "account.h"
#include "file.h"
#include <iostream>
#include <QMessageBox>

Connexion::Connexion(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Connexion)
{
    ui->setupUi(this);
}

Connexion::~Connexion()
{
    delete ui;
}

void Connexion::on_connectButton_clicked()
{
    file file;
    User *u =new User;
    u->setName("toto");
    u->setPassword("tata");
    file.addUser(*u);


    if (file.getPasswordWithName(ui->usernameLineEdit->text()) == ui->passwordLineEdit->text()) {
        QMessageBox::information(
            this,
            tr("Connexion"),
            tr("connected") );
        this->hide();
        Account *a = new Account;
        a->show();
    }
    else
    {
        QMessageBox::warning(
            this,
            tr("Connexion"),
            tr("Password or username invalid"));
    }




}

