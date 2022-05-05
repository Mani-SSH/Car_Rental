#include "car.h"

Car::Car()
{
    PlateNum = NULL;
    Brand = NULL;
    Model = NULL;
    Rate = 0;
    phone_no = NULL;
    Cost = 0;
    PhotoPath=":/resources/img/dummy car img-01.jpg";
    final_Cost = 0;
}


/**
 * @brief calculates the total cost of the car
 * @return cost of the car
 *
 * returns an integer by multiplying rate and the number of days rented
 */
int Car::calculateCost()
{
    /*return an integer by multiplying rate and the number of days rented*/
    return Rate * calculateDaysRented(DateRented, DateToReturn);
}

/**
 * @brief calculates days between d2 and d1
 * @param d1
 * @param d2
 * @return days between d2 and d1
 */
int Car::calculateDaysRented(QDate d1, QDate d2)
{
    /*return days between d2 and d1*/
    return d1.daysTo(d2);
}

/**
 * @brief calculates final cost of the rented car
 * @param daysreturned
 * @param daystoreturn
 * @return final cost of the rented car
 *
 * if number of days to return and number of days returned is not equal
 * then, calculate cost normally
 * else, total_cost(amount left to paid) is 0
 */
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

