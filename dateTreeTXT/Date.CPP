#include "Date.h"
#include <iostream>

/**
 * @brief Default constructor.
 */
Date::Date()
    : day(0), month(0), year(0)
{
}

/**
 * @brief Parameterized constructor.
 * @param d Day
 * @param m Month
 * @param y Year
 */
Date::Date(unsigned d, unsigned m, unsigned y)
    : day(d), month(m), year(y)
{
}

/**
 * @brief Get day.
 * @return Day value
 */
unsigned Date::GetDay() const
{
    return day;
}

/**
 * @brief Set day.
 * @param d Day value
 */
void Date::SetDay(unsigned d)
{
    day = d;
}

/**
 * @brief Get month.
 * @return Month value
 */
unsigned Date::GetMonth() const
{
    return month;
}

/**
 * @brief Set month.
 * @param m Month value
 */
void Date::SetMonth(unsigned m)
{
    month = m;
}

/**
 * @brief Get year.
 * @return Year value
 */
unsigned Date::GetYear() const
{
    return year;
}

/**
 * @brief Set year.
 * @param y Year value
 */
void Date::SetYear(unsigned y)
{
    year = y;
}

/**
 * @brief Compare if lhs is earlier than rhs.
 * @param lhs Left date
 * @param rhs Right date
 * @return True if lhs is earlier
 */
bool operator<(const Date& lhs, const Date& rhs)
{
    if (lhs.GetYear() != rhs.GetYear())
    {
        return lhs.GetYear() < rhs.GetYear();
    }

    if (lhs.GetMonth() != rhs.GetMonth())
    {
        return lhs.GetMonth() < rhs.GetMonth();
    }

    return lhs.GetDay() < rhs.GetDay();
}

/**
 * @brief Compare if lhs is later than rhs.
 * @param lhs Left date
 * @param rhs Right date
 * @return True if lhs is later
 */
bool operator>(const Date& lhs, const Date& rhs)
{
    return rhs < lhs;
}

/**
 * @brief Compare if lhs is earlier than or equal to rhs.
 * @param lhs Left date
 * @param rhs Right date
 * @return True if lhs <= rhs
 */
bool operator<=(const Date& lhs, const Date& rhs)
{
    return !(lhs > rhs);
}

/**
 * @brief Compare if lhs is later than or equal to rhs.
 * @param lhs Left date
 * @param rhs Right date
 * @return True if lhs >= rhs
 */
bool operator>=(const Date& lhs, const Date& rhs)
{
    return !(lhs < rhs);
}

/**
 * @brief Check if two dates are equal.
 * @param lhs Left date
 * @param rhs Right date
 * @return True if equal
 */
bool operator==(const Date& lhs, const Date& rhs)
{
    return lhs.GetDay() == rhs.GetDay() &&
           lhs.GetMonth() == rhs.GetMonth() &&
           lhs.GetYear() == rhs.GetYear();
}

/**
 * @brief Output Date to stream.
 * @param os Output stream
 * @param d Date object
 * @return Output stream
 */
std::ostream& operator<<(std::ostream& os, const Date& d)
{
    os << d.GetDay() << "/"
       << d.GetMonth() << "/"
       << d.GetYear();
    return os;
}
