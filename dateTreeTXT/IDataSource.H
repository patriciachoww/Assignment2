/**
 * @file IDataSource.h
 * @brief Interface for tabular data sources.
 *
 * Defines the basic operations required to read structured
 * row-and-column data from a source such as a CSV file.
 *
 * @author Patricia
 */

#ifndef IDATASOURCE_H
#define IDATASOURCE_H

#include <string>

/**
 * @class IDataSource
 * @brief Abstract base class for tabular data input.
 *
 * Provides a common interface for loading data, reading rows,
 * and accessing fields by column name or index.
 */
class IDataSource
{
public:
    /**
     * @brief Virtual destructor.
     */
    virtual ~IDataSource() {}

    /**
     * @brief Loads data from a file.
     *
     * @param filename Path to the file.
     * @return true if loading succeeds, otherwise false.
     */
    virtual bool LoadFile(const std::string& filename) = 0;

    /**
     * @brief Closes the current data source.
     */
    virtual void CloseFile() = 0;

    /**
     * @brief Checks whether a column exists.
     *
     * @param columnName Name of the column.
     * @return true if found, otherwise false.
     */
    virtual bool HasColumn(const std::string& columnName) const = 0;

    /**
     * @brief Returns the index of a column.
     *
     * @param columnName Name of the column.
     * @return Column index, or -1 if not found.
     */
    virtual int GetColumnIndex(const std::string& columnName) const = 0;

    /**
     * @brief Returns the number of columns.
     *
     * @return Total number of columns.
     */
    virtual int GetColumnCount() const = 0;

    /**
     * @brief Reads the next row of data.
     *
     * @return true if a row was read, otherwise false.
     */
    virtual bool ReadNextRow() = 0;

    /**
     * @brief Returns a field value by column name.
     *
     * @param columnName Name of the column.
     * @return Field value as a string.
     */
    virtual std::string GetField(const std::string& columnName) const = 0;

    /**
     * @brief Returns a field value by column index.
     *
     * @param index Column index.
     * @return Field value as a string.
     */
    virtual std::string GetFieldByIndex(int index) const = 0;

    /**
     * @brief Returns the current row number.
     *
     * @return Current row number, excluding the header row.
     */
    virtual int GetCurrentRowNumber() const = 0;
};

#endif
