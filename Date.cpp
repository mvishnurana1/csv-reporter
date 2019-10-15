#include "Date.h"


Date::Date()
{
    //ctor
}

void Date::setDay(unsigned int x){
    day = x;
}

unsigned int Date::getDay()const{
    return day;
}

void Date::setMonth(unsigned int x){
    month = x;
}

unsigned int Date::getMonth()const{
    return month;
}

void Date::setYear(unsigned int x){
    year = x;
}

unsigned int Date::getYear() const{
    return year;
}

