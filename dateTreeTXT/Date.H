/**
 * @file Date.h
 * @brief Defines the Date class used for BST operations.
 *
 * The Date class stores a calendar date using day, month, and year.
 * It provides getter and setter functions, as well as comparison
 * operators required for use in a Binary Search Tree (BST).
 *
 * Comparison operators are implemented as non-member functions
 * because ordering is not a storage responsibility of the class,
 * but is required externally (e.g. for BST operations).
 *
 * @author Patricia
 * @date 25/03/2026
 */

#ifndef DATE_H
#define DATE_H

#include <iostream>

/**
 * @class Date
 * @brief Represents a simple date (day, month, year).
 *
 * This class encapsulates a date and provides access
 * and modification methods. It does not handle formatting
 * or validation logic.
 */
class Date
{
public:
    /**
     * @brief Default constructor.
     *
     * Initializes date to 0/0/0.
     */
    Date();

    /**
     * @brief Parameterized constructor.
     * @param d Day
     * @param m Month
     * @param y Year
     */
    Date(unsigned d, unsigned m, unsigned y);

    /**
     * @brief Get the day.
     * @return Day value
     */
    unsigned GetDay() const;

    /**
     * @brief Set the day.
     * @param d Day value
     */
    void SetDay(unsigned d);

    /**
     * @brief Get the month.
     * @return Month value
     */
    unsigned GetMonth() const;

    /**
     * @brief Set the month.
     * @param m Month value
     */
    void SetMonth(unsigned m);

    /**
     * @brief Get the year.
     * @return Year value
     */
    unsigned GetYear() const;

    /**
     * @brief Set the year.
     * @param y Year value
     */
    void SetYear(unsigned y);

private:
    unsigned day;    ///< Day component
    unsigned month;  ///< Month component
    unsigned year;   ///< Year component
};

/**
 * @brief Compare if lhs is earlier than rhs.
 * @param lhs Left-hand Date
 * @param rhs Right-hand Date
 * @return True if lhs < rhs
 */
bool operator<(const Date& lhs, const Date& rhs);

/**
 * @brief Compare if lhs is later than rhs.
 * @param lhs Left-hand Date
 * @param rhs Right-hand Date
 * @return True if lhs > rhs
 */
bool operator>(const Date& lhs, const Date& rhs);

/**
 * @brief Compare if lhs is earlier than or equal to rhs.
 * @param lhs Left-hand Date
 * @param rhs Right-hand Date
 * @return True if lhs <= rhs
 */
bool operator<=(const Date& lhs, const Date& rhs);

/**
 * @brief Compare if lhs is later than or equal to rhs.
 * @param lhs Left-hand Date
 * @param rhs Right-hand Date
 * @return True if lhs >= rhs
 */
bool operator>=(const Date& lhs, const Date& rhs);

/**
 * @brief Check if two dates are equal.
 * @param lhs Left-hand Date
 * @param rhs Right-hand Date
 * @return True if equal
 */
bool operator==(const Date& lhs, const Date& rhs);

/**
 * @brief Output Date to stream.
 * @param os Output stream
 * @param d Date object
 * @return Output stream
 */
std::ostream& operator<<(std::ostream& os, const Date& d);

#endif
