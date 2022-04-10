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
    query.exec("CREATE TABLE IF NOT EXISTS cars (PlateNumber VARCHAR(10) NOT NULL PRIMARY KEY, Brand VARCHAR(10) NOT NULL, Model VARCHAR(10) NOT NULL, Rate INT NOT NULL, isAvailable INT NOT NULL, PhotoPath VARCHAR(10))");
    query.exec("CREATE TABLE IF NOT EXISTS rentedcars (PlateNumber VARCHAR(10) NOT NULL, phone_no VARCHAR(10) NOT NULL, DateRented TEXT NOT NULL, DateToReturn TEXT NOT NULL, Cost INT NOT NULL)");
    query.exec("CREATE TABLE IF NOT EXISTS costumers (phone_no VARCHAR(10) NOT NULL PRIMARY KEY, f_name VARCHAR(20) NOT NULL, l_name VARCHAR(20) NOT NULL, Age INT NOT NULL, Address VARCHAR(20) NOT NULL, Lisence_Number VARCHAR(12) NOT NULL, Gender INT NOT NULL, Strikes INT NOT NULL)");
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
        key = qry.value(4).toInt();
        qDebug()<<"Encrypted password and key received...";
        qDebug()<<"Encrypted password:"<<password;
        qDebug()<<"Key:"<<key;
    }
}


/**
 * @brief imports first and last name of the account x from the database
 * @param x
 *
 * uses an sql query to import the data
 */
