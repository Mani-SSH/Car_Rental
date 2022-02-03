#include "loginadmin.h"
#include "ui_loginadmin.h"
#include "account.h"
#include <QMessageBox>

LoginAdmin::LoginAdmin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginAdmin)
{
    ui->setupUi(this);

    /*add and open SQLite database through dbAdmin in the given path*/
    dbAdmin = QSqlDatabase::addDatabase("QSQLITE");
    dbAdmin.setDatabaseName("C:/Databases/accounts.db");

    /*remove this later (only for debugging). Checks if the databse is opened*/
    if (!dbAdmin.open()){
        QMessageBox::critical(this, "Error", "Cannot connect to Database. Please Create Folder Databases on C drive.");
    }else{
        QMessageBox::information(this, "Connected", "Connection to Database established");
    }
/**
    QString query="CREATE TABLE IF NOT EXISTS accounts ("
                  "username VARCHAR(30),"
                  "password VARCHAR(30),"
                  "key INT);"
                  "INSERT INTO accounts(username, password, key) "
                  "VALUES ('admin', 'password', 0)";
    QSqlQuery qry;
    if (!qry.exec(query)){
        QMessageBox::critical(this, "Error", "Cannot create table");
    }
*/
}

LoginAdmin::~LoginAdmin()
{
    delete ui;
}

