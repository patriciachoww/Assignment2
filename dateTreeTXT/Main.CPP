/**
 * @file main.cpp
 * @brief Demo program for BST using dates from date.txt.
 *
 * Reads date values from data/date.txt, inserts them into
 * a Bst<Date>, and demonstrates BST operations.
 *
 * @author Patricia
 * @date 25/03/2026
 */

#include "../Bst.h"
#include "Date.h"
#include "DMYParser.h"
#include "WeatherFormat.h"
#include <fstream>
#include <iostream>
#include <string>

const std::string DATE_FILE = "data/date.txt"; // input file

int main()
{
    // open file
    std::ifstream inFile(DATE_FILE.c_str());

    // check file
    if (!inFile.is_open())
    {
        std::cerr << "Error: Could not open " << DATE_FILE << std::endl;
        return 1;
    }

    DMYParser parser;    // date parser
    Bst<Date> dateTree;  // date BST

    std::string line;
    int count = 0;

    // read file line by line
    while (std::getline(inFile, line))
    {
        // trim trailing spaces
        while (!line.empty() &&
               (line[line.size() - 1] == ' '  ||
                line[line.size() - 1] == '\t' ||
                line[line.size() - 1] == '\r' ||
                line[line.size() - 1] == '\n'))
        {
            line.erase(line.size() - 1);
        }

        // skip empty line
        if (line.empty())
            continue;

        Date date;
        Time time;

        // parse date and time
        ParseWAST(line, parser, date, time);

        // insert valid date
        if (date.GetYear() != 0)
        {
            dateTree.Insert(date);
            count++;
        }
    }

    inFile.close(); // close file

    std::cout << "=== Date BST from date.txt ===" << std::endl;
    std::cout << count << " dates read from " << DATE_FILE << std::endl;
    std::cout << std::endl;

    // check BST
    std::cout << "BST valid: "
              << (dateTree.CheckBST() ? "Yes" : "No") << std::endl;
    std::cout << std::endl;

    // traversals
    std::cout << "InOrder traversal:" << std::endl;
    dateTree.InOrder();

    std::cout << std::endl;
    std::cout << "PreOrder traversal:" << std::endl;
    dateTree.PreOrder();

    std::cout << std::endl;
    std::cout << "PostOrder traversal:" << std::endl;
    dateTree.PostOrder();

    // search tests
    std::cout << std::endl;

    Date searchDate(12, 9, 2017); // existing date
    std::cout << "Search for 12/9/2017: "
              << (dateTree.Search(searchDate) ? "Found" : "Not found")
              << std::endl;

    Date missingDate(1, 1, 2000); // missing date
    std::cout << "Search for 1/1/2000: "
              << (dateTree.Search(missingDate) ? "Found" : "Not found")
              << std::endl;

    // duplicate test
    std::cout << std::endl;
    std::cout << "Insert duplicate 12/9/2017" << std::endl;
    dateTree.Insert(Date(12, 9, 2017));

    std::cout << "InOrder after duplicate insert:" << std::endl;
    dateTree.InOrder();

    std::cout << "BST valid: "
              << (dateTree.CheckBST() ? "Yes" : "No") << std::endl;

    return 0;
}
