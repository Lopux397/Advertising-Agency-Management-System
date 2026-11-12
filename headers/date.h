#pragma once

#include <iostream>
#include <compare>

class Date
{
private:
    int year{};
    int month{};
    int day{};
public:
    Date(int dayTemp, int monthTemp, int yearTemp);

    int getYear() const;
    int getMonth() const;
    int getDay() const;

    void setYear(int yearTemp);
    void setMonth(int monthTemp);
    void setDay(int dayTemp);
    void setDate(int dayTemp, int monthTemp, int yearTemp);

    bool isValidDate(int dayTemp, int monthTemp, int yearTemp) const;

    auto operator<=>(const Date& date) const = default;

    friend std::ostream& operator<< (std::ostream& os, const Date& date)
    {
        os << date.day << "." << date.month << "." << date.year << std::endl;
        return os;
    }
};