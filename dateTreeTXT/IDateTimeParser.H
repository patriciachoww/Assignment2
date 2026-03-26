/**
 * @file IDateTimeParser.h
 * @brief Interface for date and time parsing.
 *
 * Defines functions to convert string values into
 * Date and Time objects.
 *
 * @author Patricia
 */

#ifndef IDATETIMEPARSER_H
#define IDATETIMEPARSER_H

#include <string>
#include "Date.h"
#include "Time.h"

/**
 * @class IDateTimeParser
 * @brief Abstract base class for parsing date and time strings.
 *
 * Allows different date formats (e.g., DMY, YMD) to be implemented
 * without changing the rest of the program.
 */
class IDateTimeParser
{
public:
    /**
     * @brief Virtual destructor.
     */
    virtual ~IDateTimeParser() {}

    /**
     * @brief Parses a date string.
     *
     * @param dateStr Input date string.
     * @return Parsed Date object.
     */
    virtual Date ParseDate(const std::string& dateStr) const = 0;

    /**
     * @brief Parses a time string.
     *
     * @param timeStr Input time string.
     * @return Parsed Time object.
     */
    virtual Time ParseTime(const std::string& timeStr) const = 0;
};

#endif
