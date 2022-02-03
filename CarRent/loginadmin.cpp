#include "loginadmin.h"
#include "ui_loginadmin.h"
#include "account.h"
#include <QMessageBox>

static bool isNewFile = true;

LoginAdmin::LoginAdmin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginAdmin)
{
    ui->setupUi(this);

    /*add and open SQLite database through dbAdmin in the given path*/
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Databases/carrent.db");

    /*remove this later (only for debugging). Checks if the databse is opened*/
    if (!db.open()){
        QMessageBox::critical(this, "Error", "Cannot connect to Database. Please create folder, Databases, in C Drive.");
    }else{
        QMessageBox::information(this, "Connected", "Connection to Database established.");
    }

    if(isNewFile){
        createdbFile();
    }
}

/*returns the status of the file i.e. if the database created is new or not*/
bool LoginAdmin::dbFileStatus(){return isNewFile;}

/*initializes database*/
void LoginAdmin::createdbFile()
{
    QSqlQuery query;
    /*create a table 'accounts' in the database with column username(primary key), password and key and inserts default account info*/
    query.exec("CREATE TABLE IF NOT EXISTS accounts (username VARCHAR(20) PRIMARY KEY, password VARCHAR(20), key INT)");
    query.exec("INSERT INTO accounts VALUES('useradmin', 'password', 0)");
    isNewFile = false;
}

LoginAdmin::~LoginAdmin()
{
    delete ui;
}

