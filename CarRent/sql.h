#ifndef SQL_H
#define SQL_H

#include <QtSql>
#include <QtDebug>
#include <QFileInfo>

class sql
{
public:
    sql();
    QSqlDatabase db;
    void createdbFile();

};

#endif // SQL_H
