#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>
#include <QDebug>

class account
{
    QString password;
public:
    QString username;
    account();
    account(QString x, QString y);
};

#endif // ACCOUNT_H
