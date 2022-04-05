#ifndef SQL_H
#define SQL_H

#include <QtSql>
#include <QFileInfo>
#include <QDir>
#include <QDebug>
#include "account.h"
#include "car.h"
#include "costumer.h"

class sql
{
public:
    QSqlDatabase db;           //database
    void createdbFile();
    bool connectionOpen();
    void connectionClose();
    int importTotalAccounts();
    bool usernameExists(QString username);
    void importAccountDetails(QString username, QString &password, int &key);
    int importKey();
    void exportAccount(account dummy);
    void deleteDefault();
    bool isDefaultAccount();
    QSqlQueryModel* filterTablecars(bool isAvailable, int lowerRange,int upperRange, bool isAscendingOrder);
    QSqlQueryModel* searchTablecars(QString PlateNum);
    Car importCar(QString PlateNum);
    void exportCarDetails(Car x);
    bool carExists(QString PlateNum);
    void exportCostumer(Costumer x);
    QSqlQueryModel* searchTableCostumer(QString searchText, bool isPhone);
    Costumer importCostumer(QString searchText, bool isPhone);
};

#endif // SQL_H
