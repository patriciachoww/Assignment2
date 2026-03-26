/**
 * @file DataSourceFactory.cpp
 * @brief Factory implementation for creating data source objects.
 *
 * This factory class returns different types of data source handlers
 * based on the specified source type. Currently supports CSV files.
 * Additional formats can be added later if needed.
 *
 * @author Patricia
 */

#include "DataSourceFactory.h"
#include "CsvParser.h"

IDataSource* DataSourceFactory::Create(SourceType type)
{
    // Select appropriate data source based on type
    switch (type)
    {
        case CSV:
            // Create and return a CSV parser object
            return new CsvParser();

        // Placeholder for future extensions:
        // case JSON:
        //     return new JsonParser();

        default:
            // Return null if type is not recognised
            return nullptr;
    }
}
