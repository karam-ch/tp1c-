#include "createprofil.h"
#include "ui_createprofil.h"
#include "profil.h"
#include <QMessageBox>

CreateProfil::CreateProfil(ManageProfils *mp, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreateProfil)
{
    this->mp = mp;
    ui->setupUi(this);
}

CreateProfil::~CreateProfil()
{
    delete ui;
}

void CreateProfil::on_createButton_clicked()
{
    Profil p;
    p.setName(ui->nameEdit->text());
    p.setDb(ui->dbSpinBox->value());
    mp->getMainWindow()->getFile()->addProfils(p);

    if (mp->getMainWindow()->getFile()->write() == 1) {
        QMessageBox::warning(
            this,
            tr("Account"),
            tr("Can't write data in file") );
    }
    mp->show();
    this->close();
}

