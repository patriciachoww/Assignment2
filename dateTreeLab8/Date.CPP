/**
 * @file Date.cpp
 * @brief Implementation of Date class.
 *
 * This class stores a calendar date (day, month, year)
 * and provides basic access methods. It also defines
 * comparison operators so that Date objects can be used
 * in ordered structures such as a Binary Search Tree (BST).
 *
 * @author Patricia
 */

#include "Date.h"

// --- Constructors ---

Date::Date() : day(0), month(0), year(0)
{
    // Default date initialized to 0/0/0
}

Date::Date(unsigned d, unsigned m, unsigned y) : day(d), month(m), year(y)
{
    // Initialize date with given values
}

// --- Getter methods ---

unsigned Date::GetDay() const
{
    return day;
}

unsigned Date::GetMonth() const
{
    return month;
}

unsigned Date::GetYear() const
{
    return year;
}

// --- Setter methods ---

void Date::SetDay(unsigned d)
{
    day = d;
}

void Date::SetMonth(unsigned m)
{
    month = m;
}

void Date::SetYear(unsigned y)
{
    year = y;
}

// ------------------------------------------------------------
// Comparison operators
// These are required so Date objects can be stored in a BST.
// Ordering is based on chronological sequence:
// year → month → day
// ------------------------------------------------------------

bool operator<(const Date& lhs, const Date& rhs)
{
    // Compare by year first
    if (lhs.GetYear() != rhs.GetYear())
        return lhs.GetYear() < rhs.GetYear();

    // If years are equal, compare months
    if (lhs.GetMonth() != rhs.GetMonth())
        return lhs.GetMonth() < rhs.GetMonth();

    // If months are also equal, compare days
    return lhs.GetDay() < rhs.GetDay();
}

bool operator>(const Date& lhs, const Date& rhs)
{
    return rhs < lhs;
}

bool operator<=(const Date& lhs, const Date& rhs)
{
    return !(lhs > rhs);
}

bool operator>=(const Date& lhs, const Date& rhs)
{
    return !(lhs < rhs);
}

bool operator==(const Date& lhs, const Date& rhs)
{
    return lhs.GetYear()  == rhs.GetYear()  &&
           lhs.GetMonth() == rhs.GetMonth() &&
           lhs.GetDay()   == rhs.GetDay();
}
