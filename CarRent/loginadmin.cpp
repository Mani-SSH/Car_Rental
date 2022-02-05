#include "loginadmin.h"
#include "ui_loginadmin.h"
#include "account.h"
#include "sql.h"

LoginAdmin::LoginAdmin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginAdmin)
{
    ui->setupUi(this);

    /*connect to database*/
    if(admin.connectionOpen()){
        qDebug()<<"Connected...";
        if (admin.getTotalAccounts() == 1){
            ui->label_hintUsername->setText("Hint: useradmin");
            ui->label_hintPassword->setText("Hint: password");
        }
    }else{
        qDebug()<<"Cannot connect to database";
    }
}

LoginAdmin::~LoginAdmin()
{
    delete ui;
}



