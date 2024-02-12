#include "connexion.h"
#include "ui_connexion.h"
#include "file.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QCryptographicHash>



Connexion::Connexion(MainWindow *w, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Connexion)
{
    ui->setupUi(this);
    this->w = w;
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
        User u = w->getFile()->getUserWithName(ui->usernameLineEdit->text());
        if (u.getPassword() == QString::fromUtf8(QCryptographicHash::hash(ui->passwordLineEdit->text().toUtf8(), QCryptographicHash::Sha512))) {
            QMessageBox::information(
                this,
                tr("Connexion"),
                tr("Connected") );
            w->setUser(u);
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