void sql::importName(account &x)
{
    /*run query to select all from table accounts where username store in x matches*/
    QSqlQuery qry;
    qry.exec("SELECT * FROM accounts WHERE username = '"+x.username+"'");

    /*import data of 3rd and 4th column i.e. the position 2 and 3*/
    while(qry.next())
    {
        x.f_name = qry.value(2).toString();
        x.l_name = qry.value(3).toString();
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
 * @brief checks if only account in the database is the default account
 * @return true if the account matches the details of the default account else false
 */
bool sql::isDefaultAccount()
{
    /*run a sql query to increase count if default account is found*/
    QSqlQuery qry;
    int count = 0;
    qry.exec("SELECT * FROM accounts WHERE username = 'useradmin' AND key = 0");
    while(qry.next())
    {
        count++;
    }

    /*return true if count is increased*/
    if (count == 1){
        return true;
    }else{
        return false;
    }
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
    qry.exec("INSERT INTO cars (PlateNumber, Brand, Model, Rate, isAvailable, PhotoPath) VALUES ('"+x.PlateNum+"', '"+x.Brand+"', '"+x.Model+"', "+QString::number(x.Rate)+", "+QString::number(x.isAvailable)+", '"+x.PhotoPath+"')");
}



void sql::rentCar(Car x)
{
    QSqlQuery qry;
    qry.exec("UPDATE cars SET isAvailable = 0 WHERE PlateNumber = '"+x.PlateNum+"'");
    qry.exec("INSERT INTO rentedcars (PlateNumber, phone_no, DateRented, DateToReturn, Cost) VALUES ('"+x.PlateNum+"', '"+x.phone_no+"', '"+x.DateRented.toString()+"', '"+x.DateToReturn.toString()+"', "+QString::number(x.Cost)+")");
}


/**
  * @brief imports the table cars based on the filters taken as parameters from the database
  * @param isAvailable
  * @param lowerRange
  * @param upperRange
  * @return address of the model of the sql query
  */
 QSqlQueryModel* sql::filterTablecars(bool isAvailable, int lowerRange,int upperRange, bool isAscendingOrder)
 {
     /*make a static QSqlQueryModel to return its address*/
     static QSqlQueryModel model;

     if(isAscendingOrder){
        /*query to select only the PlateNumber, Brand, Model and Rate of the cars where parameters match*/
        model.setQuery("SELECT PlateNumber, Brand, Model, Rate FROM cars WHERE isAvailable = "+QString::number(isAvailable)+" AND Rate >= "+QString::number(lowerRange)+" AND Rate < "+QString::number(upperRange)+" ORDER BY Rate ASC");
     }else{
         model.setQuery("SELECT PlateNumber, Brand, Model, Rate FROM cars WHERE isAvailable = "+QString::number(isAvailable)+" AND Rate >= "+QString::number(lowerRange)+" AND Rate < "+QString::number(upperRange)+" ORDER BY Rate DESC");
     }

     /*returns the address of the model*/
     return &model;
 }

 /**
  * @brief imports the table cars based on the PlateNum searched from the database
  * @param PlateNum
  * @return address of the model of the sql query
  */
 QSqlQueryModel* sql::searchTablecars(QString PlateNum)
 {
     static QSqlQueryModel model;

     model.setQuery("SELECT PlateNumber, Brand, Model, Rate FROM cars WHERE PlateNumber = '"+PlateNum+"'");

     return &model;
 }

/**
 Car sql::importCar(QString val)
 {
     Car x;
     QSqlQuery qry;
     qry.exec("SELECT * FROM cars WHERE PlateNumber = '"+val+"'");
 }
 */

 /**
  * @brief checks if the car with the given plate number already exists
  * @param PlateNum
  * @return true if the car exists and false if doesn't
  */
 bool sql::carExists(QString PlateNum)
 {
     /*run a sql query to increase count if the car with given plate number is found*/
     int count = 0;
     QSqlQuery qry;
     qry.exec("SELECT * FROM cars WHERE PlateNumber = '"+PlateNum+"'");
     while (qry.next())
     {
         count++;
     }

     /*return true if count is increased*/
     if (count == 1){
         return true;
     }else{
         return false;
     }
 }


 /**
  * @brief returns an object of class car with all the data from the database
  * @param PlateNum of the car
  * @return
  *
  * runs query to copy all the data from table car in the database where PlateNum matches
  * if car is rented, run a query to get data of customer and dates when car was rented and to be returned
  * returns the object where all data is stored
  */
 Car sql::importCar(QString PlateNum)
 {
     Car ThisCar;    //an object of class car

     /*run query to copy all the data from table car in the database where PlateNum matches*/
     QSqlQuery qry;
     qry.exec("SELECT * FROM cars WHERE PlateNumber = '"+PlateNum+"'");
     while (qry.next())
     {
         ThisCar.PlateNum = PlateNum;
         ThisCar.Brand = qry.value(1).toString();
         ThisCar.Model = qry.value(2).toString();
         ThisCar.Rate = qry.value(3).toInt();
         ThisCar.isAvailable = qry.value(4).toBool();
         ThisCar.PhotoPath = qry.value(5).toString();
     }
     qry.clear();
     /*if car is rented, run a query to get data of customer and dates when car was rented and to be returned*/
     if(!ThisCar.isAvailable){
         qry.exec("SELECT * FROM rentedcars WHERE PlateNumber = '"+PlateNum+"'");
         while (qry.next())
         {

                 ThisCar.phone_no = qry.value(1).toString();
                 ThisCar.DateRented = QDate::fromString(qry.value(2).toString());
                 ThisCar.DateToReturn = QDate::fromString(qry.value(3).toString());
         }
     }
     return ThisCar;
 }


 /**
  * @brief update data in database when car is returned
  * @param x
  *
  * set the car as available
  * deletes the data of the car in table rentedcars
  */
 void sql::returnCar(Car x)
 {
     QSqlQuery qry;
     qry.exec("UPDATE cars SET isAvailable = 1 WHERE PlateNumber = '"+x.PlateNum+"'");
     qry.exec("DELETE FROM rentedcars WHERE PlateNumber = '"+x.PlateNum+"'");
 }


 void sql::deleteCar(Car x)
 {
     QSqlQuery qry;
     qry.exec("DELETE FROM cars WHERE PlateNumber = '"+x.PlateNum+"'");
 }


 void sql::exportCostumer(Costumer x)
 {
     QSqlQuery qry;
    if( qry.exec("INSERT INTO costumers (phone_no, f_name, l_name, Age, Address, Lisence_Number, Gender, Strikes) VALUES ('"+x.phone_no+"', '"+x.C_fname+"', '"+x.C_lname+"', '"+QString::number(x.age)+"', '"+x.Address+"', '"+x.lisence_no+"', '"+x.gender+"', "+QString::number(x.strikes)+")"))
    {
        qDebug() << "value added";
    }
 }

 QSqlQueryModel* sql ::searchTableCostumer(QString searchText, bool isPhone)
 {
     static QSqlQueryModel modal;
     if (isPhone)
        {
            modal.setQuery("SELECT phone_no,f_name,l_name FROM costumers WHERE phone_no = '"+searchText+"'");
        }
     else
     {
         modal.setQuery("SELECT phone_no, f_name, l_name FROM costumers WHERE Lisence_Number = '"+searchText+"' ");
     }
     return &modal;
 }

 Costumer sql :: importCostumer(QString searchText, bool isPhone)
 {
     Costumer dummy;
     QSqlQuery qry;
     if (isPhone)
     {
         qry.exec("SELECT * FROM costumers WHERE phone_no = '"+searchText+"'");
     }
     else
     {
         qry.exec("SELECT * FROM costumers WHERE Lisence_Number = '"+searchText+"'");
     }

     while (qry.next())
     {
         dummy.phone_no = qry.value(0).toString();
         dummy.C_fname = qry.value(1).toString();
         dummy.C_lname = qry.value(2).toString();
         dummy.age = qry.value(3).toInt();
         dummy.Address = qry.value(4).toString();
         dummy.lisence_no = qry.value(5).toString();
         dummy.gender = qry.value(6).toString();
         dummy.strikes = qry.value(7).toInt();
     }
     return dummy;
 }


 /**
  * @brief checks if the customer exists on the database
  * @param phone_no of the customer
  * @return true, if customer exists
  *
  * runs a sql query to increase count if the car with given plate number is found
  * returns true if count is increased
  */
 bool sql::costumerExists(QString phone_no)
 {
     /*run a sql query to increase count if the car with given plate number is found*/
     int count = 0;
     QSqlQuery qry;
     qry.exec("SELECT * FROM costumers WHERE phone_no = '"+phone_no+"'");
     while (qry.next())
     {
         count++;
     }

     /*return true if count is increased*/
     if (count == 1){
         return true;
     }else{
         return false;
     }
 }

 /**
  * @brief checks if the customer currently holds a rented car
  * @param phone_no of the customer
  * @return true, if customer currently holds a rented car
  *
  * runs a sql query to increase count if the car with given plate number is found
  * returns true if count is increased
  */
 bool sql::hasCustomerRented(QString phone_no)
 {
     /*run a sql query to increase count if the car with given plate number is found*/
      int count = 0;
      QSqlQuery qry;
      qry.exec("SELECT * FROM rentedcars WHERE phone_no = '"+phone_no+"'");
      while (qry.next())
      {
          count++;
      }

      /*return true if count is increased*/
      if (count == 1){
          return true;
      }else{
          return false;
      }
 }



 void sql::strikeCustomer(QString phone_no)
 {
     /*run a query to get strikes of customer*/
     int strikes = 0;
     QSqlQuery qry;
     qry.exec("SELECT Strikes FROM costumers WHERE phone_no = '"+phone_no+"'");
     while (qry.next())
     {
         strikes = qry.value(7).toInt();
     }

     /*increase strikes*/
     strikes++;

     /*update to database*/
     qry.exec("UPDATE costumers SET Strikes = "+QString::number(strikes)+" WHERE phone_no = '"+phone_no+"'");
 }

 QSqlQueryModel* sql ::filterTableCostumer(int status)
 {
     static QSqlQueryModel modal;
     if (status == 0)
     {
         modal.setQuery("SELECT phone_no,f_name,l_name FROM costumers WHERE Strikes = 0 OR Strikes = 1 OR Strikes = 2");
     }
     else
     {
         modal.setQuery("SELECT phone_no,f_name,l_name FROM costumers WHERE Strikes = 3");
     }
     return &modal;
 }
