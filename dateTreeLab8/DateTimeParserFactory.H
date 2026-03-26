/**
 * @file DateTimeParserFactory.h
 * @brief Factory interface for creating date/time parser objects.
 *
 * This factory provides a central place to create parser instances
 * based on different date formats. New formats can be supported by
 * extending this class without modifying existing code.
 *
 * @author Patricia
 */

#ifndef DATETIMEPARSERFACTORY_H
#define DATETIMEPARSERFACTORY_H

#include "IDateTimeParser.h"

/**
 * @class DateTimeParserFactory
 * @brief Responsible for generating date/time parser objects.
 *
 * Returns an appropriate parser depending on the requested
 * date format. This helps separate object creation from usage
 * and improves flexibility of the system.
 */
class DateTimeParserFactory
{
public:
    /**
     * @brief Supported date format types.
     */
    enum FormatType
    {
        DMY,    ///< Day-Month-Year format (e.g. 31/12/2025)
        YMD,    ///< Year-Month-Day format (e.g. 2025-12-31)
        MDY     ///< Month-Day-Year format (e.g. 12/31/2025)
    };

    /**
     * @brief Creates a parser based on the given format.
     *
     * @param format Selected date format type.
     * @return Pointer to a new IDateTimeParser object.
     *         Caller is responsible for deleting it.
     */
    static IDateTimeParser* Create(FormatType format);
};

#endif
