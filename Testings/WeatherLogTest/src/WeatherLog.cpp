#include "WeatherLog.h"

using namespace std;

void WeatherLog::setWindSpeed(float x)
{
    windSpeed = x;
}

float WeatherLog::getWindspeed()const
{
    return windSpeed;
}

void WeatherLog::setSolarRadiation(float x)
{
    solarRadiation = x;
}

float WeatherLog::getSolarRadiation()const
{
    return solarRadiation;
}

const Date& WeatherLog::getDate() const
{
    return dateOfWeather;
}

/**
Time* WeatherLog::getTime()
{
    return &timeOfWeather;
}
*/
void WeatherLog::setDate(const Date& obj)
{
    dateOfWeather.setDay(obj.getDay());
    dateOfWeather.setMonth(obj.getMonth());
    dateOfWeather.setYear(obj.getYear());
}

void WeatherLog::setTime(const Time& obj)
{
    timeOfWeather.setHours(obj.getHours());
    timeOfWeather.setMinutes(obj.getMinutes());
}
