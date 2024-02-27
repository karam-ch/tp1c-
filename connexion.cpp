#include "connexion.h"
#include "ui_connexion.h"
#include "file.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QCryptographicHash>



Connexion::Connexion(MainWindow *w, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Connexion)
{
    ui->setupUi(this);
    this->w = w;
}

Connexion::~Connexion()
{
    delete ui;
}
// This slot function is triggered when the "Connect" button is clicked in the Connexion dialog.
// It performs validation checks on the entered username and password, compares the hashed password
// with the stored hashed password for the corresponding user, and handles the login process.
void Connexion::on_connectButton_clicked()
{
    // Check if the entered username is empty and display a warning if true.
    if (ui->usernameLineEdit->text() == "") {
        QMessageBox::warning(
            this,
            tr("Connexion"),
            tr("Username empty") );
    }
    // Check if the entered password is empty and display a warning if true.
    else if (ui->passwordLineEdit->text() == "") {
        QMessageBox::warning(
            this,
            tr("Connexion"),
            tr("Password empty") );
    }
    else {
        // Retrieve the user object associated with the entered username from the file in the main window.
        User * u = w->getFile()->getUserWithName(ui->usernameLineEdit->text());

        // Compare the entered hashed password with the stored hashed password for the user.
        if (u->getPassword() == QString::fromUtf8(QCryptographicHash::hash(ui->passwordLineEdit->text().toUtf8(), QCryptographicHash::Sha512))) {
            // Display an information message about the successful connection.
            QMessageBox::information(
                this,
                tr("Connexion"),
                tr("Connected") );

            // Set the current user in the main window to the authenticated user.
            w->setUser(*u);

            // Show the main window and hide the current Connexion dialog.
            w->show();
            this->hide();
        }
        // Display a warning if the entered username or password is incorrect.
        else {
            QMessageBox::warning(
                this,
                tr("Connexion"),
                tr("Username or password incorrect") );
        }
    }
}

