#ifndef MANAGEACCOUNT_H
#define MANAGEACCOUNT_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class ManageAccount;
}

class ManageAccount : public QDialog
{
    Q_OBJECT

public:
    explicit ManageAccount(MainWindow *w, QWidget *parent = nullptr);
    ~ManageAccount();

    File *getFile();

    void showEvent(QShowEvent* event);

private slots:
    void on_pushButton_clicked();

    // void on_pushButton_2_clicked();

    void on_createAccountButton_clicked();

    void on_RemoveButton_clicked();

    void on_accountCombo_currentIndexChanged(int index);

    void on_toUserButton_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_toProfilsButton_clicked();


private:
    Ui::ManageAccount *ui;
    MainWindow *w;
    void setAccount();
    // void ;

};

#endif // MANAGEACCOUNT_H
