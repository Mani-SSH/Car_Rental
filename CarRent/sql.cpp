#include "sql.h"
#include <QDir>

sql::sql()
{
    QDir dir("C:/Databases");     //directory for database

    /*if directory for the database does not exists*/
    if (!dir.exists()){
        /*create directory of the given path*/
        dir.mkpath("C:/Databases");

        /*add and open SQLite database through db in the given path*/
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Databases/carrent.db");
        createdbFile();
    }else{
        /*else just open SQLite database through db in the given path*/
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Databases/carrent.db");
    }
}

/*initializes database*/
void sql::createdbFile()
{
    QSqlQuery query;
    /*create a table 'accounts' in the database with column username(primary key), password and key and inserts default account info*/
    query.exec("CREATE TABLE IF NOT EXISTS accounts (username VARCHAR(20) PRIMARY KEY, password VARCHAR(20), key INT)");
    query.exec("INSERT INTO accounts VALUES('useradmin', 'password', 0)");
}
