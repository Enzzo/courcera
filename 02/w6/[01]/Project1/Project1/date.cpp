#include "date.h"
#include <iostream>
#include <sstream>

bool operator<(const Date& lhs, const Date& rhs) {

    //Если левый год меньше правого
    if ((lhs.GetYear() < rhs.GetYear()) ||
        //или если года равны и левый месяц меньше правого
        (lhs.GetYear() == rhs.GetYear() && ((lhs.GetMonth() < rhs.GetMonth()) ||
            //или если года равны и месяца равны и левый день меньше правого
        (lhs.GetMonth() == rhs.GetMonth() && lhs.GetDay() < rhs.GetDay()))))
        //то возвращаем true
        return true;

    return false;
};

std::istream& operator>>(std::istream& ist, Date& d) {

    //строковое представаление даты:
    std::string s_date;
    ist >> s_date;
    std::istringstream is(s_date);

    int i;
    if (is >> i) {
        d.SetYear(i);
        if (is.peek() == '-') {
            is.ignore(1);
            if (is >> i) {
                d.SetMonth(i);
                if (is.peek() == '-') {
                    is.ignore(1);
                    if (is >> i) {
                        d.SetDay(i);
                        if (is.eof()) {
                            //если формат даты верен, то проверяем правильность дня, месяца года
                            int month = d.GetMonth();
                            if (month < 1 || 12 < month) throw WrongDateException("Month value is invalid: " + std::to_string(month));
                            int day = d.GetDay();
                            if (day < 1 || 31 < day) throw WrongDateException("Day value is invalid: " + std::to_string(day));
                            return ist;
                        }
                    }
                }
            }
        }
    }
    throw WrongDateException("Wrong date format: " + s_date);
}

std::ostream& operator<<(std::ostream& os, const Date& d) {
    if (d.GetYear() >= 0)
        os << std::setfill('0') << std::setw(4) << d.GetYear() << "-" << std::setw(2) << d.GetMonth() << "-" << std::setw(2) << d.GetDay();
    return os;
}