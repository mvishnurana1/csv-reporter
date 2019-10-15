#ifndef WEATHERLOG_H
#define WEATHERLOG_H

#include "Date.h"
#include "Time.h"

	/**
	 * @class Time
	 * @brief  Contains details about the weather like- windspeed and
	 * solar radiations when the weather report was recorded in the system.
	 *
	 * Contains only 4 private variables i.e. windSpeed, solarRadiation, dateOfWeather and timeOfWeather.
	 * Reads input from and writes on console
	 *
	 * @author Vishnu Rana
	 * @version 01
	 * @date 21/04/2017
	 *
	 *
	 * @todo Add extra classes.
	 */

class WeatherLog
{
    public:

        /**
        * @brief sets the private variable windSpeed to certain speed.
        *
        * @return void
        */
        void setWindSpeed(float x);

        /**
        * @brief accessor method for variable windSpeed.
        *
        * @return windSpeed
        */
        float getWindspeed() const;

        /**
        * @brief sets the private variable SolarRadiation to certain value.
        *
        * @return void
        */
        void setSolarRadiation(float x);

        /**
        * @brief accessor method for variable solarRadiation.
        *
        * @return solarRadiation
        */
        float getSolarRadiation() const;

        /**
        * @brief the method which gives access to all the private attributes of class Date
        * takes the Date obj as a parameter.
        *
        * @return void
        */
        void setDate(const Date& obj);

        /**
        * @brief sets the private data of the Date class through WeatherLog class
        *
        * @return void
        */
        const Date& getDate() const;

        /**
        * @brief  the method which gives access to all the private attributes of class Time
        * takes the Time obj as a parameter
        *
        * @return void
        */
        void setTime(const Time& obj);

    private:
        /// variable for storing wind speed.
        float windSpeed;

        /// variable for storing the solar radiation.
        float solarRadiation;

        /// variable for accessing the Date class through WeatherLog class.
        Date dateOfWeather;

        /// variable for accessing the Time class through WeatherLog class.
        Time timeOfWeather;
};

#endif // WEATHERLOG_H
