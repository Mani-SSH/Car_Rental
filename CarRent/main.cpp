#include "loginadmin.h"
#include "sql.h"
#include "mainscreen.h"
#include "account.h"

#include <QApplication>
#include <QDebug>

sql admin;
bool isLoggedIn = false;   //are account details are correct? (initially set to false)
bool isClose = false;      //is program closed
account user;              //account entered bu the user

/**
 * @brief main program
 * @param argc
 * @param argv
 * @return 0
 *
 * loops while program is not close
 * ---------LOOP START--------
 * opens login window
 * check if isLoggedIn is true
 * if true, open mainscreen
 * if false, check if force exit was clicked, if it was clicked, use exception handling to set isClose as true
 * check if force exit was clicked on mainscreen, use exception handling to set isLoggedIn as false
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*loop while program is not close*/
    while(!isClose)
    {
        LoginAdmin w;

        /*open login window*/
        w.show();
        a.exec();

        /*if isLoggedIn is true*/
        if (isLoggedIn){
            /*open main screen*/
            MainScreen m;
            m.show();
            a.exec();
        }else{
            /*check if force exit button is clicked*/
            try{
                if (!isClose){
                    throw isLoggedIn;
                }
            }catch (bool){
                isClose = true;
            }
        }

        /*check if force exit button is clicked on main screen*/
        try{
            if (isLoggedIn){
                throw isLoggedIn;
            }
        }catch (bool){
            isLoggedIn = false;
        }

    }
    admin.connectionClose();
    return 0;
}
