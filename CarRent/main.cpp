#include "loginadmin.h"
#include "sql.h"
#include "mainscreen.h"
#include "account.h"

#include <QApplication>
#include <QDebug>

sql admin;
bool isLoggedIn = false;   //are account details are correct? (initially set to false)

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginAdmin w;

    /*open login window*/
    w.show();
    a.exec();

    /*if login details are correct*/
    if (isLoggedIn){
        /*open main screen and copy the login details entered by the user*/
        MainScreen m;
        m.user = w.thisAccount;
        m.show();
        a.exec();
    }
    return 0;
}
