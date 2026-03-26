/**
 * @file CsvParser.h
 * @brief Header file for CSV parsing support.
 *
 * This class provides basic CSV file handling with automatic
 * detection of column positions from the header row. It allows
 * fields to be accessed by column name instead of fixed index,
 * making it easier to work with files that may have different
 * column arrangements.
 *
 * @author Patricia
 */

#ifndef CSVPARSER_H
#define CSVPARSER_H

#include <string>
#include <fstream>
#include "IDataSource.h"
#include "Vector.h"
#include "Map.h"

/**
 * @class CsvParser
 * @brief Reads and processes CSV files using header-based column lookup.
 *
 * The parser reads the first row of a CSV file as the header and stores
 * the relationship between column names and their positions. Each
 * subsequent row can then be accessed by column name or column index.
 */
class CsvParser : public IDataSource
{
public:
    /**
     * @brief Default constructor.
     *
     * Creates an empty parser object. A file must be loaded
     * later by calling LoadFile().
     */
    CsvParser();

    /**
     * @brief Destructor.
     *
     * Ensures any open file is properly closed.
     */
    ~CsvParser() override;

    /**
     * @brief Opens and prepares a CSV file for reading.
     *
     * The header row is read first so column names can be mapped
     * to their corresponding positions.
     *
     * @param filename Name or path of the CSV file.
     * @return true if the file was opened successfully, otherwise false.
     */
    bool LoadFile(const std::string& filename);

    /**
     * @brief Closes the current file and clears stored data.
     */
    void CloseFile();

    /**
     * @brief Checks whether a given column name exists.
     *
     * @param columnName Name of the column to search for.
     * @return true if the column is present, otherwise false.
     */
    bool HasColumn(const std::string& columnName) const;

    /**
     * @brief Returns the index of a named column.
     *
     * @param columnName Name of the column.
     * @return Column index, or -1 if the column does not exist.
     */
    int GetColumnIndex(const std::string& columnName) const;

    /**
     * @brief Reads the next row of data from the CSV file.
     *
     * The row is split into individual fields and stored internally.
     *
     * @return true if a row was successfully read, otherwise false.
     */
    bool ReadNextRow();

    /**
     * @brief Gets a field from the current row using a column name.
     *
     * @param columnName Name of the required column.
     * @return Field value as a string, or an empty string if unavailable.
     */
    std::string GetField(const std::string& columnName) const;

    /**
     * @brief Gets a field from the current row using its column index.
     *
     * @param index Index of the required field.
     * @return Field value as a string, or an empty string if index is invalid.
     */
    std::string GetFieldByIndex(int index) const;

    /**
     * @brief Returns the total number of columns.
     *
     * @return Number of columns detected in the header row.
     */
    int GetColumnCount() const;

    /**
     * @brief Returns the current data row number.
     *
     * Row counting starts after the header row.
     *
     * @return Current row number.
     */
    int GetCurrentRowNumber() const;

private:
    std::ifstream file;               ///< File stream used for input
    Map<std::string, int> columnMap;  ///< Maps column names to positions
    Vector<std::string> columnNames;  ///< Stores header names in order
    Vector<std::string> currentRow;   ///< Stores fields from current row
    int rowNumber;                    ///< Tracks current row number

    /**
     * @brief Splits one CSV line into separate fields.
     *
     * Whitespace around each field is removed before storing.
     *
     * @param line Input line from the CSV file.
     * @param result Vector used to store extracted fields.
     */
    void SplitLine(const std::string& line, Vector<std::string>& result) const;

    /**
     * @brief Removes leading and trailing whitespace from a string.
     *
     * @param str String to be trimmed.
     * @return Trimmed version of the string.
     */
    std::string Trim(const std::string& str) const;
};

#endif
