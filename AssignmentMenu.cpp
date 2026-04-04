/**
 * @file AssignmentMenu.cpp
 * @brief Implementation of Assignment 2 menu functions.
 *
 * Handles all user interaction and menu options
 * for weather data analysis.
 *
 * @author Patricia
 * @version 1.0
 * @date 04/04/2026
 */

#include "AssignmentMenu.h"
#include "Statistics.h"
#include "WeatherDataStore.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

namespace
{
    WeatherDataStore g_data;   // Global data store

    const char* MONTH_NAMES[12] =
    {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    /**
     * @brief Reads a valid integer input from user.
     *
     * Ensures input is valid and clears error state if needed.
     *
     * @param prompt - message displayed to user
     * @param value - variable to store input
     * @return bool - true if input is valid, false otherwise
     */
    bool ReadInt(const char* prompt, int& value)
    {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail())
        {
            std::cin.clear();   // Reset error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer
            std::cout << "Invalid input." << std::endl;
            return false;
        }

        return true;   // Valid input
    }
}

/**
 * @brief Displays the main menu options.
 */
void ShowMenu()
{
    std::cout << "\n===== Assignment 2 Menu =====" << std::endl;
    std::cout << "1. Average wind speed and sample stdev for a month/year" << std::endl;
    std::cout << "2. Average ambient temperature and sample stdev for each month of a year" << std::endl;
    std::cout << "3. Sample Pearson Correlation Coefficient (sPCC)" << std::endl;
    std::cout << "4. Wind/Temperature/Solar monthly output" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Enter choice: ";
}

/**
 * @brief Handles menu option 1.
 *
 * Calculates average wind speed and standard deviation
 * for a given month and year.
 */
void Option1()
{
    int month;
    int year;

    if (!ReadInt("Enter month (1-12): ", month)) return;
    if (!ReadInt("Enter year: ", year)) return;

    if (month < 1 || month > 12)
    {
        std::cout << "Invalid month." << std::endl;
        return;
    }

    Vector<double> speeds = g_data.GetSpeedsForMonthYear(month, year); // Retrieve speeds

    if (speeds.Size() == 0)
    {
        std::cout << MONTH_NAMES[month - 1] << " " << year << ": No Data" << std::endl;
        return;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << MONTH_NAMES[month - 1] << " " << year << std::endl;
    std::cout << "Average speed: " << Mean(speeds) << " km/h" << std::endl;
    std::cout << "Sample stdev: " << SampleStdev(speeds) << std::endl;
}

/**
 * @brief Handles menu option 2.
 *
 * Displays monthly temperature statistics for a given year.
 */
void Option2()
{
    int year;

    if (!ReadInt("Enter year: ", year)) return;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << year << std::endl;

    for (int month = 1; month <= 12; month++)
    {
        Vector<double> temps = g_data.GetTempsForMonthYear(month, year); // Get temperature data

        if (temps.Size() == 0)
        {
            std::cout << MONTH_NAMES[month - 1] << ": No Data" << std::endl;
        }
        else
        {
            std::cout << MONTH_NAMES[month - 1]
                      << ": average: " << Mean(temps)
                      << " degrees C, stdev: " << SampleStdev(temps)
                      << std::endl;
        }
    }
}

/**
 * @brief Handles menu option 3.
 *
 * Calculates correlation between wind, temperature,
 * and solar radiation for a given month.
 */
void Option3()
{
    int month;

    if (!ReadInt("Enter month (1-12): ", month)) return;

    if (month < 1 || month > 12)
    {
        std::cout << "Invalid month." << std::endl;
        return;
    }

    Vector<double> s = g_data.GetSpeedsForMonthAllYears(month); // Wind
    Vector<double> t = g_data.GetTempsForMonthAllYears(month);  // Temperature
    Vector<double> r = g_data.GetSolarForMonthAllYears(month);  // Solar

    double st = SPCC(s, t);
    double sr = SPCC(s, r);
    double tr = SPCC(t, r);

    if (std::fabs(st) < 1e-9) st = 0.0;
    if (std::fabs(sr) < 1e-9) sr = 0.0;
    if (std::fabs(tr) < 1e-9) tr = 0.0;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Sample Pearson Correlation Coefficient for "
              << MONTH_NAMES[month - 1] << std::endl;

    std::cout << "S_T: " << st << std::endl;
    std::cout << "S_R: " << sr << std::endl;
    std::cout << "T_R: " << tr << std::endl;
}

/**
 * @brief Handles menu option 4.
 *
 * Outputs monthly wind, temperature, and solar data
 * into a CSV file.
 */
void Option4()
{
    int year;

    if (!ReadInt("Enter year: ", year)) return;

    std::ofstream outFile("WindTempSolar.csv"); // Create output file

    if (!outFile.is_open())
    {
        std::cout << "Error creating WindTempSolar.csv" << std::endl;
        return;
    }

    outFile << std::fixed << std::setprecision(2);
    outFile << year << std::endl;

    bool hasAnyData = false; // Track if any data exists

    for (int month = 1; month <= 12; month++)
    {
        Vector<double> speeds = g_data.GetSpeedsForMonthYear(month, year);
        Vector<double> temps = g_data.GetTempsForMonthYear(month, year);
        Vector<double> solar = g_data.GetSolarForMonthYear(month, year);

        if (speeds.Size() == 0 && temps.Size() == 0 && solar.Size() == 0)
        {
            continue; // Skip empty months
        }

        hasAnyData = true;

        outFile << MONTH_NAMES[month - 1] << ",";

        if (speeds.Size() > 0)
        {
            outFile << Mean(speeds)
                    << "(" << SampleStdev(speeds)
                    << "," << MAD(speeds) << ")";
        }

        outFile << ",";

        if (temps.Size() > 0)
        {
            outFile << Mean(temps)
                    << "(" << SampleStdev(temps)
                    << "," << MAD(temps) << ")";
        }

        outFile << ",";

        if (solar.Size() > 0)
        {
            outFile << Total(solar);
        }

        outFile << std::endl;
    }

    if (!hasAnyData)
    {
        outFile << "No Data" << std::endl;
    }

    outFile.close(); // Close file

    std::cout << "WindTempSolar.csv written successfully." << std::endl;
}

/**
 * @brief Handles menu option 5.
 *
 * Displays exit message.
 */
void Option5()
{
    std::cout << "Exiting program." << std::endl;
}

/**
 * @brief Runs the main menu loop.
 *
 * Loads data and repeatedly displays menu until exit.
 */
void RunMenu()
{
    if (!g_data.LoadDataFiles("data/data_source.txt"))
    {
        std::cout << "Error loading data files." << std::endl;
        return;
    }

    int choice = 0;

    do
    {
        ShowMenu();
        std::cin >> choice;

        if (std::cin.fail())
        {
            std::cin.clear();   // Reset input state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input." << std::endl;
            continue;
        }

        switch (choice)
        {
            case 1: Option1(); break; // Wind stats
            case 2: Option2(); break; // Temperature stats
            case 3: Option3(); break; // Correlation
            case 4: Option4(); break; // CSV output
            case 5: Option5(); break; // Exit
            default:
                std::cout << "Invalid choice." << std::endl;
                break;
        }

    } while (choice != 5); // Loop until exit
}
