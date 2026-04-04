/**
 * @file WeatherRecord.h
 * @brief Stores weather data for one observation.
 *
 * Represents a simplified weather reading used by the
 * Assignment 2 menu options.
 *
 * @author Patricia
 * @date 31/03/2026
 */

#ifndef WEATHER_RECORD_H
#define WEATHER_RECORD_H

#include "../dateTreeLab8/Date.H"

/**
 * @class WeatherRecord
 * @brief One weather observation.
 *
 * Stores date plus values required by the assignment.
 */
class WeatherRecord
{
public:
    /**
     * @brief Default constructor.
     */
    WeatherRecord();

    /**
     * @brief Parameterized constructor.
     * @param d Observation date
     * @param speed Wind speed in km/h
     * @param temp Ambient temperature
     * @param solar Solar radiation
     */
    WeatherRecord(const Date& d, double speed, double temp, double solar);

    /**
     * @brief Get observation date.
     * @return Date of record
     */
    Date GetDate() const;

    /**
     * @brief Get wind speed.
     * @return Wind speed
     */
    double GetSpeed() const;

    /**
     * @brief Get temperature.
     * @return Temperature
     */
    double GetTemperature() const;

    /**
     * @brief Get solar radiation.
     * @return Solar radiation
     */
    double GetSolar() const;

    /**
     * @brief Compare if this record is less than another.
     * @param other Other weather record
     * @return True if this record date is earlier
     */
    bool operator<(const WeatherRecord& other) const;

    /**
     * @brief Compare if this record is greater than another.
     * @param other Other weather record
     * @return True if this record date is later
     */
    bool operator>(const WeatherRecord& other) const;

    /**
     * @brief Compare if this record is equal to another.
     * @param other Other weather record
     * @return True if both record dates are equal
     */
    bool operator==(const WeatherRecord& other) const;

private:
    Date date;        ///< Observation date
    double speed;     ///< Wind speed
    double temp;      ///< Ambient temperature
    double solar;     ///< Solar radiation
};

#endif
