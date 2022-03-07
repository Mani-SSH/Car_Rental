#ifndef LOGINADMIN_H
#define LOGINADMIN_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>
#include "sql.h"
#include "account.h"
#include "admin_info.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LoginAdmin; }
QT_END_NAMESPACE

class LoginAdmin : public QMainWindow
{
    Q_OBJECT

public:
    account thisAccount;
    bool isLogged = false;
    LoginAdmin(QWidget *parent = nullptr);
    ~LoginAdmin();
    void hintLoginDetails();

private slots:
    void on_checkBox_showPassword_stateChanged(int arg1);

    void on_pushButton_login_clicked();

private:
    Ui::LoginAdmin *ui;
};
#endif // LOGINADMIN_H
