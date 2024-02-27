#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QDialog>
#include "mainwindow.h"
#include "manageaccount.h"

namespace Ui {
class Account;
}

class Account : public QDialog
{
    Q_OBJECT

public:
    explicit Account(MainWindow *w,QWidget *parent = nullptr);
    explicit Account(ManageAccount *ma,QWidget *parent = nullptr);
    ~Account();

private slots:

    void on_signInButton_clicked();

    void on_createButton_clicked();

private:
    Ui::Account *ui;
    MainWindow *w;
    ManageAccount *ma;
    File *f;
};

#endif // ACCOUNT_H
