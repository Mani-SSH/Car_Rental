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
    bool usernameExists(QString x);
    void importEncryptedPassword(QString x, QString &y, int &z);
    int importKey();
};

#endif // SQL_H
