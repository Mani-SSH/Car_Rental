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
    PhotoPath=":/resources/img/dummy car img-01.jpg";
}


int Car::calculateCost()
{
    return Rate * calculateDaysRented(DateRented, DateToReturn);
}

int Car::calculateDaysRented(QDate d1, QDate d2)
{
    return d1.daysTo(d2);
}

int Car::finalCost(int daysreturned, int daystoreturn)
{
    int total_cost;
    if (daysreturned != daystoreturn)
    {
        total_cost = (daysreturned - daystoreturn) * Cost;
    }
    else
    {
        total_cost = 0;
    }
    return total_cost;

}

