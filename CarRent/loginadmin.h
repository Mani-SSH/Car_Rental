#ifndef LOGINADMIN_H
#define LOGINADMIN_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginAdmin; }
QT_END_NAMESPACE

class LoginAdmin : public QMainWindow
{
    Q_OBJECT

public:
    LoginAdmin(QWidget *parent = nullptr);
    ~LoginAdmin();

private:
    Ui::LoginAdmin *ui;
    QSqlDatabase dbAdmin;          //database for admin accouts
};
#endif // LOGINADMIN_H
