/**
 * @file CsvParser.cpp
 * @brief Implementation file for CSV parsing functions.
 *
 * This class is responsible for opening a CSV file, reading its header,
 * storing column information, and retrieving row data field by field.
 *
 * @author Patricia
 */

#include "CsvParser.h"
#include <sstream>

CsvParser::CsvParser()
    : file(), columnMap(20), columnNames(20), currentRow(20), rowNumber(0)
{
    // Constructor initializes internal containers and row counter
}

CsvParser::~CsvParser()
{
    // Ensure file is properly closed when object is destroyed
    CloseFile();
}

bool CsvParser::LoadFile(const std::string& filename)
{
    // If another file is already open, close it first
    if (file.is_open())
    {
        file.close();
    }

    // Attempt to open the new CSV file
    file.open(filename.c_str());
    if (!file.is_open())
    {
        return false;
    }

    // Read the first line as the header row
    std::string headerLine;
    if (!std::getline(file, headerLine))
    {
        file.close();
        return false;
    }

    // Reset stored header and mapping information
    columnNames.Clear();
    columnMap.Clear();

    // Break header line into separate column names
    SplitLine(headerLine, columnNames);

    // Store each column name together with its index position
    for (int i = 0; i < columnNames.Size(); i++)
    {
        columnMap.Set(columnNames[i], i);
    }

    // Reset row tracking for new file
    rowNumber = 0;
    currentRow.Clear();

    return true;
}

void CsvParser::CloseFile()
{
    // Close file if it is currently open
    if (file.is_open())
    {
        file.close();
    }

    // Clear all stored parsing data
    columnMap.Clear();
    columnNames.Clear();
    currentRow.Clear();
    rowNumber = 0;
}

bool CsvParser::HasColumn(const std::string& columnName) const
{
    // Check whether the requested column exists
    return columnMap.HasKey(columnName);
}

int CsvParser::GetColumnIndex(const std::string& columnName) const
{
    // Return -1 if the column name is not found
    if (!columnMap.HasKey(columnName))
    {
        return -1;
    }

    return columnMap.Get(columnName);
}

bool CsvParser::ReadNextRow()
{
    std::string line;

    // Stop if no more rows can be read
    if (!std::getline(file, line))
    {
        return false;
    }

    // Ignore blank lines and continue reading
    std::string cleanedLine = Trim(line);
    if (cleanedLine.empty())
    {
        return ReadNextRow();
    }

    // Store fields from the current row
    currentRow.Clear();
    SplitLine(line, currentRow);
    rowNumber++;

    return true;
}

std::string CsvParser::GetField(const std::string& columnName) const
{
    // Find the column index first, then return the matching field
    int index = GetColumnIndex(columnName);
    if (index < 0)
    {
        return "";
    }

    return GetFieldByIndex(index);
}

std::string CsvParser::GetFieldByIndex(int index) const
{
    // Return empty string if index is out of range
    if (index < 0 || index >= currentRow.Size())
    {
        return "";
    }

    return currentRow[index];
}

int CsvParser::GetColumnCount() const
{
    // Return number of columns detected from header
    return columnNames.Size();
}

int CsvParser::GetCurrentRowNumber() const
{
    // Return current data row number being processed
    return rowNumber;
}

void CsvParser::SplitLine(const std::string& line, Vector<std::string>& result) const
{
    // Separate a line into fields using comma as delimiter
    result.Clear();

    std::stringstream stream(line);
    std::string field;

    while (std::getline(stream, field, ','))
    {
        result.push_back(Trim(field));
    }
}

std::string CsvParser::Trim(const std::string& str) const
{
    // Locate first non-space character
    size_t start = 0;
    while (start < str.length() &&
           (str[start] == ' ' || str[start] == '\t' ||
            str[start] == '\r' || str[start] == '\n'))
    {
        start++;
    }

    // Locate last non-space character
    size_t end = str.length();
    while (end > start &&
           (str[end - 1] == ' ' || str[end - 1] == '\t' ||
            str[end - 1] == '\r' || str[end - 1] == '\n'))
    {
        end--;
    }

    // Return trimmed substring
    return str.substr(start, end - start);
}
