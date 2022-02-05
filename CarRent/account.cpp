#include "account.h"
#include "sql.h"

account::account()
{
    username = "";
    password = "";
}

account::account(QString x, QString y)
{
    username = x;
    password = y;
}

