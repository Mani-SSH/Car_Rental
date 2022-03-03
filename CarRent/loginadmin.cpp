#include "loginadmin.h"
#include "ui_loginadmin.h"
#include "account.h"
#include <QPixmap>

LoginAdmin::LoginAdmin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginAdmin)
{
    ui->setupUi(this);

    /*adding background image in admin login page*/
    QPixmap bkgnd(":/resources/img/background.jpg");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Window, bkgnd);
        this->setPalette(palette);

    /*adding logo in admin login page*/
        QPixmap pix(":/resources/img/logo.png");
        ui->label_logo->setPixmap(pix.scaled(130,50,Qt::KeepAspectRatio));

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
    int x = admin.importTotalAccounts();
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
        /*hides password*/
        ui->lineEdit_password->setEchoMode(QLineEdit::Password);
        break;
    case 2:
        /*shows password*/
        ui->lineEdit_password->setEchoMode(QLineEdit::Normal);
        break;
    }
}

/**
 * @brief INCOMPLETE
 */
void LoginAdmin::on_pushButton_login_clicked()
{
    /*get username and password entered by the user*/
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    /*if username entered by the user exists*/
    if (admin.usernameExists(username)){
        /*create an account to import the encrypted password and key of the given username from the database and set the username*/
        account thisAccount;
        QString encryptedPassword;
        int key;
        admin.importAccountDetails(username, encryptedPassword, key);
        thisAccount.username = username;

        /*if the decrypted password from the database and password entered by the user matches*/
        if (thisAccount.decrypt(encryptedPassword, key) == password){

            thisAccount.setPassword(password);

            /*check if it is logged in from the default user details*/
            /*if yes, open a new pop up window to remove and add new user details*/
            /*else set password and first and last name*/

            this -> hide();
            admin_info Admin_info;
            Admin_info.setModal(true);
            Admin_info.exec();
        }else{
            /*if wrong password, give an error message*/
            ui->label_hintPassword->setText("<font color='red' > Incorrect Password");
        }
    }else{
        /*if username does not exists show username not found*/
        ui->label_hintUsername->setText("<font color='red'>Username not found");

    }
}

