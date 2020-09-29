#pragma once
#include <iostream>
#include <sstream>
#include <iomanip>

class Date {
public:
    Date(const int y, const int m, const int d) : year(y), month(m), day(d) {};
    Date() : Date(0, 0, 0) {};
    int GetYear() const {
        return year;
    };
    int GetMonth() const {
        return month;
    };
    int GetDay() const {
        return day;
    };

    void SetYear(const int year) {
        this->year = year;
    }
    void SetMonth(const int month) {
        this->month = month;
    }
    void SetDay(const int day) {
        this->day = day;
    }
private:
    int year;
    int month;
    int day;
};

std::istream& operator>>(std::istream&, Date&);
std::ostream& operator<<(std::ostream&, const Date&);

bool operator<(const Date&, const Date&);

Date ParseDate(std::istream&);