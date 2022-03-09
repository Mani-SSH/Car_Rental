#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>
#include <QDebug>
#include <QRandomGenerator>

class account
{
private:
    QString password;
    int key;
public:
    QString username;
    QString f_name;
    QString l_name;
    account();
    account(QString x, QString y, int z);
    QString encrypt(QString password, int key);
    QString decrypt(QString encryptedPassword, int key);
    void setPassword(QString password);
    QString getPassword();
    int getKey();
    void keyGenerator();
};

#endif // ACCOUNT_H
