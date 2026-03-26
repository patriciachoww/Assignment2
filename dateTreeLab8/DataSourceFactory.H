/**
 * @file DataSourceFactory.h
 * @brief Factory interface for creating IDataSource objects.
 *
 * This class centralises the creation of different data source
 * implementations. New data source types can be added here
 * without modifying the rest of the program.
 *
 * @author Patricia
 */

#ifndef DATASOURCEFACTORY_H
#define DATASOURCEFACTORY_H

#include "IDataSource.h"
#include <string>

/**
 * @class DataSourceFactory
 * @brief Responsible for creating data source instances.
 *
 * The factory returns an appropriate IDataSource implementation
 * based on the requested type. This helps keep object creation
 * separate from usage and improves flexibility.
 */
class DataSourceFactory
{
public:
    /**
     * @brief Enumeration of supported data source types.
     */
    enum SourceType
    {
        CSV     ///< CSV file format
        // Additional types (e.g., JSON, XML) can be added later
    };

    /**
     * @brief Creates a data source object of the given type.
     *
     * @param type The selected data source type.
     * @return Pointer to a newly created IDataSource object.
     *         The caller is responsible for deleting it.
     */
    static IDataSource* Create(SourceType type);
};

#endif
