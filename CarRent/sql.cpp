#include "sql.h"

/**
 * @brief intializes the carrent.db file with tables and default values
 */
void sql::createdbFile()
{
    QSqlQuery query;
    /*create a table 'accounts' in the database with column username(primary key), password and key and inserts default account info*/
    query.exec("CREATE TABLE IF NOT EXISTS accounts (username VARCHAR(10) NOT NULL PRIMARY KEY, password VARCHAR(20) NOT NULL, key INT)");
    query.exec("INSERT INTO accounts VALUES('useradmin', 'password', 0)");
}


/**
 * @brief connects to the database, returns true if connection is successful, else returns false
 * @return bool
 *
 * checks if the directory which stores the carrent.db file exists
 * if not, makes one and opens the database
 * if yes, just opens the database
 * if some error occurs, returns false, else returns true
 */
bool sql::connectionOpen()
{
    QDir dir("C:/Databases");     //directory for database

    /*if directory for the database does not exists*/
    if (!dir.exists()){
        /*create directory of the given path*/
        dir.mkpath("C:/Databases");

        /*add and open SQLite database through db in the given path*/
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Databases/carrent.db");
        db.open();
        createdbFile();
    }else{
        /*else just open SQLite database through db in the given path*/
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Databases/carrent.db");
        db.open();
    }

    if(db.isOpen()){
        return true;
    }else{
        return false;
    }
}


/**
 * @brief gives total number of accounts in the database
 * @return int count
 *
 * selects all the rows in the table accounts in the database
 * counts all of them and then returns the value
 */
int sql::getTotalAccounts()
{
    int count = 0;       //represents number of account
    QSqlQuery qry;
    /*select all the rows in the table, accounts*/
    if(qry.exec("SELECT * FROM accounts")){
        qDebug()<<"Total number of accounts received";
        /*count all the rows*/
        while(qry.next())
        {
            count++;
        }
        qDebug()<<count;
    }else{
        qDebug()<<"Error: Total number of accounts could not ber received";
    }
    return count;
}

