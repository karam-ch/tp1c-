#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(User u, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->u = u;
    // if (u.getAdmin()) {
    //     ui->actionCreate_account->setVisible(true);
    // }
    // else {
    //     ui->actionCreate_account->setVisible(false);
    // }
}

MainWindow::~MainWindow()
{
    delete ui;
}
