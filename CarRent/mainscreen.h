#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QMainWindow>
#include <QMessageBox>

#include "account.h"
#include "sql.h"
#include "car.h"
#include "change_admin.h"

namespace Ui {
class MainScreen;
}

class MainScreen : public QMainWindow
{
    Q_OBJECT

public:
    account user;
    explicit MainScreen(QWidget *parent = nullptr);
    ~MainScreen();

private slots:
    void on_lineEdit_rate_textEdited(const QString &arg1);

    void on_pushButton_addCar_clicked();

private:
    Ui::MainScreen *ui;
};

#endif // MAINSCREEN_H
