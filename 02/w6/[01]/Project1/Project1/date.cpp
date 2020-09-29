#include "date.h"

class WrongDateException {
public:
    WrongDateException(const std::string& m = "Wrong date") {
        message = m;
    }
    const std::string what()const {
        return message;
    }
private:
    std::string message;
};

bool operator<(const Date& lhs, const Date& rhs) {

    //���� ����� ��� ������ �������
    if ((lhs.GetYear() < rhs.GetYear()) ||
        //��� ���� ���� ����� � ����� ����� ������ �������
        (lhs.GetYear() == rhs.GetYear() && ((lhs.GetMonth() < rhs.GetMonth()) ||
            //��� ���� ���� ����� � ������ ����� � ����� ���� ������ �������
        (lhs.GetMonth() == rhs.GetMonth() && lhs.GetDay() < rhs.GetDay()))))
        //�� ���������� true
        return true;

    return false;
};

std::istream& operator>>(std::istream& ist, Date& d) {

    //��������� �������������� ����:
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
                            //���� ������ ���� �����, �� ��������� ������������ ���, ������ ����
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

Date ParseDate(std::istream& is) {
    Date d;
    return d;
}