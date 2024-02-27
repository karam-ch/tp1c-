#ifndef CREATEPROFIL_H
#define CREATEPROFIL_H

#include <QDialog>
#include "manageprofils.h"

namespace Ui {
class CreateProfil;
}

class CreateProfil : public QDialog
{
    Q_OBJECT

public:
    explicit CreateProfil(ManageProfils *mp, QWidget *parent = nullptr);
    ~CreateProfil();

private slots:
    void on_createButton_clicked();

private:
    Ui::CreateProfil *ui;
    ManageProfils *mp;
};

#endif // CREATEPROFIL_H
