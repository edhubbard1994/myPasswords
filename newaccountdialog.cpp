#include "newaccountdialog.h"
#include "ui_newaccountdialog.h"
#include "createaccount.h"
#include <QFile>
#include <QDebug>
#include <QMessageBox>




newAccountDialog::newAccountDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newAccountDialog)
{
    ui->setupUi(this);

}

newAccountDialog::~newAccountDialog()
{
    delete ui;
}

void newAccountDialog::on_passwordVerify_textChanged(const QString &arg1)
{
    if (arg1==getPassword)
    {
        ui->passwordVerifyLabel->setText("Verified");
        passConfirm=true;
    }
    else
    {
        ui->passwordVerifyLabel->setText("");
        passConfirm=false;
    }
}

void newAccountDialog::on_userID_textChanged(const QString &arg1)
{
     getUserID=arg1;


}

void newAccountDialog::on_password_textChanged(const QString &arg1)
{
     getPassword=arg1;


}

void newAccountDialog::on_cancelButton_clicked()
{
    close();
}

void newAccountDialog::unlockCreateBtn(bool userID, bool password)
{
    if(userID==true && password==true)
    {
        ui->createButton->setEnabled(true);
    }
}

void newAccountDialog::on_createButton_clicked()
{
    ui->comboBox->hide();
    ui->comboBox_2->hide();
    getCurrentIndexOne=ui->comboBox->currentIndex();
    getCurrentIndexTwo=ui->comboBox_2->currentIndex();

    createAccount createNew(getUserID,getPassword,ui->securityAnsOne->text(),ui->securityAnsTwo->text(),ui->comboBox->currentIndex(),ui->comboBox_2->currentIndex());
    close();
}

void newAccountDialog::on_verifyCheckBox_clicked()
{  if (checkPasswordSecure(getPassword)==true)
    {
         unlockCreateBtn(userConfirm,passConfirm);
    }


    ui->verifyCheckBox->setChecked(false);
}

void newAccountDialog::on_userIDVerify_textChanged(const QString &arg1)
{
    if (arg1==getUserID)
    {

        userConfirm=true;
    }
    else
    {

        userConfirm=false;
    }
}

bool newAccountDialog::checkPasswordSecure(QString thePassowrd)
{
    if (thePassowrd.length()<9||specialCharCheck(thePassowrd)==false)
    {
        QMessageBox invalidPassword;
        invalidPassword.setText("Password must be at least 9 characters long and contain at least 1 special character");
        invalidPassword.setWindowFlags(Qt::WindowStaysOnTopHint);
        invalidPassword.exec();
        return false;
    }
    else
    {
        return true;
    }
}

bool newAccountDialog::specialCharCheck(QString passwordCheck)
{
    QChar specCharArray[]={'!','@','#','$','%','^','&','*','(',')','-','_','+','=','[',']','{','}',';','<','>',',','.','/','?'};
    for (int i=0;i<passwordCheck.length();i++)
    {
        for(int j=0;j<26;j++)
        {
            if(passwordCheck[i]==specCharArray[j])
            {
                return true;
            }
        }
    }
    return false;
}

