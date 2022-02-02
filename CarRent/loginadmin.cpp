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
    dbAdmin.setDatabaseName("C:/Program Files/Databases/accounts.db");

    /*remove this later (only for debugging)*/
    if (!dbAdmin.open()){
        QMessageBox::information(this, "Connected", "Connection to Database established");
    }else{
        QMessageBox::critical(this, "Error", "Cannot connect to Database");
    }


}

LoginAdmin::~LoginAdmin()
{
    delete ui;
}

