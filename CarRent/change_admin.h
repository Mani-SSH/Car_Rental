#ifndef CHANGE_ADMIN_H
#define CHANGE_ADMIN_H

#include <QDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>
#include "sql.h"
#include "account.h"
#include "admin_info.h"



namespace Ui {
class change_admin;
}

class change_admin : public QDialog
{
    Q_OBJECT

public:
    explicit change_admin(QWidget *parent = nullptr);
    ~change_admin();

private slots:

    void on_pushButton_addAccount_clicked();

    void on_pushButton_logout_clicked();

private:
    Ui::change_admin *ui;
};

#endif // CHANGE_ADMIN_H
