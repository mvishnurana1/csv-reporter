#include <iostream>

#include "WindLogVector.h"


using namespace std;

int main()
{
    WindLogVector W;
    WeatherLog LW;
    Time T;
    Date D;

    LW.setSolarRadiation(23);
    LW.setWindSpeed(10);

    T.setHours(12);

    T.setMinutes(25);

    D.setDay(10);
    D.setMonth(9);
    D.setYear(2016);

    LW.setDate(D);
    LW.setTime(T);

    W.addWeatherLog(LW);


}
