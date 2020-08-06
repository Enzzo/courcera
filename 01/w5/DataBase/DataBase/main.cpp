// ���������� ������� � ������ ������� � ��� ������������� �������� ����

/*
- ���������� �������:                        Add ���� �������
- �������� �������:                          Del ���� �������
- �������� ���� ������� �� ���������� ����:  Del ����
- ����� ������� �� ���������� ����:          Find ����
- ������ ���� ������� �� ��� ����:           Print
*/

#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

class Date {
public:
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

class Database {
public:
    void AddEvent(const Date& date, const std::string& event);
    bool DeleteEvent(const Date& date, const std::string& event);
    int  DeleteDate(const Date& date);

    //Find(const Date& date) const;

    void Print() const;
private:
    std::map<Date, std::vector<std::string>> table;
};

std::istringstream& operator>>(std::istringstream&, Date&);
std::ostream& operator<<(std::ostream&, const Date&);

//������� ��� �������� ������ � ������� �������
//����������� ��� ��������� �������� �������
void upper(std::string&);

int main() {
    Database db;

    std::string line;
    std::istringstream iss;

    //TEST
    /*
    std::string test;
    std::string test2;
    std::istringstream isstest;
    
    while (std::getline(std::cin, test)) {
        isstest.str(test);
        isstest >> test2;
    }*/
    //TEST

    std::string command;
    while (std::getline(std::cin, line)) {
        if (line.size() == 0) continue;

        iss.str(line);
        iss >> command;
        
        
        //std::getline(iss, command, ' ');
        if (iss.peek() == ' ')iss.ignore(1);

        //���� ������ ������, �� �������    

        // �������� ������� � ������ ����� � ����������� ������
        if (command == "ADD") {
            Date date;
            iss >> date;
            std::string event;
            std::getline(iss, event);
            db.AddEvent(date, event);
        }
        else if (command == "DEL") {

        }
        else if (command == "FIND") {
        }
        else if (command == "PRINT") {
            db.Print();
        }
        else {
            std::cout << "Unknown command: " << command;
        }
    }
    
    return 0;
}

void upper(std::string& s) {
    for (char& c : s)
        c = std::toupper(c);
}

void Database::AddEvent(const Date& date, const std::string& event) {
    for (const std::string& s : table[date]) {
        if (s == event) return;
    }
    table[date].push_back(event);
}

void Database::Print()const {
    for (const std::pair<Date, std::vector<std::string>>& p : table) {
        std::cout << "Date: " << p.first << std::endl;
        for (const std::string& s : p.second) {
            std::cout << "Event: " << s << std::endl;
        }
        std::cout << std::endl;
    }
}

std::istringstream& operator>>(std::istringstream& ist, Date& d) {

    int i;
    ist >> i;
    d.SetDay(i);
    ist.ignore(1);
    ist >> i;
    d.SetMonth(i);
    ist.ignore(1);
    ist >> i;
    d.SetYear(i);

    return ist;
}

std::ostream& operator<<(std::ostream& os, const Date& d) {
    os << d.GetDay() << "/" << d.GetMonth() << "/" << d.GetYear();
    return os;
}