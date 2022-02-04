#include "loginadmin.h"
#include "ui_loginadmin.h"
#include "account.h"
#include "sql.h"

LoginAdmin::LoginAdmin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginAdmin)
{
    ui->setupUi(this);


}


LoginAdmin::~LoginAdmin()
{
    delete ui;
}

