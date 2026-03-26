/**
 * @file Time.h
 * @brief Declaration of the Time class.
 *
 * Represents a time using hour, minute, and second values.
 *
 * @author Patricia
 */

#ifndef TIME_H
#define TIME_H

/**
 * @class Time
 * @brief Stores a time using hour, minute, and second.
 *
 * Simple data class with getter and setter methods.
 */
class Time
{
public:
    /**
     * @brief Default constructor.
     *
     * Initializes time to 00:00:00.
     */
    Time();

    /**
     * @brief Parameterized constructor.
     *
     * @param h Hour value.
     * @param m Minute value.
     * @param s Second value.
     */
    Time(unsigned h, unsigned m, unsigned s);

    /**
     * @brief Returns the hour.
     * @return Hour value.
     */
    unsigned GetHour() const;

    /**
     * @brief Sets the hour.
     * @param h Hour value.
     */
    void SetHour(unsigned h);

    /**
     * @brief Returns the minute.
     * @return Minute value.
     */
    unsigned GetMinute() const;

    /**
     * @brief Sets the minute.
     * @param m Minute value.
     */
    void SetMinute(unsigned m);

    /**
     * @brief Returns the second.
     * @return Second value.
     */
    unsigned GetSecond() const;

    /**
     * @brief Sets the second.
     * @param s Second value.
     */
    void SetSecond(unsigned s);

private:
    unsigned hour;
    unsigned minute;
    unsigned second;
};

#endif
