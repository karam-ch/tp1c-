#include "manageaccount.h"
#include "ui_manageaccount.h"
#include "account.h"
#include <QMessageBox>


ManageAccount::ManageAccount(MainWindow *w, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ManageAccount)
{
    ui->setupUi(this);
    this->w = w;
    ui->checkBox->setChecked(this->w->getFile()->getUserWithName(ui->accountCombo->currentText())->getAdmin());
}

ManageAccount::~ManageAccount()
{
    delete ui;
}

void ManageAccount::on_pushButton_clicked()
{
    w->getFile()->write();
    w->show();
    this->close();
}

void ManageAccount::on_createAccountButton_clicked()
{
    Account *a = new Account(this);
    a->show();
    this->hide();
}

void ManageAccount::showEvent( QShowEvent* event ) {
    QWidget::showEvent( event );

    ui->checkBox->setChecked(this->w->getFile()->getUserWithName(ui->accountCombo->currentText())->getAdmin());
    /** Avoid remove last admin **/
    if (this->w->getFile()->numberAdmin() <= 1 && this->w->getFile()->getUserWithName(ui->accountCombo->currentText())->getAdmin() == 1) {
        ui->checkBox->setDisabled(true);
    }
    else {
        ui->checkBox->setDisabled(false);
    }

    /** Update interface **/
    ui->accountCombo->clear();
    for (unsigned int i = 0; i < this->w->getFile()->getNumberUser(); i++) {
        ui->accountCombo->addItem(this->w->getFile()->getUsersWithIndex(i).getName());
    }
    ui->availableList->clear();
    for (unsigned int i = 0; i < this->w->getFile()->getNumberProfil(); i++) {
        ui->availableList->addItem(this->w->getFile()->getProfilsWithIndex(i).getName());
    }
    ui->userList->clear();
    for (unsigned int i = 0; i < this->w->getFile()->getUserWithName(ui->accountCombo->currentText())->getProfils().size() ; i++) {
        ui->userList->addItem(this->w->getFile()->getUserWithName(ui->accountCombo->currentText())->getProfils()[i].getName());
    }
}

File * ManageAccount::getFile() {
    return this->w->getFile();
}

void ManageAccount::on_RemoveButton_clicked()
{
    if ( ui->availableList->currentRow() == -1 ) {
        QMessageBox::warning(
            this,
            tr("Manage account"),
            tr("No profil selected"));
    }
    else {
        if (this->w->getNameUser() == ui->accountCombo->currentText()) {
            QMessageBox::warning(
                this,
                tr("Manage account"),
                tr("can't remove account it's you"));
        }
        else if (this->w->getFile()->numberAdmin() <= 1 && this->w->getFile()->getUserWithName(ui->accountCombo->currentText())->getAdmin() == 1) {
            QMessageBox::warning(
                this,
                tr("Manage account"),
                tr("can't remove account no admin"));
        }
        else {
            this->w->getFile()->removeUser(ui->accountCombo->currentText());
        }

        /** **/
        ui->checkBox->setChecked(this->w->getFile()->getUserWithName(ui->accountCombo->currentText())->getAdmin());
        if (this->w->getFile()->numberAdmin() <= 1 && this->w->getFile()->getUserWithName(ui->accountCombo->currentText())->getAdmin() == 1) {
            ui->checkBox->setDisabled(true);
        }
        else {
            ui->checkBox->setDisabled(false);
        }

        ui->accountCombo->clear();
        for (unsigned int i = 0; i < this->w->getFile()->getNumberUser(); i++) {
            ui->accountCombo->addItem(this->w->getFile()->getUsersWithIndex(i).getName());
        }

        ui->availableList->clear();
        for (unsigned int i = 0; i < this->w->getFile()->getNumberProfil(); i++) {
            ui->availableList->addItem(this->w->getFile()->getProfilsWithIndex(i).getName());
        }

        ui->userList->clear();
        for (unsigned int i = 0; i < this->w->getFile()->getUserWithName(ui->accountCombo->currentText())->getProfils().size() ; i++) {
            ui->userList->addItem(this->w->getFile()->getUserWithName(ui->accountCombo->currentText())->getProfils()[i].getName());
        }
    }
}


void ManageAccount::on_accountCombo_currentIndexChanged(int index) {

    ui->checkBox->setChecked(this->w->getFile()->getUserWithName(ui->accountCombo->currentText())->getAdmin());
    if (this->w->getFile()->numberAdmin() <= 1 && this->w->getFile()->getUserWithName(ui->accountCombo->currentText())->getAdmin() == 1) {
        ui->checkBox->setDisabled(true);
    }
    else {
        ui->checkBox->setDisabled(false);
    }

    ui->userList->clear();
    for (unsigned int i = 0; i < this->w->getFile()->getUserWithName(ui->accountCombo->currentText())->getProfils().size() ; i++) {
        ui->userList->addItem(this->w->getFile()->getUserWithName(ui->accountCombo->currentText())->getProfils()[i].getName());
    }
}


void ManageAccount::on_toUserButton_clicked()
{
    if ( ui->availableList->currentRow() == -1 ) {
        QMessageBox::warning(
            this,
            tr("Manage account"),
            tr("No profil selected"));
    }
    else {
        Profil p = this->w->getFile()->getProfil(ui->availableList->currentItem()->text());
        if (this->w->getFile()->getUserWithName(ui->accountCombo->currentText())->profilExist(ui->availableList->currentItem()->text())) {
            QMessageBox::warning(
                this,
                tr("Manage account"),
                tr("Profil already in account"));
        }
        else {
            this->w->getFile()->getUserWithName(ui->accountCombo->currentText())->addProfils(p);
            ui->userList->clear();
            for (unsigned int i = 0; i < this->w->getFile()->getUserWithName(ui->accountCombo->currentText())->getProfils().size() ; i++) {
                ui->userList->addItem(this->w->getFile()->getUserWithName(ui->accountCombo->currentText())->getProfils()[i].getName());
            }
        }
    }
}


void ManageAccount::on_checkBox_stateChanged(int arg1) {
    this->w->getFile()->getUserWithName(ui->accountCombo->currentText())->setAdmin(ui->checkBox->isChecked());
}

/** Only remove profil of a user and update interface **/
void ManageAccount::on_toProfilsButton_clicked()
{
    this->w->getFile()->getUserWithName(ui->accountCombo->currentText())->removeProfil(ui->userList->currentItem()->text());
    ui->userList->clear();
    for (unsigned int i = 0; i < this->w->getFile()->getUserWithName(ui->accountCombo->currentText())->getProfils().size() ; i++) {
        ui->userList->addItem(this->w->getFile()->getUserWithName(ui->accountCombo->currentText())->getProfils()[i].getName());
    }
}

