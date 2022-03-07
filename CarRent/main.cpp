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

    w.show();
    a.exec();

    if (w.isLogged){
        MainScreen m;
        m.user = w.thisAccount;
        m.show();
        a.exec();
    }
    return 0;
}
