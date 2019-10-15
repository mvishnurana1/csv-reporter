#ifndef WINDLOGVECTOR_H
#define WINDLOGVECTOR_H

#include "WeatherLog.h"
#include "Vector.h"


class WindLogVector
{
    public:

        /**
        * @brief default constructor of the class WindLogVector.
        *
        * @return void
        */
        WindLogVector();


        /**
        * @brief The sub-routine adds the Objects
        *
        * @return void
        */
        void addWeatherLog(const WeatherLog& x);

        /**
        * @brief the sub-routine gets all the attributes of the class WeatherLog
        * So that, data can be accessed for calculations.
        *
        * @return WeatherLog Obj
        */
        const WeatherLog& getWeatherLog(unsigned int index);

        /**
        *
        *@brief returns the vector size
        *
        *@return unsigned int size
        */
        unsigned int getVectorSize() const;

        /**
        *
        *@brief the max windSpeed is used for calculating the maximum windSpeed for all the months in a given year.
        *
        *@return float windSpeed
        */
        float getMaxWindSpeed(unsigned int month, unsigned int year) const;

        /**
        *
        *@brief the sub-routine is used for calculating the average windSpeed and takes the specified
        * as a parameter.
        *
        *@return float windSpeed
        */
        float getAvgWindSpeed(unsigned int month ,unsigned int year) const;

        /**
        *
        * @brief the sub-routine is used for calculating the total Solar Radiation
        *
        * @return totalsolarRadiation
        */
        float getMonthTotalSolarRadiation(unsigned int month, unsigned int year) const;


    private:

        /// Vector of WeatherLog
        Vector<WeatherLog> wVector;

};

#endif // WINDLOGVECTOR_H
