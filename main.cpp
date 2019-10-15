#include<iostream>
#include<fstream>
#include<sstream>
#include <stdlib.h>
#include "WindLogVector.h"

using namespace std;

/// prototypes

istream& operator >>(istream &infile, Date &D);
istream& operator >> (istream &infile, Time &T);
istream& operator >>(istream &infile, WeatherLog &WL);
istream& operator >> (istream &infile, WindLogVector &WLV);
unsigned int chosenMonth();
unsigned int chosenYear();
void avgMonthWindSpeed(const WeatherLog & wlVector);
void maxWindSpeed(const WindLogVector  &wlvector);
void switchPrompts();
void switchMethod( const WindLogVector & wlvector);




istream& operator >>(istream &infile, Date &D){

    string temp;

    getline(infile, temp, '/');
    D.setDay(atoi(temp.c_str()));

    getline(infile, temp, '/');
    D.setMonth(atoi(temp.c_str()));

    getline(infile, temp, ' ');
    D.setYear(atoi(temp.c_str()));

    return infile;
}

istream& operator >> (istream &infile, Time &T){

    string temp;
    getline(infile, temp, ':');
    T.setHours(atoi(temp.c_str()));

    getline(infile, temp, ',');
    T.setMinutes(atoi(temp.c_str()));

    return infile;
}

istream& operator >>(istream &infile, WeatherLog &WL){

    string temp;
    static Date D;
    static Time T;

    infile >> D;

    WL.setDate(D);

    infile >> T;

    WL.setTime(T);

    for(unsigned int i = 0; i<9; i++)    /// need to make this one more flexible.
    {
        getline(infile, temp, ',');
    }

    getline(infile, temp, ',');
    WL.setWindSpeed(atoi(temp.c_str()));

    float tempf;
    getline(infile, temp, ',');
    if(atoi(temp.c_str()) >= 80){
        tempf = atoi(temp.c_str());
        tempf = tempf/6/1000;
        WL.setSolarRadiation(tempf);
    }
    else
        WL.setSolarRadiation(0);

    return infile;
}




istream& operator >> (istream &infile, WindLogVector &WLV){

    string temp;
    static WeatherLog WL;
    while(getline(infile, temp, '\n'))
    {
        infile >> WL;
        WLV.addWeatherLog(WL);
    }
    return infile;
}

unsigned int validity_Test(unsigned int x){

while(std::cin.fail())
{
   std::cout << "Error " << endl;
   std::cin.clear();
   std::cin.ignore(256,'\n');
   std::cin >> x;
}

return x;
}


unsigned int chosenMonth(){

unsigned int month;
cout<<"Enter a month "<<endl;
cin >> month;

month = validity_Test(month);

return month;
}

unsigned int chosenYear(){

unsigned int year;
cout<<"Enter a year "<<endl;
cin >> year;

year = validity_Test(year);

return year;
}


void totAverageWindSolar(const WindLogVector & wlvector){

    unsigned int year = chosenYear();

    float avgWindSpeed[12];
    float avgSolarRadiation[12];

     for(unsigned int i = 1; i <= 12; i++)
     {
        avgWindSpeed[i-1] = wlvector.getAvgWindSpeed(i, year);
        avgSolarRadiation[i-1] = wlvector.getMonthTotalSolarRadiation(i, year);
     }

     for(unsigned int i = 0; i<=12; i++)
     {
         if(avgWindSpeed[i] != -1)
            cout<<"Average Wind Speed for month " << i+1 << " is "<< avgWindSpeed[i]<<endl<<endl;
        else
            {
                cout<<"No data for given month."<<endl;
            }

            if(avgSolarRadiation[i] != -1)
            {
               cout<<"<Average Solar Radiataion for month " << i+1 << " is "<< avgSolarRadiation[i]<<endl<<endl;
            }
            else
                cout<<"No data for given month."<<endl;
     }

}


void totYearSolarRadiation(const WindLogVector & wlvector){
    unsigned int year = chosenYear();

    float tot[12];

    for(unsigned int i = 1; i <= 12; i++)
     tot[i-1] = wlvector.getMonthTotalSolarRadiation(i, year);

    for(unsigned int i = 0; i<12; i++)
    {
        if(tot[i] != -1)
            cout << "Total solar radiation for "<< i+1 << " is "<< tot[i] << endl;
        else
            cout << "No data for given month." << endl;
    }
}

void avgMonthWindSpeed(const WindLogVector & wlVector){

    unsigned int year = chosenYear();

    float avg [12];

    for(unsigned int i = 1; i <= 12; i++)
        avg[i-1] = wlVector.getAvgWindSpeed(i, year);

    for(unsigned int i = 0; i<12; i++)
    {
        if(avg[i] != -1)
            cout << " Average Wind Speed for "<< i+1 << " is "<< avg[i] << endl;
        else
            cout << "No data for given month." << endl;
    }
}


void maxWindSpeed(const WindLogVector  &wlvector){

    unsigned int month;
    unsigned int year;
    float maxWindSpeed;

    year = chosenYear();
    month = chosenMonth();

    maxWindSpeed = wlvector.getMaxWindSpeed(month, year);

    if(maxWindSpeed<0)
    {
        cout<<"Invalid Data"<<endl;
    }
    else
    cout<<"Max. Wind speed "<<maxWindSpeed;
}


void switchPrompts(){
    cout<<"Hit '1' for The maximum windspeed for a month and year"<<'\n';
    cout<<"Hit '2' for Average wind speed for each month of a specified year"<<'\n';
    cout<<"Hit '3' for Total solar radiation in kWh/m^2 for each month of a specified year"<<'\n';
    cout<<"Hit '4' for Average wind speed km/h & total Solar radiation in kWh/m^2 "<<'\n';
    cout<<"Hit '5' to Quit the program "<<'\n';
}

void switchMethod(const WindLogVector & wlvector)
{

    switchPrompts();

    unsigned int choice;

    cin >> choice;

    switch(choice)
    {
    case 1:
            maxWindSpeed(wlvector);
            break;

    case 2:
           avgMonthWindSpeed(wlvector);
           break;

    case 3:
            totYearSolarRadiation(wlvector);
            break;

    case 4:
          totAverageWindSolar(wlvector);
          break;

    case 5:
        break;

    default:
        choice = validity_Test(choice);
        switchMethod(wlvector);
    }
}


int main()
{
    ifstream infile( "MetaData.csv" );
        if(!infile) return -1;

    WindLogVector wlvector;

    infile >> wlvector;

    switchMethod(wlvector);

    return 0;
}

