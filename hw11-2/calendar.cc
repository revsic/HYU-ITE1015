#include "calendar.h"

#include <sstream>

Date::Date() : m_year(0), m_month(0), m_day(0) {
    // Do Nothing
}

Date::Date(int year, int month, int day) :
    m_year(year), m_month(month), m_day(day)
{
    // Do Nothing
}

void Date::NextDay(int n) {
    int days = ComputeDaysFromYearStart(m_year, m_month, m_day) + n;

    while (days < 1) {
        days += DaysInYear(--m_year);
    }

    while (days > DaysInYear(m_year)) {
        days -= DaysInYear(m_year++);
    }

    int month_sum = 0;
    for (int m = 1; m <= 12; ++m) {
        int month_day = DaysInMonth(m_year, m);
        if (month_sum < days && days <= month_sum + month_day) {
            m_month = m;
            m_day = days - month_sum;
            break;
        }
        month_sum += month_day;
    }
}

bool Date::SetDate(int year, int month, int day) {
    auto valid = [](int n, int limit) { return n >= 1 && n <= limit; };
    if (year >= 0 
        && valid(month, 12) 
        && valid(day, DaysInMonth(year, month))) 
    {
        m_year = year;
        m_month = month;
        m_day = day;
        return true;
    }
    else {
        std::ostringstream oss;
        oss << year << '.' << month << '.' << day;
        throw InvalidDateException(oss.str());
    }
    return false;
}

int Date::year() const {
    return m_year;
}

int Date::month() const {
    return m_month;
}

int Date::day() const {
    return m_day;
}

int Date::DaysInYear(int year) {
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        return 366;
    }
    else {
        return 365;
    }
}

int Date::DaysInMonth(int year, int month) {
    int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (DaysInYear(year) == 366 && month == 2) {
        return 29;
    } 
    else {
        return days[month];
    }
}

int Date::ComputeDaysFromYearStart(int year, int month, int day) {
    for (int i = 1; i < month; ++i) {
        day += DaysInMonth(year, i);
    }
    return day;
}

std::ostream& operator<<(std::ostream& os, Date const& date) {
    os << date.year() << '.' << date.month() << '.' << date.day();
    return os;
}

std::istream& operator>>(std::istream& is, Date& date) {
    char sep;
    int year, month, day;

    is >> year >> sep >> month >> sep >> day;
    date.SetDate(year, month, day);

    return is;
}
