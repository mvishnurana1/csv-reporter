#ifndef DATE_H
#define DATE_H

	/**
	 * @class Date
	 * @brief  Contains details about the date when the weather report was recorded in the system.
	 *
	 * Contains only three unsigned member variables that is, dd/mm/yyyy objects.\n
	 * Reads input from and writes -coutput to files.\n
	 *
	 * @author Vishnu Rana
	 * @version 01
	 * @date 20/04/2017
	 *
	 *
	 * @todo Add extra classes.
	 */

class Date
{

    public:

        /**
        * @brief  a default constructor for the class weather.
        *
        * @return void
        */
        Date();

        /**
        * @brief  Used to set the day DD for DATE OF weather.
        *
        * @return void
        */
        void setDay(unsigned int x);


        /**
        * @brief Used to get the day DD for DATE OF weather.
        *
        * @return (unsigned int) day
        */
        unsigned int getDay() const;


        /**
        * @brief  Used to set the month MM for DATE OF weather.
        *
        * @return void
        */
        void setMonth(unsigned int);

        /**
        * @brief Used to get the month MM for MONTH OF weather.
        *
        * @return (unsigned int) month
        */
        unsigned int getMonth() const;


        /**
        * @brief  Used to set the day YYYY for DATE OF weather.
        *
        * @return void
        */
        void setYear(unsigned int x);


        /**
        * @brief Used to return the year YYYY for DATE OF weather.
        *
        * @return (unsigned int) year
        */
        unsigned int getYear() const;

    private:
        /// unsigned int for storing the day of weather (Date)
        unsigned int day;

        /// unsigned int for storing the month of weather (Date)
        unsigned int month;

        /// unsigned int for storing the year of weather (Date)
        unsigned int year;
};

#endif // DATE_H
