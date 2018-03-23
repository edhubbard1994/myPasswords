#include "logindialog.h"
#include "ui_logindialog.h"
#include <QDir>
#include <QMessageBox>
#include <QTextStream>
#include "encrypt.h"
#include <QDebug>

loginDialog::loginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginDialog)
{
    ui->setupUi(this);
    ui->loginButton->hide();
}

loginDialog::~loginDialog()
{
    delete ui;

}

void loginDialog::on_cancelButton_clicked()
{
    close();
}

void loginDialog::on_userIDEdit_textChanged(const QString &arg1)
{
    enteredID=arg1;
}

void loginDialog::checkUserID( QDir forPath)
{
    if(forPath.exists()==false)
    {
        QMessageBox noUserIDError;
        noUserIDError.setText("Error User Account not found");
        noUserIDError.setWindowFlags(Qt::WindowStaysOnTopHint);
        noUserIDError.exec();
    }
    else
    {
        openAccountFile(forPath);
    }
}

void loginDialog::on_loginButton_clicked()
{
    QDir account;

    account.setPath(path+"/"+enteredID);
    checkUserID(account);

}

void loginDialog::openAccountFile(QDir forDir)
{
    forDir.setPath(path+"/"+enteredID);
    QFile forInfo(path+"/"+enteredID+"/"+"password.txt");
    if(forInfo.open(QIODevice::ReadOnly))
    {
        QTextStream getInfo(&forInfo);
        getPassword = getInfo.readLine(0);
        encrypt decode(getPassword,1);
        authenticatePassword(decode.testDecode());
    }
    else
    {
        QMessageBox cannotOpen;
        cannotOpen.setText("Error cannot access account files");
        cannotOpen.setWindowFlags(Qt::WindowStaysOnTopHint);
        cannotOpen.exec();
    }
    loggedInUser=enteredID;
    forInfo.close();
}

void loginDialog::on_passwordEdit_textChanged(const QString &arg1)
{
    enteredPassword=arg1;
    ui->loginButton->show();
}

void loginDialog::authenticatePassword(QString password)
{
    if(enteredPassword==password)
    {
        authenticateLogin=true;
        close();
    }else{
        QMessageBox denied;
        denied.setText("Password is incorrect");
        denied.setWindowFlags(Qt::WindowStaysOnTopHint);
        denied.exec();
    }
}


