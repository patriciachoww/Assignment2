/**
 * @file Date.h
 * @brief Declaration of the Date class.
 *
 * The Date class stores a calendar date using day, month,
 * and year values. It also supports comparison operators so
 * Date objects can be used in ordered structures such as Bst<Date>.
 *
 * @author Patricia
 */

#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

/**
 * @class Date
 * @brief Represents a date using day, month, and year.
 *
 * This class stores basic date information and provides
 * accessor and mutator methods for each field.
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
     *
     * @param d Day value.
     * @param m Month value.
     * @param y Year value.
     */
    Date(unsigned d, unsigned m, unsigned y);

    /**
     * @brief Returns the day.
     * @return Day of the month.
     */
    unsigned GetDay() const;

    /**
     * @brief Sets the day.
     * @param d Day value.
     */
    void SetDay(unsigned d);

    /**
     * @brief Returns the month.
     * @return Month value.
     */
    unsigned GetMonth() const;

    /**
     * @brief Sets the month.
     * @param m Month value.
     */
    void SetMonth(unsigned m);

    /**
     * @brief Returns the year.
     * @return Year value.
     */
    unsigned GetYear() const;

    /**
     * @brief Sets the year.
     * @param y Year value.
     */
    void SetYear(unsigned y);

private:
    unsigned day;    ///< Stores day value
    unsigned month;  ///< Stores month value
    unsigned year;   ///< Stores year value
};

// ------------------------------------------------------------
// Non-member comparison operators
// These are required so Date can be compared inside Bst<Date>.
// Dates are compared in chronological order:
// year, then month, then day.
// ------------------------------------------------------------

/**
 * @brief Checks whether one Date is earlier than another.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 * @return true if lhs is earlier than rhs.
 */
bool operator<(const Date& lhs, const Date& rhs);

/**
 * @brief Checks whether one Date is later than another.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 * @return true if lhs is later than rhs.
 */
bool operator>(const Date& lhs, const Date& rhs);

/**
 * @brief Checks whether one Date is earlier than or equal to another.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 * @return true if lhs is earlier than or equal to rhs.
 */
bool operator<=(const Date& lhs, const Date& rhs);

/**
 * @brief Checks whether one Date is later than or equal to another.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 * @return true if lhs is later than or equal to rhs.
 */
bool operator>=(const Date& lhs, const Date& rhs);

/**
 * @brief Checks whether two Date objects are equal.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 * @return true if both dates are the same.
 */
bool operator==(const Date& lhs, const Date& rhs);

#endif
