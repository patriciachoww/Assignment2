/**
 * @file WeatherFormat.h
 * @brief Helper functions for weather data parsing.
 *
 * Provides utility functions for splitting combined
 * date/time strings and checking numeric values.
 *
 * @author Patricia
 */

#ifndef WEATHERFORMAT_H
#define WEATHERFORMAT_H

#include <string>
#include "Date.h"
#include "Time.h"
#include "IDateTimeParser.h"

/**
 * @brief Parses a WAST string into Date and Time objects.
 *
 * Expected format: "DD/MM/YYYY H:MM" or "DD/MM/YYYY HH:MM"
 *
 * @param wast Input date/time string.
 * @param parser Parser used to read the values.
 * @param date Output Date object.
 * @param time Output Time object.
 */
void ParseWAST(const std::string& wast, const IDateTimeParser& parser,
               Date& date, Time& time);

/**
 * @brief Checks whether a string is a valid number.
 *
 * @param str Input string.
 * @return true if the string is numeric, otherwise false.
 */
bool IsValidNumber(const std::string& str);

#endif
