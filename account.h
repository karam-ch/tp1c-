#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QDialog>
#include "file.h"

namespace Ui {
class Account;
}

class Account : public QDialog
{
    Q_OBJECT

public:
    explicit Account(file *f,QWidget *parent = nullptr);
    ~Account();

private slots:


    void on_signInButton_clicked();

    void on_createButton_clicked();

private:
    Ui::Account *ui;
    file *f;
};

#endif // ACCOUNT_H
