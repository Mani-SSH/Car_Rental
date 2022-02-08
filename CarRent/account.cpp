#include "account.h"
#include "sql.h"

account::account()
{
    username = "";
    password = "";
    key = 0;
}

account::account(QString x, QString y, int z)
{
    username = x;
    password = y;
    key = z;
}

