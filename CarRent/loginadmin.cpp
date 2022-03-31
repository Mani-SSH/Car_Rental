#include "loginadmin.h"
#include "ui_loginadmin.h"
#include "account.h"
#include <QPixmap>

extern sql admin;
extern bool isLoggedIn;
extern bool isClose;

LoginAdmin::LoginAdmin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginAdmin)
{
    ui->setupUi(this);

    /*connect to database*/
    if(admin.db.isOpen()){
        /*if already opened*/
        qDebug()<<"Connected...";
        hintLoginDetails();
    }else{
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
      

    /*adding background image in admin login page*/
    QPixmap bkgnd(":/resources/img/background.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    /*adding logo in admin login page*/
    QPixmap pix(":/resources/img/logo.png");
    ui->label_logo->setPixmap(pix.scaled(130,50,Qt::IgnoreAspectRatio));

    //adding icons
    QIcon username(":/resources/img/user.png");
    QIcon pass(":/resources/img/pass.png");
    ui->lineEdit_username->addAction(username,QLineEdit::LeadingPosition);
    ui->lineEdit_password->addAction(pass,QLineEdit::LeadingPosition);
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
        /*if there is only one account in the table accounts in the database*/
        /*check if the account is default*/
        if(admin.isDefaultAccount()){
            /*if it is default account, hint username and password*/
            ui->label_hintUsername->setText("Hint: useradmin");
            ui->label_hintPassword->setText("Hint: password");
        }
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
        QString encryptedPassword;
        int key;
        admin.importAccountDetails(username, encryptedPassword, key);
        thisAccount.username = username;

        /*if the decrypted password from the database and password entered by the user matches*/
        if (thisAccount.decrypt(encryptedPassword, key) == password){
            /*check if it is logged in from the default user details*/
            /*if yes, open a new pop up window to remove and add new user details*/
            /*else set password and first and last name*/
            thisAccount.setPassword(password);

            /*hide the current ui*/
            this->hide();

            /*if the account is default account*/
            if(admin.isDefaultAccount()){
                /*open dialog to add new account*/
                admin_info Admin_info;
                Admin_info.setModal(true);
                Admin_info.exec();

                /*check if new account has been added*/
                if(Admin_info.isAccountAdded){
                    /*copy account information*/
                    thisAccount = Admin_info.admin_account;

                    /*delete default account*/
                    admin.deleteDefault();

                    /*close the current window and set isLoggedIn as true*/
                    this->close();
                    isLoggedIn = true;
                }else{
                    /*if new account is not added then open login*/
                    this->show();
                }
            }else{
                /*close the current window and set isLoggedIn as true*/
                this->close();
                isLoggedIn = true;
            }
        }else{

          /*if wrong password, give an error message*/
            ui->label_hintPassword->setText("<font color='red'>Incorrect Password");

        }
    }else{
        /*if username does not exists, show username not found*/
        ui->label_hintUsername->setText("<font color='red'>Username not found");

    }
}


void LoginAdmin::on_pushButton_Exit_clicked()
{
    isClose = true;
    this->close();
}

