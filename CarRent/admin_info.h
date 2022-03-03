#ifndef ADMIN_INFO_H
#define ADMIN_INFO_H

#include <QDialog>
#include <QMessageBox>
#include <QDebug>
#include "sql.h"

namespace Ui {
class admin_info;
}

class admin_info : public QDialog
{
    Q_OBJECT

public:
    sql admin_data;
    explicit admin_info(QWidget *parent = nullptr);
    ~admin_info();

private slots:
    void on_pushButton_clicked();

private:
    Ui::admin_info *ui;
};

#endif // ADMIN_INFO_H
