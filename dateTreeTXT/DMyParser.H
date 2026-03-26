/**
 * @file DMYParser.h
 * @brief Declaration of parser for DD/MM/YYYY date format.
 *
 * Provides functions to parse date and time strings using
 * the day/month/year format.
 *
 * @author Patricia
 */

#ifndef DMYPARSER_H
#define DMYPARSER_H

#include "IDateTimeParser.h"

/**
 * @class DMYParser
 * @brief Parses dates in DD/MM/YYYY format and times in H:MM format.
 *
 * Implements IDateTimeParser to convert string values into
 * Date and Time objects.
 */
class DMYParser : public IDateTimeParser
{
public:
    /**
     * @brief Parses a date string.
     *
     * @param dateStr Input date string (e.g., "31/03/2016").
     * @return Parsed Date object.
     */
    Date ParseDate(const std::string& dateStr) const override;

    /**
     * @brief Parses a time string.
     *
     * @param timeStr Input time string (e.g., "9:30" or "14:45").
     * @return Parsed Time object.
     */
    Time ParseTime(const std::string& timeStr) const override;
};

#endif
