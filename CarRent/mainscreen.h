#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QMainWindow>
#include <QMessageBox>

#include "account.h"
#include "sql.h"
#include "car.h"
#include "change_admin.h"
#include <QFileDialog>

namespace Ui {
class MainScreen;
}

class MainScreen : public QMainWindow
{
    Q_OBJECT

public:
    Car carToAdd;
    Car carClicked;

    explicit MainScreen(QWidget *parent = nullptr);
    void displayCar(Car x);
    void initializeRentCar(Car x);
    void initializeHomeTab();
    void initializeCarDisplay();
    void showCost(Car x);
    ~MainScreen();

private slots:
    void on_lineEdit_rate_textEdited(const QString &arg1);

    void on_pushButton_addCar_clicked();

    void on_tableView_Cars_activated(const QModelIndex &index);

    void on_pushButton_carSearch_clicked();

    void on_pushButton_carReload_clicked();

    void on_pushButton_carFilter_clicked();

    void on_pushButton_admin_clicked();

    void on_pushButton_clicked();

    void on_pushButton_Search_clicked();

    void on_pushButton_2_clicked();
    
    void on_dateEdit_rentDate_dateChanged(const QDate &date);

    void on_dateEdit_rentReturnDate_dateChanged(const QDate &date);

    void on_pushButton_rent_clicked();

    void on_lineEdit_rentDays_textChanged(const QString &arg1);

    void on_pushButton_carReturn_clicked();

    void on_pushButton_carDelete_clicked();

    void on_tableView_customer_activated(const QModelIndex &index);

    void on_pushButton_Filter_costumer_clicked();

private:
    Ui::MainScreen *ui;
};

#endif // MAINSCREEN_H
