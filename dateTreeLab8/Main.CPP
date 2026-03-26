/**
 * @file main.cpp
 * @brief Demonstration program for BST using Date objects.
 *
 * This program reads all CSV filenames listed in data/data_source.txt,
 * extracts the date portion from the WAST column in each file, and
 * inserts those dates into a Bst<Date>. The program then demonstrates
 * traversal, searching, and BST validation using the resulting tree.
 *
 * Supporting classes from earlier work, such as CsvParser and DMYParser,
 * are used to read and interpret the input data.
 *
 * @author Patricia
 */

#include "../Bst.h"
#include "Date.h"
#include "DMYParser.h"
#include "WeatherFormat.h"
#include "CsvParser.h"
#include "Vector.h"
#include <iostream>
#include <fstream>
#include <string>

// Name of the column that stores date/time information
const std::string DATETIME_COLUMN = "WAST";

// File containing the list of CSV source files
const std::string DATA_SOURCE_FILE = "data/data_source.txt";

/**
 * @brief Removes whitespace characters from the end of a string.
 * @param str String to be modified.
 */
static void TrimTrailing(std::string& str)
{
    while (!str.empty() &&
           (str[str.size() - 1] == ' '  ||
            str[str.size() - 1] == '\t' ||
            str[str.size() - 1] == '\r' ||
            str[str.size() - 1] == '\n'))
    {
        str.erase(str.size() - 1);
    }
}

/**
 * @brief Reads all listed CSV filenames from the data source file.
 * @param filenames Vector used to store the filenames read.
 * @return true if at least one filename is loaded, otherwise false.
 */
static bool ReadAllDataFiles(Vector<std::string>& filenames)
{
    std::ifstream sourceFile(DATA_SOURCE_FILE.c_str());
    if (!sourceFile.is_open())
        return false;

    std::string line;
    while (std::getline(sourceFile, line))
    {
        TrimTrailing(line);
        if (!line.empty())
            filenames.push_back(line);
    }

    return filenames.Size() > 0;
}

// Forward declaration of stream output operator for Date.
// This is only needed in this program for printing date values.
std::ostream& operator<<(std::ostream& os, const Date& d);

/**
 * @brief Outputs a Date object in DD/MM/YYYY format.
 * @param os Output stream.
 * @param d  Date object to display.
 * @return Reference to the output stream.
 */
std::ostream& operator<<(std::ostream& os, const Date& d)
{
    os << d.GetDay() << "/" << d.GetMonth() << "/" << d.GetYear();
    return os;
}

int main()
{
    // Read all filenames from data_source.txt
    Vector<std::string> dataFiles(10);
    if (!ReadAllDataFiles(dataFiles))
    {
        std::cerr << "Error: Unable to read file list from "
                  << DATA_SOURCE_FILE << std::endl;
        return 1;
    }

    // Create parser used for WAST date conversion
    DMYParser parser;

    // Create BST and CSV parser
    Bst<Date> dateTree;
    CsvParser csvParser;

    // Process each file listed in the data source file
    for (int i = 0; i < dataFiles.Size(); i++)
    {
        std::string filepath = "data/" + dataFiles[i];

        if (!csvParser.LoadFile(filepath))
        {
            std::cerr << "Warning: Failed to open " << filepath << std::endl;
            continue;
        }

        if (!csvParser.HasColumn(DATETIME_COLUMN))
        {
            std::cerr << "Warning: Missing WAST column in "
                      << filepath << std::endl;
            csvParser.CloseFile();
            continue;
        }

        int rowCount = 0;
        while (csvParser.ReadNextRow())
        {
            std::string wastStr = csvParser.GetField(DATETIME_COLUMN);

            Date date;
            Time time;
            ParseWAST(wastStr, parser, date, time);

            // Insert only valid dates into the BST
            if (date.GetYear() != 0)
            {
                dateTree.Insert(date);
                rowCount++;
            }
        }

        csvParser.CloseFile();

        std::cout << "Processed file: " << dataFiles[i]
                  << " (" << rowCount << " valid rows)" << std::endl;
    }

    std::cout << std::endl;

    // Check whether BST structure is still valid
    dateTree.CheckBST();
    std::cout << std::endl;

    // Display tree traversals
    std::cout << "InOrder traversal (ascending dates):" << std::endl;
    dateTree.InOrder();

    std::cout << std::endl;
    std::cout << "PreOrder traversal:" << std::endl;
    dateTree.PreOrder();

    std::cout << std::endl;
    std::cout << "PostOrder traversal:" << std::endl;
    dateTree.PostOrder();

    // Search examples
    std::cout << std::endl;

    Date searchDate(1, 3, 2015);
    std::cout << "Searching for 1/3/2015: "
              << (dateTree.Search(searchDate) ? "Found" : "Not found")
              << std::endl;

    Date missingDate(1, 1, 2000);
    std::cout << "Searching for 1/1/2000: "
              << (dateTree.Search(missingDate) ? "Found" : "Not found")
              << std::endl;

    return 0;
}
