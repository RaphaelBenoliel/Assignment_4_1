//
// Created by Raphael Benoliel on 01/06/2022.
//

#ifndef ASSIGNMENT_4_1_DATE_H
#define ASSIGNMENT_4_1_DATE_H
#include <ostream>
using namespace std;
class Date {
private:
    int day, month, year;
public:
    Date();
    friend ostream& operator<<(ostream &os,const Date& other);
    void setDate(int d, int m, int y);
};


#endif //ASSIGNMENT_4_1_DATE_H
