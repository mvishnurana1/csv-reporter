#ifndef TIME_H
#define TIME_H


	/**
	 * @class Time
	 * @brief  Contains details about the date when the weather report was recorded in the system.
	 *
	 * Contains only three unsigned member variables that is, HH:MM objects.\n
	 * Reads input from and writes on console
	 *
	 * @author Vishnu Rana
	 * @version 01
	 * @date 20/04/2017
	 *
	 *
	 * @todo Add extra classes.
	 */

class Time
{
    public:

        /**
        * @brief  a default constructor for the class Time.
        *
        * @return void
        */
        Time();

        /**
        * @brief  Used to set the bour HH for weather OF weather.
        *
        * @return void
        */
        void setHours(unsigned int x);


        /**
        * @brief Used to get the hour HH for Time OF weather.
        *
        * @return (unsigned int) hour
        */
        unsigned int getHours()const;


        /**
        * @brief mutator method for private variable minutes of class Time.
        *
        * @return void
        */
        void setMinutes(unsigned int x);

        /**
        * @brief accessor method for private variable minutes of class Time.
        *
        * @return an unsigned int minutes
        */
        unsigned int getMinutes() const;

    private:
        /// unsigned int for storing hours of the time.
        unsigned int hour;

        /// unsigned int for storing minutes of the time.
        unsigned int minute;
};

#endif // TIME_H
