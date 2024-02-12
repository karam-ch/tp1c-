#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "account.h"

MainWindow::MainWindow(File *f, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // this->u = u;
    this->f = f;
    if (u.getAdmin()) {
        ui->actionCreate_account->setVisible(true);
    }
    else {
        ui->actionCreate_account->setVisible(false);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionCreate_account_triggered()
{
    this->hide();
    Account *a = new Account(this);
    a->show();
}

File * MainWindow::getFile() {
    return this->f;
}

void MainWindow::setUser(User u) {
    this->u = u;
}
