#include "account.h"
#include "ui_account.h"
#include "connexion.h"
#include "user.h"
#include "file.h"
#include <QMessageBox>
#include <QCryptographicHash>

Account::Account(MainWindow *w, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Account)
{
    ui->setupUi(this);
    this->w = w;
    if (w->getFile()->isEmpty()){
        ui->adminCheckBox->setChecked(true);
        ui->adminCheckBox->setDisabled(true);
    }
}

Account::~Account()
{
    delete ui;
}

void Account::on_signInButton_clicked()
{
    this->w->show();
    this->close();
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
    else if (ui->passwordEdit->text() == ui->passwordConfirmEdit->text()) {
        QMessageBox::information(
            this,
            tr("Account"),
            tr("Account create") );
        User u;
        u.setName(ui->userEdit->text());
        u.setPassword(QString::fromUtf8(QCryptographicHash::hash(ui->passwordEdit->text().toUtf8(), QCryptographicHash::Sha512)));
        u.setAdmin(ui->adminCheckBox->isChecked());
        this->hide();
        this->w->getFile()->addUser(u);
        this->w->getFile()->write();
        this->w->show();
    }
    else {
        QMessageBox::warning(
            this,
            tr("Connexion"),
            tr("Username or password invalid") );
    }
}

