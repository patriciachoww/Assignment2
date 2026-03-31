/**
 * @file AssignmentMenu.h
 * @brief Menu functions for Assignment 2 progress demo.
 *
 * Contains the menu display and handlers for the updated
 * Assignment 2 options required for Lab 11.
 *
 * @author Patricia
 * @date 31/03/2026
 */

#ifndef ASSIGNMENT_MENU_H
#define ASSIGNMENT_MENU_H

/**
 * @brief Displays the assignment menu.
 */
void ShowMenu(); // Prints menu options to console

/**
 * @brief Runs the assignment menu loop.
 */
void RunMenu(); // Controls user input and menu flow

/**
 * @brief Handles option 1.
 */
void Option1(); // Load data (placeholder)

/**
 * @brief Handles option 2.
 */
void Option2(); // Display summary (placeholder)

/**
 * @brief Handles option 3 for sPCC.
 */
void Option3_sPCC(); // Compute correlation for selected month

/**
 * @brief Handles option 4 for monthly statistics output.
 */
void Option4_WindTempSolar(); // Generate CSV output

/**
 * @brief Handles option 5.
 */
void Option5(); // Exit program

#endif
