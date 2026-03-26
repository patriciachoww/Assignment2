/**
 * @file DMYParser.cpp
 * @brief Implementation of parser for DD/MM/YYYY date format.
 *
 * This parser converts date and time strings into Date and Time
 * objects. It currently supports dates in day/month/year format
 * and times in hour:minute format.
 *
 * @author Patricia
 */

#include "DMYParser.h"
#include <cstdlib>

Date DMYParser::ParseDate(const std::string& dateStr) const
{
    Date d;

    // Locate the two '/' separators in the date string
    size_t firstSlash = dateStr.find('/');
    size_t secondSlash = dateStr.find('/', firstSlash + 1);

    if (firstSlash != std::string::npos && secondSlash != std::string::npos)
    {
        unsigned day = static_cast<unsigned>(std::stoul(dateStr.substr(0, firstSlash)));
        unsigned month = static_cast<unsigned>(
            std::stoul(dateStr.substr(firstSlash + 1, secondSlash - firstSlash - 1)));
        unsigned year = static_cast<unsigned>(std::stoul(dateStr.substr(secondSlash + 1)));

        d.SetDay(day);
        d.SetMonth(month);
        d.SetYear(year);
    }

    return d;
}

Time DMYParser::ParseTime(const std::string& timeStr) const
{
    Time t;

    // Locate ':' separator in the time string
    size_t colonPos = timeStr.find(':');

    if (colonPos != std::string::npos)
    {
        unsigned hour = static_cast<unsigned>(std::stoul(timeStr.substr(0, colonPos)));
        unsigned minute = static_cast<unsigned>(std::stoul(timeStr.substr(colonPos + 1)));

        t.SetHour(hour);
        t.SetMinute(minute);
        t.SetSecond(0);   // seconds default to zero
    }

    return t;
}
