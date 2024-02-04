#include <QApplication>
#include "mainwindow.h"
#include "connexion.h"
#include "file.h"
#include "account.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    file file;
    file.read();
    Account account(&file);
    Connexion connxion(&file);
    MainWindow w;
    if (file.isEmpty()) {
        account.show();
    }
    else {
        connxion.show();
    }
    // w.show();
    return a.exec();
}
