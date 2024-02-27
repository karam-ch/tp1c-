#include "manageprofils.h"
#include "ui_manageprofils.h"
#include "createprofil.h"
#include <QMessageBox>

ManageProfils::ManageProfils(MainWindow *w, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ManageProfils)
{
    this->w = w;
    ui->setupUi(this);

}

ManageProfils::~ManageProfils()
{
    delete ui;
}



void ManageProfils::showEvent( QShowEvent* event ) {
    QWidget::showEvent( event );
    ui->profilBox->clear();
    for (unsigned int i = 0; i < this->w->getFile()->getNumberProfil(); i++) {
        ui->profilBox->addItem(this->w->getFile()->getProfilsWithIndex(i).getName());
    }
}


void ManageProfils::on_createProfilButton_clicked()
{
    CreateProfil *cp = new CreateProfil(this);
    cp->show();
    this->hide();
}

MainWindow* ManageProfils::getMainWindow()
{
    return this->w;
}

void ManageProfils::on_returnButton_clicked()
{
    this->w->getFile()->write();
    this->w->show();
    this->hide();


}


void ManageProfils::on_removeButton_clicked() {

    if (this->getMainWindow()->getFile()->removeProfil(ui->profilBox->currentText())) {
        QMessageBox::warning(
            this,
            tr("Manage profil"),
            tr("can't remove profil a least one account use it"));
    }
    // this->getMainWindow()->getFile()->removeProfil(ui->profilBox->currentText());
    ui->profilBox->clear();
    for (unsigned int i = 0; i < this->w->getFile()->getNumberProfil(); i++) {
        ui->profilBox->addItem(this->w->getFile()->getProfilsWithIndex(i).getName());
    }
}



