#ifndef ENCRYPT_H
#define ENCRYPT_H

#include <QObject>


class encrypt
{
public:

    encrypt(QString,int);

    void codeString(QString);

    QString codedResult;
    QString testDecode();
private:

    QString result(std::string );

    void bitOperate(std::string);
    void decodeString(QString);
    void stringParse();

    std::string decodeString();
    std::string convertToString();

    std::string stdString;

    std::vector<int>castedData;
    //std::vector<int>uncastedData;

};

#endif // ENCRYPT_H
