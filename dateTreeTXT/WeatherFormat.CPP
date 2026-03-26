/**
 * @file WeatherFormat.cpp
 * @brief Implementation of weather data parsing utilities.
 *
 * Provides helper functions to extract date and time from
 * combined strings and to validate numeric values.
 *
 * @author Patricia
 */

#include "WeatherFormat.h"

// --- Parse WAST field ---

void ParseWAST(const std::string& wast, const IDateTimeParser& parser,
               Date& date, Time& time)
{
    // Locate space separating date and time
    size_t spacePos = wast.find(' ');

    if (spacePos != std::string::npos)
    {
        std::string dateStr = wast.substr(0, spacePos);
        std::string timeStr = wast.substr(spacePos + 1);

        date = parser.ParseDate(dateStr);
        time = parser.ParseTime(timeStr);
    }
}

// --- Validate numeric string ---

bool IsValidNumber(const std::string& str)
{
    if (str.empty())
        return false;

    // Handle non-numeric placeholders
    if (str == "N/A" || str == "n/a" || str == "-")
        return false;

    // Attempt to convert string to float
    try
    {
        size_t pos;
        std::stof(str, &pos);

        // Ensure entire string is numeric
        return pos == str.length();
    }
    catch (...)
    {
        return false;
    }
}
