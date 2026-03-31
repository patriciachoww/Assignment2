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
    Date();
    Date(unsigned d, unsigned m, unsigned y);

    unsigned GetDay() const;
    void SetDay(unsigned d);

    unsigned GetMonth() const;
    void SetMonth(unsigned m);

    unsigned GetYear() const;
    void SetYear(unsigned y);

private:
    unsigned day;
    unsigned month;
    unsigned year;
};

bool operator<(const Date& lhs, const Date& rhs);
bool operator>(const Date& lhs, const Date& rhs);
bool operator<=(const Date& lhs, const Date& rhs);
bool operator>=(const Date& lhs, const Date& rhs);
bool operator==(const Date& lhs, const Date& rhs);
std::ostream& operator<<(std::ostream& os, const Date& d);

#endif
