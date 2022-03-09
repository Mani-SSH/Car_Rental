#ifndef SQL_H
#define SQL_H

#include <QtSql>
#include <QFileInfo>
#include <QDir>
#include <QDebug>
#include "account.h"

class sql
{
public:
    QSqlDatabase db;
    void createdbFile();
    bool connectionOpen();
    void connectionClose();
    int importTotalAccounts();
    bool usernameExists(QString username);
    void importAccountDetails(QString username, QString &password, int &key);
    int importKey();
    void exportAccount(account dummy);
    void deleteDefault();
};

#endif // SQL_H
