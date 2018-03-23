#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QDebug>
#include <QObject>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "start.h"
#include "logindialog.h"
#include "encrypt.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    populateComboBox();

};

MainWindow::~MainWindow()
{
    delete ui;
};


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    newAccount=arg1;
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    newPassword=arg1;
}

void MainWindow::on_pushButton_clicked()
{
    if(newAccount.size()>0&&newPassword.size()>0)
    {
        QFile content(path+"/"+loggedInUser+"/"+newAccount+".txt");
        if(content.open(QIODevice::ReadWrite)==false)
        {
            QMessageBox cannotOpen;;
            cannotOpen.setText("Error cannot access account files");
            cannotOpen.setWindowFlags(Qt::WindowStaysOnTopHint);
            cannotOpen.exec();
        }
        else
        {
            QTextStream stream(&content);
            stream<< encode(newPassword);
            content.close();
        }
    }
    resetWindow();
}
QString MainWindow::encode(QString toEncode)
{
    encrypt code(toEncode,0);
    QString result = code.codedResult;
    return result;

}

void MainWindow::populateComboBox()
{

    QString dirPath=path+"/"+loggedInUser+"/";
    qDebug() << dirPath <<endl;
    QDir fileList(dirPath);
    ui->AccountComboBox->addItems(fileList.entryList());
}

void MainWindow::resetWindow()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->AccountComboBox->clear();
    populateComboBox();
}

void MainWindow::on_AccountComboBox_activated(const QString &arg1)
{
    QFile getRequest(path+"/"+loggedInUser+"/"+arg1);
    if(getRequest.open(QIODevice::ReadOnly)==false)
    {
        QMessageBox cannotOpen;
        cannotOpen.setText("Error cannot access account files");
        cannotOpen.setWindowFlags(Qt::WindowStaysOnTopHint);
        cannotOpen.exec();
    }
    else
    {
        QTextStream stream(&getRequest);
        encrypt decode(stream.readLine(0),1);
        ui->displayLabel->setText(decode.testDecode());
    }
    getRequest.close();
}
