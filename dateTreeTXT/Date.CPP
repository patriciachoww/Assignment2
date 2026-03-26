/**
 * @file Date.cpp
 * @brief Implementation of Date class.
 *
 * Defines constructors, getters, setters,
 * comparison and output operators.
 *
 * @author Patricia
 * @date 25/03/2026
 */

#include "Date.h"

/**
 * @brief Default constructor.
 */
Date::Date() : day(0), month(0), year(0)
{
    // default date
}

/**
 * @brief Parameterized constructor.
 */
Date::Date(unsigned d, unsigned m, unsigned y)
    : day(d), month(m), year(y)
{
    // set date values
}

/**
 * @brief Get day.
 */
unsigned Date::GetDay() const
{
    return day; // return day
}

/**
 * @brief Get month.
 */
unsigned Date::GetMonth() const
{
    return month; // return month
}

/**
 * @brief Get year.
 */
unsigned Date::GetYear() const
{
    return year; // return year
}

/**
 * @brief Set day.
 */
void Date::SetDay(unsigned d)
{
    day = d; // update day
}

/**
 * @brief Set month.
 */
void Date::SetMonth(unsigned m)
{
    month = m; // update month
}

/**
 * @brief Set year.
 */
void Date::SetYear(unsigned y)
{
    year = y; // update year
}

/**
 * @brief Compare if lhs < rhs.
 * Order: year → month → day
 */
bool operator<(const Date& lhs, const Date& rhs)
{
    // compare year
    if (lhs.GetYear() != rhs.GetYear())
        return lhs.GetYear() < rhs.GetYear();

    // compare month
    if (lhs.GetMonth() != rhs.GetMonth())
        return lhs.GetMonth() < rhs.GetMonth();

    // compare day
    return lhs.GetDay() < rhs.GetDay();
}

/**
 * @brief Compare if lhs > rhs.
 */
bool operator>(const Date& lhs, const Date& rhs)
{
    return rhs < lhs; // reverse <
}

/**
 * @brief Compare if lhs <= rhs.
 */
bool operator<=(const Date& lhs, const Date& rhs)
{
    return !(rhs < lhs); // not greater
}

/**
 * @brief Compare if lhs >= rhs.
 */
bool operator>=(const Date& lhs, const Date& rhs)
{
    return !(lhs < rhs); // not less
}

/**
 * @brief Check if two dates are equal.
 */
bool operator==(const Date& lhs, const Date& rhs)
{
    return lhs.GetYear()  == rhs.GetYear() &&
           lhs.GetMonth() == rhs.GetMonth() &&
           lhs.GetDay()   == rhs.GetDay(); // same date
}

/**
 * @brief Output Date to stream.
 */
std::ostream& operator<<(std::ostream& os, const Date& d)
{
    os << d.GetDay() << "/"
       << d.GetMonth() << "/"
       << d.GetYear(); // format dd/mm/yyyy
    return os;
}
