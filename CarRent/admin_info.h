#ifndef ADMIN_INFO_H
#define ADMIN_INFO_H

#include <QDialog>
#include <QMessageBox>
#include <QDebug>
#include "sql.h"
#include "account.h"

namespace Ui {
class admin_info;
}

class admin_info : public QDialog
{
    Q_OBJECT

public:
    account admin_account;
    explicit admin_info(QWidget *parent = nullptr);
    ~admin_info();

private slots:
    void on_pushButton_clicked();
    void on_checkBox_stateChanged(int arg1);

private:
    Ui::admin_info *ui;
};

#endif // ADMIN_INFO_H
