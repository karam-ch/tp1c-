#include "connexion.h"
#include "ui_connexion.h"
// #include "account.h"
#include "file.h"
#include "mainwindow.h"
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
    else {
        User u = this->f->getUserWithName(ui->usernameLineEdit->text());
        if (u.getPassword() == QString::fromUtf8(QCryptographicHash::hash(ui->passwordLineEdit->text().toUtf8(), QCryptographicHash::Sha512))) {
            QMessageBox::information(
                this,
                tr("Connexion"),
                tr("Connected") );
            MainWindow* w = new MainWindow(u);
            w->show();
            this->hide();
        }
        else {

            QMessageBox::warning(
                this,
                tr("Connexion"),
                tr("User name or password incorrect") );
        }
    }

}

