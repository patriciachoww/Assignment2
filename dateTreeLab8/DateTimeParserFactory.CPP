/**
 * @file DateTimeParserFactory.cpp
 * @brief Factory class for creating date/time parser objects.
 *
 * This factory returns the appropriate parser based on the
 * specified date format. Currently, only DMY format is supported.
 * Other formats can be added later without modifying existing code.
 *
 * @author Patricia
 */

#include "DateTimeParserFactory.h"
#include "DMYParser.h"

IDateTimeParser* DateTimeParserFactory::Create(FormatType format)
{
    // Determine which parser to create based on format type
    switch (format)
    {
        case DMY:
            // Create parser for Day-Month-Year format
            return new DMYParser();

        case YMD:
            // Placeholder for Year-Month-Day parser
            return nullptr;

        case MDY:
            // Placeholder for Month-Day-Year parser
            return nullptr;

        default:
            // Return null if format is unsupported
            return nullptr;
    }
}
