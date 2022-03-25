#include "change_admin.h"
#include "ui_change_admin.h"

change_admin::change_admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::change_admin)
{
    ui->setupUi(this);
}

change_admin::~change_admin()
{
    delete ui;
}

void change_admin::on_pushButton_addAccount_clicked()
{
    /*open dialog to add new account*/
    admin_info Admin_info;
    Admin_info.setModal(true);
    Admin_info.exec();
}

