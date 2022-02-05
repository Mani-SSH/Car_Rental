#include "loginadmin.h"
#include "ui_loginadmin.h"
#include "account.h"

LoginAdmin::LoginAdmin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginAdmin)
{
    ui->setupUi(this);

    /*connect to database*/
    if(admin.connectionOpen()){
        qDebug()<<"Connected...";
        hintLoginDetails();
    }else{
        qDebug()<<"Cannot connect to database";
        QMessageBox::critical(this, "Error", "Cannot connect to the database.");
        QCoreApplication::exit();
    }
}

LoginAdmin::~LoginAdmin()
{
    delete ui;
}

/**
 * @brief LoginAdmin::hintLoginDetails
 *
 * uses the empty labels in the login page to hint the default login details
 */
void LoginAdmin::hintLoginDetails()
{
    /*if there is only one account in the table accounts in the database*/
    if (admin.getTotalAccounts() == 1){
        /*hint the user default login details*/
        ui->label_hintUsername->setText("Hint: useradmin");
        ui->label_hintPassword->setText("Hint: password");
    }
}



