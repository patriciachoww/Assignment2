#include "AssignmentMenu.h"
#include "Statistics.h"
#include <iostream>
#include <limits>

/**
 * @brief Displays the assignment menu.
 */
void ShowMenu()
{
    std::cout << "\n===== Assignment 2 Menu =====" << std::endl;
    std::cout << "1. Load data" << std::endl;
    std::cout << "2. Display summary" << std::endl;
    std::cout << "3. Sample Pearson Correlation Coefficient (sPCC)" << std::endl;
    std::cout << "4. Wind/Temperature/Solar monthly output" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Enter choice: ";
}

/**
 * @brief Handles option 1.
 */
void Option1()
{
    // Placeholder for data loading logic
    std::cout << "Option 1 called." << std::endl;
}

/**
 * @brief Handles option 2.
 */
void Option2()
{
    // Placeholder for summary display logic
    std::cout << "Option 2 called." << std::endl;
}

/**
 * @brief Handles option 3 for sPCC.
 */
void Option3_sPCC()
{
    int month;

    std::cout << "Enter month (1-12): ";
    std::cin >> month;

    // Validate month input
    if (std::cin.fail() || month < 1 || month > 12)
    {
        std::cin.clear(); // Reset fail state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer
        std::cout << "Invalid month." << std::endl;
        return;
    }

    // Stub output for correlation results
    std::cout << "Sample Pearson Correlation Coefficient for month "
              << month << std::endl;
    std::cout << "S_T: stub" << std::endl;
    std::cout << "S_R: stub" << std::endl;
    std::cout << "T_R: stub" << std::endl;
}

/**
 * @brief Handles option 4 for monthly statistics output.
 */
void Option4_WindTempSolar()
{
    int year;

    std::cout << "Enter year: ";
    std::cin >> year;

    // Validate year input
    if (std::cin.fail())
    {
        std::cin.clear(); // Reset fail state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer
        std::cout << "Invalid year." << std::endl;
        return;
    }

    // Generate CSV output (stub for now)
    std::cout << "Writing WindTempSolar.csv for year " << year << std::endl;
    WriteStubWindTempSolarCSV(year);
}

/**
 * @brief Handles option 5.
 */
void Option5()
{
    // Exit message
    std::cout << "Exiting program." << std::endl;
}

/**
 * @brief Runs the assignment menu loop.
 */
void RunMenu()
{
    int choice = 0;

    do
    {
        ShowMenu();
        std::cin >> choice;

        // Validate menu input
        if (std::cin.fail())
        {
            std::cin.clear(); // Reset fail state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer
            std::cout << "Invalid input." << std::endl;
            continue;
        }

        // Execute selected option
        switch (choice)
        {
            case 1:
                Option1(); // Load data
                break;

            case 2:
                Option2(); // Display summary
                break;

            case 3:
                Option3_sPCC(); // Compute sPCC
                break;

            case 4:
                Option4_WindTempSolar(); // Generate CSV output
                break;

            case 5:
                Option5(); // Exit program
                break;

            default:
                std::cout << "Invalid choice." << std::endl;
                break;
        }

    } while (choice != 5); // Loop until user exits
}
