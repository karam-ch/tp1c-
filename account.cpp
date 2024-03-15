#include "account.h"
#include "ui_account.h"
// #include "connexion.h"
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
    this->ma = nullptr;
    this->f = w->getFile();
    // if first connexion
    if (w->getFile()->isEmpty()){
        ui->adminCheckBox->setChecked(true);
        ui->adminCheckBox->setDisabled(true);
        QMessageBox::warning(
            this,
            tr("Account"),
            tr("JSON File not found, Please create your first admin account") );
    }
}

Account::Account(ManageAccount *ma, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Account)
{
    ui->setupUi(this);
    this->ma = ma;
    this->f = ma->getFile();
    this->w = nullptr;
}

Account::~Account()
{
    delete ui;
}

void Account::on_signInButton_clicked()
{
    if (this->w == nullptr) {
        this->ma->show();
    }
    else {
        this->w->show();
    }
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
    else if (ui->passwordEdit->text() != ui->passwordConfirmEdit->text()) {
        QMessageBox::warning(
            this,
            tr("Account"),
            tr("comfirm password incorrect") );
    }
    else if (!f->userExist(ui->userEdit->text())) {
        QMessageBox::information(
            this,
            tr("Account"),
            tr("Account create") );
        User u;
        u.setName(ui->userEdit->text());
        u.setPassword(QString::fromUtf8(QCryptographicHash::hash(ui->passwordEdit->text().toUtf8(), QCryptographicHash::Sha512)));
        u.setAdmin(ui->adminCheckBox->isChecked());

        if (f->isEmpty()) {
            this->w->setUser(u);
        }
        f->addUser(u);
        if (f->write() == 1) {
            QMessageBox::warning(
                this,
                tr("Account"),
                tr("Can't write data in file") );
        }
        if (this->w == nullptr) {

            this->ma->show();
        }
        else {
            this->w->show();
        }
        this->close();
    }
    else {
        QMessageBox::warning(
            this,
            tr("Account"),
            tr("Username already exist") );
    }
}

