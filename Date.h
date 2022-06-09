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
    void setDate(int d, int m, int y);
    bool operator==(const Date &other)const;
    friend ostream& operator<<(ostream &os,const Date& other);

};


#endif //ASSIGNMENT_4_1_DATE_H
