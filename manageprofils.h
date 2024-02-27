#ifndef MANAGEPROFILS_H
#define MANAGEPROFILS_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class ManageProfils;
}

class ManageProfils : public QDialog
{
    Q_OBJECT

public:
    explicit ManageProfils(MainWindow *w, QWidget *parent = nullptr);

    MainWindow* getMainWindow();

    void showEvent(QShowEvent* event);

    ~ManageProfils();

private slots:

    void on_createProfilButton_clicked();


    void on_returnButton_clicked();

    void on_removeButton_clicked();

private:
    Ui::ManageProfils *ui;
    MainWindow *w;
};

#endif // MANAGEPROFILS_H
