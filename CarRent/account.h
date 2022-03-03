#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>
#include <QDebug>

class account
{
private:
    QString password;   //password of the user
    int key;            //encryption and decryption key
public:
    QString username;   //username
    account();
    account(QString x, QString y, int z);
    QString encrypt(QString password, int key);
    QString decrypt(QString encryptedPassword, int key);
    void setPassword(QString password);
    QString getPassword();
    int getKey();
};

#endif // ACCOUNT_H
