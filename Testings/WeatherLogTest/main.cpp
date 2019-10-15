#include <iostream>
#include "WeatherLog.h"
#include "Date.h"
#include "Time.h"

using namespace std;

int main()
{
    WeatherLog Obj;
    Time T;
    Date D;


    Obj.setWindSpeed(52);
    Obj.setSolarRadiation(12);

    T.setHours(12);
    T.setMinutes(29);

    D.setDay(10);
    D.setMonth(06);

    cout<< " WindSpeed " << Obj.getWindspeed() <<endl;
    cout<<" Solar Radiation "<< Obj.getSolarRadiation() <<endl;
    cout<<" Hours : "<< T.getHours() <<endl;
    cout<<"minutes : "<< T.getMinutes()<<endl;
    cout<< "Date "<< D.getDay() <<":" << D.getMonth()<<endl;


    return 0;
}
