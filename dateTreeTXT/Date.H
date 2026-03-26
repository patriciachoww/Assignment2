/**
 * @file Date.h
 * @brief Date class for BST usage.
 *
 * Stores day, month, year and supports comparison and output.
 *
 * @author Patricia
 * @date 25/03/2026
 */

#ifndef DATE_H
#define DATE_H

#include <iostream>

/**
 * @class Date
 * @brief Simple date (day/month/year).
 */
class Date
{
public:
    /**
     * @brief Default constructor.
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
     * @brief Get day.
     * @return Day value
     */
    unsigned GetDay() const;

    /**
     * @brief Set day.
     * @param d Day value
     */
    void SetDay(unsigned d);

    /**
     * @brief Get month.
     * @return Month value
     */
    unsigned GetMonth() const;

    /**
     * @brief Set month.
     * @param m Month value
     */
    void SetMonth(unsigned m);

    /**
     * @brief Get year.
     * @return Year value
     */
    unsigned GetYear() const;

    /**
     * @brief Set year.
     * @param y Year value
     */
    void SetYear(unsigned y);

private:
    unsigned day;    ///< day
    unsigned month;  ///< month
    unsigned year;   ///< year
};

/**
 * @brief Compare if lhs is earlier than rhs.
 */
bool operator<(const Date& lhs, const Date& rhs);

/**
 * @brief Compare if lhs is later than rhs.
 */
bool operator>(const Date& lhs, const Date& rhs);

/**
 * @brief Compare if lhs <= rhs.
 */
bool operator<=(const Date& lhs, const Date& rhs);

/**
 * @brief Compare if lhs >= rhs.
 */
bool operator>=(const Date& lhs, const Date& rhs);

/**
 * @brief Check if two dates are equal.
 */
bool operator==(const Date& lhs, const Date& rhs);

/**
 * @brief Output Date to stream.
 */
std::ostream& operator<<(std::ostream& os, const Date& d);

#endif
