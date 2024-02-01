#include "account.h"
#include "ui_account.h"
#include "connexion.h"
#include <QMessageBox>

Account::Account(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Account)
{
    ui->setupUi(this);
}

Account::~Account()
{
    delete ui;
}



void Account::on_signInButton_clicked()
{
    this->hide();
    Connexion *c = new Connexion;
    c->show();
}


void Account::on_createButton_clicked()
{
    if (ui->userEdit->text() == "") {
        QMessageBox::warning(
            this,
            tr("Account"),
            tr("Username empty") );
    }
    else if (ui->passwordEdit->text() == "") {
        QMessageBox::warning(
            this,
            tr("Account"),
            tr("Password empty") );
    }

    else if (ui->passwordEdit->text() == ui->passwordEditconfirm->text()) {
        QMessageBox::information(
            this,
            tr("Account"),
            tr("Account create") );

    }
    else {
        QMessageBox::warning(
            this,
            tr("Connexion"),
            tr("Username or password invalid") );
    }
}

