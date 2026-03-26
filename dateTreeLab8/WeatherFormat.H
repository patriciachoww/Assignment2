/**
 * @file WeatherFormat.h
 * @brief Helper functions for parsing weather data fields.
 *
 * Provides utility functions for extracting date and time
 * from combined strings, as well as validating numeric values.
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
 * @brief Parses a WAST string into Date and Time.
 *
 * Splits the input string using a space separator and
 * uses the provided parser to extract date and time values.
 *
 * Expected format: "DD/MM/YYYY H:MM" or "DD/MM/YYYY HH:MM"
 *
 * @param wast Input string containing date and time.
 * @param parser Parser used to interpret the values.
 * @param[out] date Output Date object.
 * @param[out] time Output Time object.
 */
void ParseWAST(const std::string& wast, const IDateTimeParser& parser,
               Date& date, Time& time);

/**
 * @brief Checks whether a string represents a valid number.
 *
 * Returns false for empty strings, "N/A", or invalid numeric values.
 *
 * @param str Input string.
 * @return true if valid number, otherwise false.
 */
bool IsValidNumber(const std::string& str);

#endif
