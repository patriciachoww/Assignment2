/**
 * @file IDataSource.h
 * @brief Abstract interface for tabular data input sources.
 *
 * This interface defines the basic operations required for reading
 * structured row-and-column data from a source such as a CSV file.
 * Concrete classes implement these operations according to the
 * specific source format.
 *
 * @author Patricia
 */

#ifndef IDATASOURCE_H
#define IDATASOURCE_H

#include <string>

/**
 * @class IDataSource
 * @brief Common interface for reading tabular data.
 *
 * Classes derived from IDataSource provide a consistent way to
 * load files, move through rows, and retrieve field values,
 * regardless of the actual data source being used.
 */
class IDataSource
{
public:
    /**
     * @brief Virtual destructor.
     *
     * Ensures correct cleanup when deleting through a base class pointer.
     */
    virtual ~IDataSource() {}

    /**
     * @brief Opens and loads data from a file.
     *
     * @param filename Path of the file to load.
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
     * @param columnName Name of the column to search for.
     * @return true if the column exists, otherwise false.
     */
    virtual bool HasColumn(const std::string& columnName) const = 0;

    /**
     * @brief Returns the index of a named column.
     *
     * @param columnName Name of the column.
     * @return Column index, or -1 if not found.
     */
    virtual int GetColumnIndex(const std::string& columnName) const = 0;

    /**
     * @brief Returns the total number of columns.
     *
     * @return Number of columns in the data source.
     */
    virtual int GetColumnCount() const = 0;

    /**
     * @brief Reads the next row of data.
     *
     * @return true if a row is successfully read, otherwise false.
     */
    virtual bool ReadNextRow() = 0;

    /**
     * @brief Retrieves a field value by column name.
     *
     * @param columnName Name of the required column.
     * @return Field value as a string, or empty string if unavailable.
     */
    virtual std::string GetField(const std::string& columnName) const = 0;

    /**
     * @brief Retrieves a field value by column index.
     *
     * @param index Position of the column.
     * @return Field value as a string, or empty string if index is invalid.
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
