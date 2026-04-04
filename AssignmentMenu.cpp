/**
 * @file AssignmentMenu.cpp
 * @brief Implementation of Assignment 2 menu functions.
 *
 * Handles user interaction for all menu options.
 *
 * @author Patricia
 * @date 31/03/2026
 */

#include "AssignmentMenu.h"
#include "Statistics.h"
#include "WeatherDataStore.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <limits>

namespace
{
    WeatherDataStore g_data;

    const char* MONTH_NAMES[12] =
    {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    /**
     * @brief Read a valid integer from user input.
     * @param prompt Prompt text
     * @param value Output integer
     * @return True if input is valid
     */
    bool ReadInt(const char* prompt, int& value)
    {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input." << std::endl;
            return false;
        }

        return true;
    }
}

/**
 * @brief Display the assignment menu.
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
 * @brief Handle option 1.
 */
void Option1()
{
    int month;
    int year;

    if (!ReadInt("Enter month (1-12): ", month))
    {
        return;
    }

    if (!ReadInt("Enter year: ", year))
    {
        return;
    }

    if (month < 1 || month > 12)
    {
        std::cout << "Invalid month." << std::endl;
        return;
    }

    Vector<double> speeds = g_data.GetSpeedsForMonthYear(month, year);

    if (speeds.Size() == 0)
    {
        std::cout << MONTH_NAMES[month - 1] << " " << year << ": No Data" << std::endl;
        return;
    }

    std::cout << MONTH_NAMES[month - 1] << " " << year << std::endl;
    std::cout << "Average speed: " << Mean(speeds) << " km/h" << std::endl;
    std::cout << "Sample stdev: " << SampleStdev(speeds) << std::endl;
}

/**
 * @brief Handle option 2.
 */
void Option2()
{
    int year;

    if (!ReadInt("Enter year: ", year))
    {
        return;
    }

    std::cout << year << std::endl;

    for (int month = 1; month <= 12; month++)
    {
        Vector<double> temps = g_data.GetTempsForMonthYear(month, year);

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
 * @brief Handle option 3.
 */
void Option3()
{
    int month;

    if (!ReadInt("Enter month (1-12): ", month))
    {
        return;
    }

    if (month < 1 || month > 12)
    {
        std::cout << "Invalid month." << std::endl;
        return;
    }

    Vector<double> s = g_data.GetSpeedsForMonthAllYears(month);
    Vector<double> t = g_data.GetTempsForMonthAllYears(month);
    Vector<double> r = g_data.GetSolarForMonthAllYears(month);

    std::cout << "Sample Pearson Correlation Coefficient for "
              << MONTH_NAMES[month - 1] << std::endl;
    std::cout << "S_T: " << SPCC(s, t) << std::endl;
    std::cout << "S_R: " << SPCC(s, r) << std::endl;
    std::cout << "T_R: " << SPCC(t, r) << std::endl;
}

/**
 * @brief Handle option 4.
 */
void Option4()
{
    int year;

    if (!ReadInt("Enter year: ", year))
    {
        return;
    }

    std::ofstream outFile("WindTempSolar.csv");

    if (!outFile.is_open())
    {
        std::cout << "Error creating WindTempSolar.csv" << std::endl;
        return;
    }

    outFile << year << std::endl;

    bool hasAnyData = false;

    for (int month = 1; month <= 12; month++)
    {
        Vector<double> speeds = g_data.GetSpeedsForMonthYear(month, year);
        Vector<double> temps = g_data.GetTempsForMonthYear(month, year);
        Vector<double> solar = g_data.GetSolarForMonthYear(month, year);

        if (speeds.Size() == 0 && temps.Size() == 0 && solar.Size() == 0)
        {
            continue;
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

    outFile.close();

    std::cout << "WindTempSolar.csv written successfully." << std::endl;
}

/**
 * @brief Handle option 5.
 */
void Option5()
{
    std::cout << "Exiting program." << std::endl;
}

/**
 * @brief Run the menu loop.
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
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input." << std::endl;
            continue;
        }

        switch (choice)
        {
            case 1:
                Option1();
                break;
            case 2:
                Option2();
                break;
            case 3:
                Option3();
                break;
            case 4:
                Option4();
                break;
            case 5:
                Option5();
                break;
            default:
                std::cout << "Invalid choice." << std::endl;
                break;
        }

    } while (choice != 5);
}
