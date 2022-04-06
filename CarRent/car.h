#ifndef CAR_H
#define CAR_H

#include <QString>
#include <QDate>

class Car
{
public:
    QString PlateNum;
    QString Brand;
    QString Model;
    int Rate;
    bool isAvailable = false;
    QString PhotoPath;
    QDate DateRented;
    QDate DateToReturn;
    QDate DateReturned;
    QString phone_no;
    int Cost;
    Car();
    //Car(Car &x);
    friend int calculateDaysRented(QDate d1, QDate d2);
};

int calculateDaysRented(QDate d1, QDate d2);

#endif // CAR_H
