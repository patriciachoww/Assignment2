/**
 * @file DMYParser.h
 * @brief Declaration of parser for DD/MM/YYYY date format.
 *
 * This class implements the IDateTimeParser interface and is used
 * to convert date strings in day/month/year format and time strings
 * in hour:minute format into Date and Time objects.
 *
 * @author Patricia
 */

#ifndef DMYPARSER_H
#define DMYPARSER_H

#include "IDateTimeParser.h"

/**
 * @class DMYParser
 * @brief Parser for day-month-year date strings.
 *
 * This parser handles dates written in DD/MM/YYYY format and
 * times written in H:MM or HH:MM format.
 */
class DMYParser : public IDateTimeParser
{
public:
    /**
     * @brief Converts a date string into a Date object.
     *
     * @param dateStr Date in DD/MM/YYYY format.
     * @return Parsed Date value.
     */
    Date ParseDate(const std::string& dateStr) const override;

    /**
     * @brief Converts a time string into a Time object.
     *
     * @param timeStr Time in H:MM or HH:MM format.
     * @return Parsed Time value.
     */
    Time ParseTime(const std::string& timeStr) const override;
};

#endif
