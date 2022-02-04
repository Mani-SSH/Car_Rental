#include "loginadmin.h"
#include "sql.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginAdmin w;
    sql s;
    w.show();
    return a.exec();
}
