#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "user.h"
#include "file.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(File *f, QWidget *parent = nullptr);
    ~MainWindow();
    File *getFile();
    void setUser(User u);
    void showEvent(QShowEvent* event);
    QString getNameUser();

private slots:
    void on_actionCreate_account_triggered();

    void on_actionSign_out_triggered();

    void on_actionProfils_triggered();

private:
    Ui::MainWindow *ui;
    User u;
    File *f;
};
#endif // MAINWINDOW_H
