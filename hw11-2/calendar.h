#ifndef CALENDAR_H
#define CALENDAR_H

#include <iostream>

class Date {
public:
    Date();
    Date(int year, int month, int day);

    void NextDay(int n = 1);
    bool SetDate(int year, int month, int day);

    int year() const;
    int month() const;
    int day() const;

private:
    static int DaysInYear(int year);
    static int DaysInMonth(int year, int month);
    static int ComputeDaysFromYearStart(int year, int month, int day);

    int m_year;
    int m_month;
    int m_day;
};

struct InvalidDateException {
    std::string input_date;
    InvalidDateException(std::string const& input_date) : input_date(input_date) {
        // Do Nothing
    }

    InvalidDateException(std::string&& input_date) : input_date(std::move(input_date)) {
        // Do Nothing
    }
};

std::ostream& operator<<(std::ostream& os, Date const& date);
std::istream& operator>>(std::istream& is, Date& date);

#endif