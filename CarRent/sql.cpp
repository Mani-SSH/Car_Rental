#include "sql.h"

/**
 * @brief intializes the carrent.db file with tables and default values
 */
void sql::createdbFile()
{
    QSqlQuery query;
    /*create a table 'accounts' in the database with column username(primary key), password and key and inserts default account info*/

    query.exec("CREATE TABLE IF NOT EXISTS accounts (username VARCHAR(10) NOT NULL PRIMARY KEY, password VARCHAR(20) NOT NULL, first_name VARCHAR(10) NOT NULL, last_name VARCHAR(10) NOT NULL, key INT)");
    query.exec("INSERT INTO accounts VALUES('useradmin', 'password', 'default' , 'account' , 0)");
    query.exec("CREATE TABLE IF NOT EXISTS cars (PlateNumber VARCHAR(10) NOT NULL PRIMARY KEY, Brand VARCHAR(10) NOT NULL, Model VARCHAR(10) NOT NULL, Rate INT NOT NULL, isAvailable INT NOT NULL, DateRented TEXT, DateToReturn TEXT)");
    

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
 * @brief closes connection to database
 */
void sql::connectionClose()
{
    /*close connection and remove database*/
    db.close();
    db.removeDatabase(QSqlDatabase::defaultConnection);
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
 * counts all the rows with username same as parameter
 * if count is equal to one, returns true
 * else, returns false
 */
bool sql::usernameExists(QString username)
{
    int count = 0;       //number of entries with username same as x

    /*select all rows with username same as x and count them*/
    QSqlQuery qry;
    qry.exec("SELECT * FROM accounts WHERE username='"+username+"'");
    while(qry.next())
    {
        count++;
    }

    /*if only one account with username same as x is found, return true ,else return false*/
    if (count == 1){
        qDebug()<<"Username"<<username<<"found.";
        return true;
    }else{
        qDebug()<<"Username"<<username<<"not found";
        return false;
    }
}


/**
 * @brief stores the password in 2nd parameter and key in 3rd parameter of the username in 1st parameter
 * @param x
 * @param y
 * @param z
 *
 * selects all elements of table accounts where username is same as x
 * stores value of 2nd column(password) i.e. in position 1 in table accounts in y which is passed by reference
 * stores value of 3rd column(password) i.e. in position 2 in table accounts in z which is also passed by reference
 */
void sql::importAccountDetails(QString username, QString &password, int &key)
{
    /*select all elements of table accounts where username matches*/
    QSqlQuery qry;
    qry.exec("SELECT * FROM accounts WHERE username='"+username+"'");
    while (qry.next())
    {
        /*store value of 2nd column(password) i.e. in position 1 in table accounts in password*/
        password = qry.value(1).toString();
        /*store value of 3rd column(key) i.e. in position 2 in table accounts in key*/
        key = qry.value(2).toInt();
        qDebug()<<"Encrypted password and key received...";
        qDebug()<<"Encrypted password:"<<password;
        qDebug()<<"Key:"<<key;
    }
}

/**
 * @brief exports the account information into database
 * @param dummy
 */
void sql::exportAccount(account dummy)
{
    QSqlQuery qry;
    qry.exec("INSERT INTO accounts VALUES('"+dummy.username+"','"+dummy.getPassword()+"','"+dummy.f_name+"', '"+dummy.l_name+"',"+QString::number(dummy.getKey())+")");
    qDebug() << dummy.username << " " << dummy.getPassword() << " " <<dummy.getKey();
}

/**
 * @brief deletes default account from the database
 */
void sql::deleteDefault()
{
    QSqlQuery qry;
    // needed for case
    qry.exec("DELETE FROM accounts WHERE key = 0");
}
/**
 * @brief exports data of Car x from the program to the database
 * @param x
 *
 * runs a sql query to insert members of car x into database
 */
void sql::exportCarDetails(Car x)
{
    /*run a sql query to insert members of car x into database*/
    QSqlQuery qry;
    qry.exec("INSERT INTO cars (PlateNumber, Brand, Model, Rate, isAvailable) VALUES ('"+x.PlateNum+"', '"+x.Brand+"', '"+x.Model+"', "+QString::number(x.Rate)+", "+QString::number(x.isAvailable)+")");

}
