#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <exception>

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

class Database {
public:
    void AddEvent(const Date&, const std::string&);
    bool DeleteEvent(const Date&, const std::string&);
    int  DeleteDate(const Date&);
    void Find(const Date&)const;

    //Find(const Date& date) const;

    void Print() const;
private:
    std::map<Date, std::vector<std::string>> table;
};

std::istream& operator>>(std::istream&, Date&);
std::ostream& operator<<(std::ostream&, const Date&);

int main() try{
    Database db;

    std::string line;
    std::istringstream iss;

    std::string command;
    Date date;

    std::ifstream fs("input.txt");

    while (std::getline(fs, line)) {
    //while(std::getline(std::cin, line)){
        if (line.size() == 0) continue;        

        iss.str(line);
        iss >> command;
        
        // �������� ������� � ������ ����� � ����������� ������
        if (command == "Add") {
            std::string event;
            iss >> date;
            iss.ignore(1);
            std::getline(iss, event);

            db.AddEvent(date, event);
        }
        else if (command == "Del") {
            Date date;
            std::string event;
            iss >> date;
            iss.ignore(1);
            std::getline(iss, event);
            
            if (event.size() > 0) {
                if (db.DeleteEvent(date, event))
                    std::cout << "Deleted successfully\n";
                else
                    std::cout << "Event not found\n";
            }
            else
                std::cout << "Deleted " << db.DeleteDate(date) << " events\n";                
        }
        else if (command == "Find") {
            Date date;
            if(!(iss.eof())){
                iss >> date;
                iss.ignore(1);
                db.Find(date);
            }
        }
        else if (command == "Print") {
            db.Print();
        }
        else {
            std::cout << "Unknown command: " << command << std::endl;
        }
        iss.clear();
    }
    
    return 0;
}
catch (WrongDateException d) {
    std::cout << d.what();
}

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

void Database::AddEvent(const Date& date, const std::string& event) {
    for (const std::string& s : table[date]) {
        if (s == event) return;
    }
    table[date].push_back(event);
    std::sort(table[date].begin(), table[date].end());
}

bool Database::DeleteEvent(const Date& date, const std::string& event) {
    for (auto& p : table) {
        std::vector<std::string>::iterator it = p.second.begin();
        for (; it != p.second.end(); it++) {
            if (*it == event) {
                p.second.erase(it);
                return true;
            }
        }
    }
    return false;
}

int Database::DeleteDate(const Date& date) {
    int s = table[date].size();
    table.erase(date);
    return s;
}

void Database::Find(const Date& date) const{
    try {
        std::vector<std::string> v = table.at(date);
        if (v.size() > 0) {
            for (const std::string& s : v) {
                std::cout << s << std::endl;
            }
        }
    }
    catch (std::out_of_range) {};
};

void Database::Print()const {

    for (const std::pair<Date, std::vector<std::string>>& p : table) {
        if (p.first.GetYear() >= 0) {
            for (const std::string& s : p.second) {
                std::cout << p.first << " " << s << std::endl;
            }
        }
    }
}

std::istream& operator>>(std::istream& ist, Date& d) {
    
    //��������� �������������� ����:
    std::string s_date;
    ist >> s_date;
    std::istringstream is(s_date);

    int i;
    if (is >> i) {
        d.SetYear(i);
        is.ignore(1);
        if (is >> i) {
            d.SetMonth(i);
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
    throw WrongDateException("Wrong date format: "+s_date);
}

std::ostream& operator<<(std::ostream& os, const Date& d) {
    if(d.GetYear() >= 0)
        os << std::setfill('0') << std::setw(4) << d.GetYear() << "-" << std::setw(2) << d.GetMonth() << "-" << std::setw(2) << d.GetDay();
    return os;
}