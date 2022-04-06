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

/**
Car::Car(Car &x)
{
    PlateNum = x.PlateNum;
    Brand = x.Brand;
    Model = x.Model;
    Rate = x.Rate;
    phone_no = x.phone_no;
    Cost = x.Cost;
    isAvailable = x.isAvailable;
    PhotoPath = x.PhotoPath;
    DateRented = x.DateRented;
    DateReturned = x.DateReturned;
    DateToReturn = x.DateToReturn;
}
*/

int calculateDaysRented(QDate d1, QDate d2)
{
    return d1.daysTo(d2);
}
