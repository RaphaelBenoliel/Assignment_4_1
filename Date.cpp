//
// Created by Raphael Benoliel on 01/06/2022.
//

#include "Date.h"

Date::Date() {
    this->day = 1;
    this->month = 1;
    this->year = 1900;
}

ostream &operator<<(ostream &os, const Date &other) {
    os << other.day << "/" << other.month << "/" << other.year;
    return os;
}

void Date::setDate(int d, int m, int y) {
    if(y >= 1900 && y <= 2100){
        if (m == 2 ){
            if((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))//check if is a leap year
            {
                if(d > 0 && d < 30){
                    this->day = d;
                    this->month = m;
                    this->year = y;
                }
                else
                    throw "Incorrect date!Pls try again.";
            }
            else{
                if(d > 0 && d < 29){
                    this->day = d;
                    this->month = m;
                    this->year = y;
                }
                else
                    throw "Incorrect date!Pls try again.";
            }
        }
        else if (m == 4 || m == 6 || m == 9 || m == 11 ){
            if(d > 0 && d < 31){
                this->day = d;
                this->month = m;
                this->year = y;
            }
            else
                throw "Incorrect date!Pls try again.";
        }
        else if(m == 1 || m== 3 || m == 5 || m== 7 ||m==8|| m == 10||m==12){
            if(d > 0 && d < 32){
                this->day = d;
                this->month = m;
                this->year = y;
            }
            else
                throw "Incorrect date!Pls try again.";
        }
        else
            throw "Incorrect date!Pls try again.";
    }
    else
        throw "Incorrect date!Pls try again.";
}

bool Date::operator==(const Date &other) const {
    return (day == other.day && month == other.month && year == other.year);
}