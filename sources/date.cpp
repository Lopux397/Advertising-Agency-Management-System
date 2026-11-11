#include "../headers/date.h"

#include <stdexcept>
#include <array>

Date::Date() = default;
Date::Date(int dayTemp, int monthTemp, int yearTemp) :year(yearTemp), month(monthTemp), day(dayTemp)
{
    if (!isValidDate(day, month, year))
        throw std::invalid_argument("Invalid date");
}

int Date::getYear() const { return year; }
int Date::getMonth() const { return month; }
int Date::getDay() const{ return day; }

void Date::setYear(int yearTemp)
{
    if (!isValidDate(day, month, yearTemp))
        throw std::invalid_argument("Invalid year for current date");

    year = yearTemp;
}
void Date::setMonth(int monthTemp)
{
    if (!isValidDate(day, monthTemp, year))
        throw std::invalid_argument("Invalid month for current date");

    month = monthTemp;
}
void Date::setDay(int dayTemp)
{
    if (!isValidDate(dayTemp, month, year))
        throw std::invalid_argument("Invalid day for current date");

    day = dayTemp;
}
void Date::setDate(int dayTemp, int monthTemp, int yearTemp)
{
    if (!isValidDate(dayTemp, monthTemp, yearTemp))
        throw std::invalid_argument("Invalid date");

    day = dayTemp;
    month = monthTemp;
    year = yearTemp;
}

bool Date::isValidDate(int dayTemp, int monthTemp, int yearTemp) const
{
    if ((monthTemp < 1) || (monthTemp > 12) ||( yearTemp < 1)) return false;

    const std::array<int, 12> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int maxDays = daysInMonth[monthTemp - 1];

    if (bool leapYear = (yearTemp % 400 == 0) || (yearTemp % 4 == 0 && yearTemp % 100 != 0); monthTemp == 2 && leapYear)
        maxDays = 29;

    return dayTemp >= 1 && dayTemp <= maxDays;
}