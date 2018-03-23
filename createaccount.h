#ifndef CREATEACCOUNT_H
#define CREATEACCOUNT_H

#include <QObject>
#include <QFile>
#include <QDir>

#include "newaccountdialog.h"


class createAccount
{
public:
    createAccount(QString,QString,QString,QString,int,int);

     bool checkNameAvailability(QString userIDPath);
private:
    void createUserID();
    void createPassword(QString);
    void createFirstTimePath();
    void createAccountPath();
    void createAccountDirectory();
    void createAccountFiles();

    QString encode(QString);

    bool checkAccountsDir();

    QString userId;
    QString password;
    QString ansOne;
    QString ansTwo;
    QString path;

    int indexOne;
    int indexTwo;

};

#endif // CREATEACCOUNT_H
