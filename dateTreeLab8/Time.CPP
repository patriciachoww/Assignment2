/**
 * @file Time.cpp
 * @brief Implementation of Time class.
 *
 * This class represents a time value using hour, minute,
 * and second components. It provides basic getter and setter
 * methods to access and modify each field.
 *
 * @author Patricia
 */

#include "Time.h"

// --- Constructors ---

Time::Time() : hour(0), minute(0), second(0)
{
    // Default time initialized to 00:00:00
}

Time::Time(unsigned h, unsigned m, unsigned s)
    : hour(h), minute(m), second(s)
{
    // Initialize time with given values
}

// --- Getter methods ---

unsigned Time::GetHour() const
{
    return hour;
}

unsigned Time::GetMinute() const
{
    return minute;
}

unsigned Time::GetSecond() const
{
    return second;
}

// --- Setter methods ---

void Time::SetHour(unsigned h)
{
    hour = h;
}

void Time::SetMinute(unsigned m)
{
    minute = m;
}

void Time::SetSecond(unsigned s)
{
    second = s;
}
