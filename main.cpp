#include <QApplication>
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
    if (file.isEmpty()) {
        account.show();
    }
    else {
        connxion.show();
    }
    return a.exec();
}
