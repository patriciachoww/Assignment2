/**
 * @file Time.cpp
 * @brief Implementation of the Time class.
 *
 * Provides constructors and basic getter/setter methods
 * for handling time values.
 *
 * @author Patricia
 */

#include "Time.h"

// --- Constructors ---

Time::Time() : hour(0), minute(0), second(0)
{
    // Default time set to 00:00:00
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
