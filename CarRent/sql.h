#ifndef SQL_H
#define SQL_H

#include <QtSql>
#include <QtDebug>
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
    int getTotalAccounts();
};

#endif // SQL_H
