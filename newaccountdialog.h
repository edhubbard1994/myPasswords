#ifndef NEWACCOUNTDIALOG_H
#define NEWACCOUNTDIALOG_H

#include <QDialog>
#include <QApplication>


namespace Ui {
class newAccountDialog;
}

class newAccountDialog : public QDialog
{
    Q_OBJECT

public:


    explicit newAccountDialog(QWidget *parent = 0);
    ~newAccountDialog();




private slots:


    void on_passwordVerify_textChanged(const QString &arg1);

    void on_userID_textChanged(const QString &arg1);

    void on_password_textChanged(const QString &arg1);

    void on_cancelButton_clicked();

    void on_createButton_clicked();

    void on_verifyCheckBox_clicked();



    void on_userIDVerify_textChanged(const QString &arg1);

private:
    Ui::newAccountDialog *ui;

    QString getUserID;
    QString getPassword;
    QString answerOne;
    QString answerTwo;

    int getCurrentIndexOne;
    int getCurrentIndexTwo;

    bool userConfirm;
    bool passConfirm;
    bool questionsAnswered;
    bool specialCharCheck(QString);
    bool checkPasswordSecure(QString);

    void unlockCreateBtn(bool, bool);

};

#endif // NEWACCOUNTDIALOG_H
