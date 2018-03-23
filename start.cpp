#include <QCloseEvent>

#include "start.h"
#include "ui_start.h"
#include "newaccountdialog.h"
#include "logindialog.h"

start::start(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::start)
{
    ui->setupUi(this);

}

start::~start()
{

    delete ui;
}

void start::on_logButton_clicked()
{
    loginDialog login;
    login.setModal(true);
    login.exec();
    if (authenticateLogin==true)
    {
        close();
    }
}

void start::on_createButton_clicked()
{
    newAccountDialog newAccount;
    newAccount.setModal(true);
    newAccount.exec();

}

void start::loginIsTrue()
{
    if (authenticateLogin==true)
    {
        close();
    }
}
