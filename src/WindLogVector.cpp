#include "WindLogVector.h"

WindLogVector::WindLogVector()
{
    //ctor
}

void WindLogVector::addWeatherLog(const WeatherLog &x){
    wVector.insertObject(x);
}
/*
const WeatherLog& WindLogVector::getWeatherLog(unsigned int index){
    return wVector.getIndex(index);
}
*/

unsigned int WindLogVector::getVectorSize() const{

    return wVector.getCurrentIndex();
}


float WindLogVector::getMaxWindSpeed(unsigned int month, unsigned int year)const
{
    float maxWindSpeed = -1;

     for(unsigned int i=0;i< wVector.getCurrentIndex(); i++)
        {
            if(wVector.getIndex(i).getDate().getMonth() == month && wVector.getIndex(i).getDate().getYear() == year)
            {
                   if(wVector.getIndex(i).getWindspeed() > maxWindSpeed)
                   {
                        maxWindSpeed = wVector.getIndex(i).getWindspeed();
                   }
            }
        }
    return maxWindSpeed;
}


float WindLogVector::getAvgWindSpeed(unsigned int month ,unsigned int year) const
{

    float avg = 0;
    float total = 0;

    for (unsigned i = 0; i < wVector.getCurrentIndex(); i++)
    {
        if(wVector.getIndex(i).getWindspeed())
            if(wVector.getIndex(i).getDate().getYear() == year && wVector.getIndex(i).getDate().getMonth() == month)
            {
                avg = avg + wVector.getIndex(i).getWindspeed();
                total++;
            }
    }
    if(total > 0)
    {
        avg = avg/total;
        return avg;
    }
    else
        return -1;
}


float WindLogVector::getMonthTotalSolarRadiation(unsigned int month, unsigned int year) const
{
    float totalsolarRadiation = 0;

    for (unsigned i = 0; i < wVector.getCurrentIndex(); i++)
    {

        if(wVector.getIndex(i).getSolarRadiation())
        {
            if(wVector.getIndex(i).getDate().getYear() == year && wVector.getIndex(i).getDate().getMonth() == month)
            {
                totalsolarRadiation = totalsolarRadiation + wVector.getIndex(i).getSolarRadiation();
            }
        }
    }

    if(totalsolarRadiation > 0)
        return totalsolarRadiation;
    else
        return -1;
}





