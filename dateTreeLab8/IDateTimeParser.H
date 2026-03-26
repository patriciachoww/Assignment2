/**
 * @file IDateTimeParser.h
 * @brief Interface for parsing date and time strings.
 *
 * This interface defines methods for converting date and time
 * strings into Date and Time objects. Different formats can be
 * supported by implementing this interface in separate classes.
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
 * @brief Abstract base class for date/time parsing.
 *
 * Provides a common interface for handling different date
 * and time formats. Concrete parser classes (e.g. DMYParser)
 * implement these methods for specific formats.
 */
class IDateTimeParser
{
public:
    /**
     * @brief Virtual destructor.
     *
     * Ensures proper cleanup when deleting through a base pointer.
     */
    virtual ~IDateTimeParser() {}

    /**
     * @brief Converts a date string into a Date object.
     *
     * @param dateStr Input date string.
     * @return Parsed Date value.
     */
    virtual Date ParseDate(const std::string& dateStr) const = 0;

    /**
     * @brief Converts a time string into a Time object.
     *
     * @param timeStr Input time string.
     * @return Parsed Time value.
     */
    virtual Time ParseTime(const std::string& timeStr) const = 0;
};

#endif
