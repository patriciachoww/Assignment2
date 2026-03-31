/**
 * @file Date.h
 * @brief Defines the Date class used for BST operations.
 *
 * Stores a simple date using day, month, and year.
 * Also declares comparison and output operators.
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
 * This class stores date values and provides getter and setter
 * functions. Comparison operators are declared as non-member
 * functions so Date objects can be ordered in a BST.
 */
class Date
{
public:
    /**
     * @brief Default constructor.
     *
     * Initializes the date to 0/0/0.
     */
    Date();

    /**
     * @brief Parameterized constructor.
     * @param d Day value
     * @param m Month value
     * @param y Year value
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
 * @brief Check whether two dates are equal.
 * @param lhs Left-hand Date
 * @param rhs Right-hand Date
 * @return True if both dates are equal
 */
bool operator==(const Date& lhs, const Date& rhs);

/**
 * @brief Output a Date to a stream.
 * @param os Output stream
 * @param d Date object
 * @return Reference to output stream
 */
std::ostream& operator<<(std::ostream& os, const Date& d);

#endif
