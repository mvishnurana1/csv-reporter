#include "Time.h"

Time::Time(){

    hour = 0;
    minute = 0;
}


void Time::setHours(unsigned int x){
    hour = x;
}

unsigned int  Time:: getHours() const{
    return hour;
}

void Time::setMinutes(unsigned int x){
    minute = x;
}

unsigned int Time::getMinutes()const{
    return minute;
}

