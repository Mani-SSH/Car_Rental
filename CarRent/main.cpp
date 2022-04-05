#include "loginadmin.h"
#include "sql.h"
#include "mainscreen.h"
#include "account.h"

#include <QApplication>
#include <QDebug>

sql admin;
bool isLoggedIn = false;   //are account details are correct? (initially set to false)
bool isClose = false;
account user;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    while(!isClose)
    {
        LoginAdmin w;

        /*open login window*/
        w.show();
        a.exec();

        /*if login details are correct*/
        if (isLoggedIn){
            /*open main screen*/
            MainScreen m;
            m.show();
            a.exec();
        }

        try{
            if (isLoggedIn){
                throw isLoggedIn;
            }
        }catch (bool){
            isLoggedIn = false;
        }

    }
    return 0;
}
