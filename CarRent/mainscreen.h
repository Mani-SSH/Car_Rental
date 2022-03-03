#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QMainWindow>
#include "account.h"
#include "sql.h"

namespace Ui {
class MainScreen;
}

class MainScreen : public QMainWindow
{
    Q_OBJECT

public:
    sql database;
    account user;
    explicit MainScreen(QWidget *parent = nullptr);
    ~MainScreen();

private:
    Ui::MainScreen *ui;
};

#endif // MAINSCREEN_H
