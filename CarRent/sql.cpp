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
int sql::importTotalAccounts()
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
        qDebug()<<"Accounts found: "<<count;
    }else{
        qDebug()<<"Error: Total number of accounts could not ber received";
    }
    return count;
}


/**
 * @brief checks if username exits on the database
 * @param x
 * @return bool
 *
 * counts all the rows with username same as parameter, x
 * if count is equal to one, returns true
 * else, returns false
 */
bool sql::usernameExists(QString x)
{
    int count = 0;       //number of entries with username same as x

    /*select all rows with username same as x and count them*/
    QSqlQuery qry;
    qry.exec("SELECT * FROM accounts WHERE username='"+x+"'");
    while(qry.next())
    {
        count++;
    }

    /*if only one account with username same as x is found, return true ,else return false*/
    if (count == 1){
        qDebug()<<"Username"<<x<<"found.";
        return true;
    }else{
        qDebug()<<"Username"<<x<<"not found";
        return false;
    }
}


void sql::importEncryptedPassword(QString x, QString &y, int &z)
{
    QSqlQuery qry;
    qry.exec("SELECT * FROM accounts WHERE username='"+x+"'");
    while (qry.next())
    {
        y = qry.value(1).toString();
        z = qry.value(2).toInt();
        qDebug()<<"Encrypted password and key received...";
        qDebug()<<"Encrypted password:"<<y;
        qDebug()<<"Key:"<<z;
    }
}
