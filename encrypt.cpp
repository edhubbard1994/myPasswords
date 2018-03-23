#include "encrypt.h"
#include <string>
#include <QDebug>


encrypt::encrypt(QString toCode, int pathDecide)
{
    if (pathDecide==0)
    {
        codeString(toCode);
    }
    else if (pathDecide==1)
    {
        decodeString(toCode);
    }
}
void encrypt::decodeString(QString toDecode)
{
    stdString=toDecode.toStdString();
    qDebug()<<toDecode;
    stringParse();

}

void encrypt::stringParse()
{
    std::string getNum;

    for(int i=0;i<(stdString.size());i++)
    {
       if (stdString[i]!=',')
       {
           getNum+=stdString[i];
       }
       else if(stdString[i]==',')
       {
           QString forNum;
           forNum=forNum.fromStdString(getNum);
           int convert = forNum.toInt();
           castedData.push_back(convert);
           getNum="";
       }


    qDebug()<<i<<"     "<<stdString[i]<<"    " <<castedData.size();

    }
    qDebug()<<castedData.size();
}
QString encrypt::testDecode()
{
    QString arrayChar;
    for (int i=0;i<castedData.size();i++)
    {
        arrayChar+=(char)castedData[i];
    }
    castedData.clear();
    bitOperate(arrayChar.toStdString());
    QString decoded;
    for (int j =0;j<castedData.size();j++)
    {
        decoded+=(char)castedData[j];
    }
    return decoded;
}

void encrypt::codeString(QString theString)
{
   stdString=theString.toStdString();
   bitOperate(stdString);
   stdString=convertToString();
   codedResult=result(stdString);
}


void encrypt::bitOperate(std::string toEncrypt )
{
    char key[] = {'y','o','u','r','k','e','y','h','e','r','e'};
    std::string output = toEncrypt;
    for (int i =0;i<toEncrypt.size();i++)
    {
        output[i]=toEncrypt[i] ^ key[i%(sizeof(key)/sizeof(char))];
        castedData.push_back((int)toEncrypt[i]);
    }
}

QString encrypt::result(std::string conversion)
{
   QString out=out.fromStdString(conversion);
   return out;
}

std::string encrypt::convertToString()
{
    std::string product;
    for (int i=0;i<castedData.size();i++)
    {
        if(i<(castedData.size()-1))
        {
            product+=((std::to_string(castedData[i]))+',');
        }
        else
        {
            product+=((std::to_string(castedData[i]))+',');
        }
    }
    return product;
}
