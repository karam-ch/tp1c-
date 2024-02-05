#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "user.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(User u, QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    User u;
};
#endif // MAINWINDOW_H
