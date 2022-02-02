#include "loginadmin.h"
#include "ui_loginadmin.h"

LoginAdmin::LoginAdmin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginAdmin)
{
    ui->setupUi(this);

    dbAdmin = QSqlDatabase::addDatabase("QSQLITE");
}

LoginAdmin::~LoginAdmin()
{
    delete ui;
}

