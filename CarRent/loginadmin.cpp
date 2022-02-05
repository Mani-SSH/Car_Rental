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
        /*display error if cannot connect to the database*/
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
 * @brief uses the empty labels in the login page to hint the default login details
 *
 * gets total number of accounts from getTotalAccounts()
 * checks if database is corrupted
 * if yes, sends an error message to user and terminates program
 * if not, checks if there is only one account in the database
 * if yes, shows default login details
 */
void LoginAdmin::hintLoginDetails()
{
    int x = admin.getTotalAccounts();
    /*check if database is corrupted*/
    if (x == 0){
        /*send an error message to user and terminates program*/
        QMessageBox::critical(this, "Error", "Database is corrupted");
        QCoreApplication::exit();
    }else if(x == 1){
        /*if there is only one account in the table accounts in the database, hint the user default login details*/
        ui->label_hintUsername->setText("Hint: useradmin");
        ui->label_hintPassword->setText("Hint: password");
    }
}


/**
 * @brief shows password if checkBox_showPassword is checked
 * @param arg1
 *
 * parameter arg1 is 0 if check box is unchecked
 * parameter arg1 is 1 if check box is partially checked
 * parameter arg1 is 2 if check box is checked
 * shows password if arg1 is 2
 * hides password if arg1 is 0
 */
void LoginAdmin::on_checkBox_showPassword_stateChanged(int arg1)
{
    switch(arg1)
    {
    case 0:
        ui->lineEdit_password->setEchoMode(QLineEdit::Password);
        break;
    case 2:
        ui->lineEdit_password->setEchoMode(QLineEdit::Normal);
        break;
    }
}


void LoginAdmin::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    int count = 0;
    QSqlQuery qry;
    qry.exec("SELECT * FROM accounts WHERE username='"+username+"'");
    qDebug()<<"Query executed";
    while(qry.next())
    {
        count++;
    }
    if (count == 1){
        count = 0;
        qry.exec("SELECT * FROM accounts WHERE username='"+username+"' AND password='"+password+"'");
        while(qry.next())
        {
            count++;
        }
        if (count == 1){
            QMessageBox::information(this, "SUCCESS", "Access granted");
            account thisUser(username, password);
        }else{
            QMessageBox::critical(this, "FAILURE", "Emotional damage");
        }
    }else{
        ui->label_hintUsername->setText("Username not found");
    }
}

