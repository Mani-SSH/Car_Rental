#ifndef LOGINADMIN_H
#define LOGINADMIN_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>
#include "sql.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LoginAdmin; }
QT_END_NAMESPACE

class LoginAdmin : public QMainWindow, public sql
{
    Q_OBJECT

public:
    sql admin;
    LoginAdmin(QWidget *parent = nullptr);
    ~LoginAdmin();
    void hintLoginDetails();

private slots:
    void on_checkBox_showPassword_stateChanged(int arg1);

private:
    Ui::LoginAdmin *ui;
};
#endif // LOGINADMIN_H
