#include <QApplication>
#include "connexion.h"
#include "file.h"
#include "account.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    File* file = new File();
    file->read();
    MainWindow *m = new MainWindow(file);
    Connexion connxion(m);
    if (file->isEmpty()) {
        Account *account = new Account(m);
        account-> show();
    }
    else {
        connxion.show();
    }
    return a.exec();
}
