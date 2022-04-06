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
    QDate DateRented;
    QDate DateToReturn;
    QDate DateReturned;
    QString PhotoPath;
    QString phone_no;
    Car();
    friend int calculateDaysRented(QDate d1, QDate d2);
};

int calculateDaysRented(QDate d1, QDate d2);

#endif // CAR_H
