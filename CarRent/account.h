#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>
#include <QDebug>

class account
{
    QString password;
    int key;
public:
    QString username;
    account();
    account(QString x, QString y, int z);
};

#endif // ACCOUNT_H
