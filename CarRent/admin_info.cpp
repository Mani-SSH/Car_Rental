#include "admin_info.h"
#include "ui_admin_info.h"
#include "account.h"

admin_info::admin_info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin_info)
{
    ui->setupUi(this);
    if(admin_data.connectionOpen()){
        qDebug()<<"Connected...";

    }else{

        /*display error if cannot connect to the database*/
        qDebug()<<"Cannot connect to database";
        QMessageBox::critical(this, "Error", "Cannot connect to the database.");
        QCoreApplication::exit();
    }
}

admin_info::~admin_info()
{
    delete ui;
}

void admin_info::on_pushButton_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    QString confirm_password = ui->lineEdit_confirm_password->text();

    // checks existing username in database.
    if (admin_data.usernameExists(username))
    {
        ui->label_username_check->setText("invalid username");
    }

    // confirms the password
    if (confirm_password != password)
    {
        ui->label_password_check->setText("password doesn't match");
    }

}

