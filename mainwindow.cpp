#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connexion.h"
#include "manageaccount.h"
#include "manageprofils.h"

MainWindow::MainWindow(File *f, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setWindowTitle("Database interface");
    ui->setupUi(this);

    this->f = f;

}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::getNameUser() {
    return this->u.getName();
}

void MainWindow::on_actionCreate_account_triggered()
{
    ManageAccount *ma = new ManageAccount(this);
    ma->show();
    this->hide();
}

File * MainWindow::getFile() {
    return this->f;
}

void MainWindow::setUser(User u) {
    this->u = u;
}

void MainWindow::on_actionSign_out_triggered()
{
    this->u.clear();
    Connexion* c = new Connexion(this);
    c->show();
    this->hide();
}

void MainWindow::showEvent( QShowEvent* event ) {
    QWidget::showEvent( event );
    // show or hide admin options
    this->u = *this->f->getUserWithName(this->u.getName());
    ui->comboBox->clear();
    for (int i = 0 ; i < this->u.getProfils().size() ; i++) {
        ui->comboBox->addItem(this->u.getProfils()[i].getName());
    }

    if (u.getAdmin()) {
        ui->actionCreate_account->setVisible(true);
        ui->actionProfils->setVisible(true);
    }
    else {
        ui->actionCreate_account->setVisible(false);
        ui->actionProfils->setVisible(false);
    }
}

void MainWindow::on_actionProfils_triggered()
{
    ManageProfils *mp = new ManageProfils(this);
    mp->show();
    this->hide();
}

