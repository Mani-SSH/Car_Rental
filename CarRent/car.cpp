#include "car.h"

Car::Car()
{
    PlateNum = NULL;
    Brand = NULL;
    Model = NULL;
    Rate = 0;
    phone_no = NULL;
    Cost = 0;
    //PhotoPath = <Path of default car icon on resources>
}


int Car::calculateCost()
{
    return Rate * calculateDaysRented(DateRented, DateToReturn);
}

int Car::calculateDaysRented(QDate d1, QDate d2)
{
    return d1.daysTo(d2);
}

