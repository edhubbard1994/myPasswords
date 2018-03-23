#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QDir>

namespace Ui {
class loginDialog;
}

class loginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit loginDialog(QWidget *parent = 0);
    ~loginDialog();

private slots:
    void on_cancelButton_clicked();

    void on_userIDEdit_textChanged(const QString &arg1);

    void on_loginButton_clicked();

    void on_passwordEdit_textChanged(const QString &arg1);

private:
    Ui::loginDialog *ui;

    void checkUserID(QDir);
    void openAccountFile(QDir);
    void authenticatePassword(QString);

    QString enteredID;
    QString getPassword;
    QString enteredPassword;
    QString path = "your_path/user_Accounts";


};
extern bool authenticateLogin;
extern QString loggedInUser;
#endif // LOGINDIALOG_H
