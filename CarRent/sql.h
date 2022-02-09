#ifndef SQL_H
#define SQL_H

#include <QtSql>
#include <QFileInfo>
#include <QDir>
#include <QDebug>

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
};

#endif // SQL_H
