#include "createaccount.h"
#include "newaccountdialog.h"
#include "encrypt.h"
#include <QFile>
#include <QDir>
#include <QMessageBox>
#include <QTextStream>

createAccount::createAccount( QString c_ID,QString c_pass,QString c_ansOne,QString c_ansTwo,int c_indexOne,int c_indexTwo)
{
userId=c_ID;
password=c_pass;
ansOne=c_ansOne;
ansTwo=c_ansTwo;
indexOne=c_indexOne;
indexTwo=c_indexTwo;
createUserID();
}

void createAccount::createUserID()
{
    checkAccountsDir();
    if (checkAccountsDir()==false)
    {
        createFirstTimePath();
    }
}

bool createAccount::checkNameAvailability(QString userIDPath)
{
    QDir newAccount;
    newAccount.setPath(userIDPath +"/"+ userId);
    bool checkAccount = newAccount.exists();
    if(checkAccount==true||userId=="TEST")
    {
        QMessageBox takenUserIDError;
        takenUserIDError.setText("Error User Id Taken");
        takenUserIDError.setWindowFlags(Qt::WindowStaysOnTopHint);
        takenUserIDError.exec();
    }
    return newAccount.exists();
}

void createAccount::createFirstTimePath()
{
    QDir createPath;
    path = "/yourDesiredPath";
    createPath.setPath(path);
    createPath.mkdir("user_Accounts");
    path+="/user_Accounts";
    createPath.setPath(path);
    checkNameAvailability(path);
    if (checkNameAvailability(path)==false)
    {
        createAccountPath();
    }
}

void createAccount::createAccountPath()
{
    QDir createPath;
    createPath.setPath(path);
    createPath.mkdir(userId);
    QString newPath=path+userId;
    createPath.setPath(newPath);
    createAccountDirectory();
}

bool createAccount::checkAccountsDir()
{
    QDir accountsDirectory;
    return accountsDirectory.exists("user_Accounts");
}

void createAccount::createAccountDirectory()
{
    QDir forAccount;
    forAccount.setPath(path);
    forAccount.mkdir(userId);
    forAccount.setPath(path+"/"+ userId);
    createAccountFiles();
}

void createAccount::createAccountFiles()
{
    QDir dir;
    dir.setPath(path+"/"+userId);
    QFile info(path+"/"+userId+"/"+"password.txt");
    if(info.open(QIODevice::ReadWrite)== true)
    {
        QTextStream streamTo(&info);
        QString numConvert;
        streamTo<< encode(password)<<endl<< encode(numConvert.number(indexOne))<<endl<<encode(ansOne)<<endl<<encode(numConvert.number(indexTwo))<<endl<<encode(ansTwo);
        info.close();
    }
    else
    {
        QMessageBox noFile;
        noFile.setWindowFlags(Qt::WindowStaysOnTopHint);
        noFile.setText("error file not created");
        noFile.exec();
    }
}

QString createAccount::encode(QString toEncode)
{
    encrypt code(toEncode,0);
    QString result = code.codedResult;
    return result;

}
