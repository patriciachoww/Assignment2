/**
 * @file WeatherFormat.cpp
 * @brief Helper functions for parsing and validating weather data.
 *
 * This file contains utility routines for splitting the WAST field
 * into separate Date and Time objects, and for checking whether a
 * string can be treated as a valid numeric value.
 *
 * @author Patricia
 */

#include "WeatherFormat.h"

void ParseWAST(const std::string& wast, const IDateTimeParser& parser,
               Date& date, Time& time)
{
    // Locate the space that separates date and time
    size_t spacePos = wast.find(' ');

    if (spacePos != std::string::npos)
    {
        std::string dateStr = wast.substr(0, spacePos);
        std::string timeStr = wast.substr(spacePos + 1);

        date = parser.ParseDate(dateStr);
        time = parser.ParseTime(timeStr);
    }
}

bool IsValidNumber(const std::string& str)
{
    // Empty string is not a valid number
    if (str.empty())
        return false;

    // Reject common non-numeric placeholders
    if (str == "N/A" || str == "n/a" || str == "-")
        return false;

    // Try converting the string to a floating-point value
    try
    {
        size_t pos;
        std::stof(str, &pos);

        // Valid only if the whole string was consumed
        return pos == str.length();
    }
    catch (...)
    {
        return false;
    }
}
