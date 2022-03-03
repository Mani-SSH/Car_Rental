#include "loginadmin.h"
#include "sql.h"
#include "mainscreen.h"
#include "account.h"

#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginAdmin w;
    w.show();
    a.exec();
    if (w.isLogged){
        MainScreen m;
        w.admin.connectionClose();
        m.user = w.thisAccount;
        /*connect to database*/
        if(m.database.connectionOpen()){
            qDebug()<<"Connected...";
        }else{
            /*display error if cannot connect to the database*/
            qDebug()<<"Cannot connect to database";
            //QMessageBox::critical(this, "Error", "Cannot connect to the database.");
            QCoreApplication::exit();
        }
        m.show();
        a.exec();
    }
    return 0;
}
