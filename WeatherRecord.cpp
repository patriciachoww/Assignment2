/**
 * @file WeatherRecord.cpp
 * @brief Implementation of WeatherRecord class.
 *
 * Stores one weather record with date and values.
 *
 * @author Patricia
 * @date 31/03/2026
 */

#include "WeatherRecord.h"

/**
 * @brief Default constructor.
 */
WeatherRecord::WeatherRecord()
    : date(), speed(0.0), temp(0.0), solar(0.0)
{
}

/**
 * @brief Parameterized constructor.
 * @param d Observation date
 * @param s Wind speed
 * @param t Temperature
 * @param sr Solar radiation
 */
WeatherRecord::WeatherRecord(const Date& d, double s, double t, double sr)
    : date(d), speed(s), temp(t), solar(sr)
{
}

/**
 * @brief Get date.
 * @return Record date
 */
Date WeatherRecord::GetDate() const
{
    return date;
}

/**
 * @brief Get wind speed.
 * @return Wind speed
 */
double WeatherRecord::GetSpeed() const
{
    return speed;
}

/**
 * @brief Get temperature.
 * @return Temperature
 */
double WeatherRecord::GetTemperature() const
{
    return temp;
}

/**
 * @brief Get solar radiation.
 * @return Solar radiation
 */
double WeatherRecord::GetSolar() const
{
    return solar;
}

/**
 * @brief Compare by date.
 * @param other Other record
 * @return True if this date is earlier
 */
bool WeatherRecord::operator<(const WeatherRecord& other) const
{
    return date < other.date;
}

/**
 * @brief Compare by date.
 * @param other Other record
 * @return True if this date is later
 */
bool WeatherRecord::operator>(const WeatherRecord& other) const
{
    return date > other.date;
}

/**
 * @brief Compare equality by date.
 * @param other Other record
 * @return True if dates are equal
 */
bool WeatherRecord::operator==(const WeatherRecord& other) const
{
    return date == other.date;
}
