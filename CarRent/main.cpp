#include "loginadmin.h"
#include "sql.h"
#include "mainscreen.h"
#include "account.h"

#include <QApplication>
#include <QDebug>

sql admin;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginAdmin w;

    /*open connection to database*/
    //admin.connectionOpen();

    /*open login window*/
    w.show();
    a.exec();

    /*if login details are correct*/
    if (w.isLoggedIn){
        /*open main screen and copy the login details entered by the user*/
        MainScreen m;
        m.user = w.thisAccount;
        m.show();
        a.exec();
    }
    return 0;
}
