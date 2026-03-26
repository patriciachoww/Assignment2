/**
 * @file DMYParser.cpp
 * @brief Implementation of parser for DD/MM/YYYY date format.
 *
 * Provides functions to convert date and time strings
 * into Date and Time objects.
 *
 * @author Patricia
 */

#include "DMYParser.h"
#include <cstdlib>

// --- Parse Date ---

Date DMYParser::ParseDate(const std::string& dateStr) const
{
    Date d;

    // Locate '/' separators in the date string
    size_t pos1 = dateStr.find('/');
    size_t pos2 = dateStr.find('/', pos1 + 1);

    if (pos1 != std::string::npos && pos2 != std::string::npos)
    {
        unsigned day = static_cast<unsigned>(std::stoul(dateStr.substr(0, pos1)));
        unsigned month = static_cast<unsigned>(
            std::stoul(dateStr.substr(pos1 + 1, pos2 - pos1 - 1)));
        unsigned year = static_cast<unsigned>(std::stoul(dateStr.substr(pos2 + 1)));

        d.SetDay(day);
        d.SetMonth(month);
        d.SetYear(year);
    }

    return d;
}

// --- Parse Time ---

Time DMYParser::ParseTime(const std::string& timeStr) const
{
    Time t;

    // Locate ':' separator in the time string
    size_t pos = timeStr.find(':');

    if (pos != std::string::npos)
    {
        unsigned hour = static_cast<unsigned>(std::stoul(timeStr.substr(0, pos)));
        unsigned minute = static_cast<unsigned>(std::stoul(timeStr.substr(pos + 1)));

        t.SetHour(hour);
        t.SetMinute(minute);
        t.SetSecond(0); // Default seconds to 0
    }

    return t;
}
