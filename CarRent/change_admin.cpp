#include "change_admin.h"
#include "ui_change_admin.h"
#include <QMessageBox>
extern bool isLoggedIn;

change_admin::change_admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::change_admin)
{
    ui->setupUi(this);

    /*adding logout icon*/
    ui->pushButton_logout->setIcon(QIcon(":/resources/img/logout.png"));

    /*adding add account icon*/
    ui->pushButton_addAccount->setIcon(QIcon(":/resources/img/add account.png"));
}

change_admin::~change_admin()
{
    delete ui;
}

void change_admin::on_pushButton_addAccount_clicked()
{
    account thisAccount;
    /*open dialog to add new account*/
    admin_info Admin_info;
    Admin_info.setModal(true);
    Admin_info.exec();

    /*check if new account has been added*/
    if(Admin_info.isAccountAdded){

        /*close the current window and show message box*/
        this->close();

        QMessageBox::information(this,"Account Added","New Account has been added");

    }else{
        /*if new account is not added then close window*/
        this->close();
    }

}


void change_admin::on_pushButton_logout_clicked()
{
    isLoggedIn = false;
    this->close();
}

