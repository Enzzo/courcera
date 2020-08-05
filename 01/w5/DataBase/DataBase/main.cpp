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

std::istream& operator>>(std::istream& is, Database& db);

//������� ��� �������� ������ � ������� �������
//����������� ��� ��������� �������� �������
void upper(std::string&);

int main() {
    Database db;

    std::string command;
    std::string line;
    std::string mode;

    std::istringstream iss;

    while (std::getline(std::cin, line)) {
        if (line.size() == 0) continue;

        iss.str(line);
        
        std::getline(iss, command, ' ');
        std::getline(iss, command, ' ');
        std::getline(iss, command, ' ');
        std::getline(iss, command, ' ');
        std::getline(iss, command, ' ');
        //���� ������ ������, �� �������
        



        // �������� ������� � ������ ����� � ����������� ������
        if (command == "ADD") {
            Date date;
            std::string event;
            std::cin >> event;
            std::cout << "\ntest:  " << event << std::endl;
            db.AddEvent(date, event);
        }
        else if (command == "DEL") {

        }
        else if (command == "FIND") {
        }
        else if (command == "PRINT") {
            db.Print();
            command.erase();
        }
        else {
            std::cout << "Unknown command: " << command;
            command.erase();
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
}

std::istream& operator>>(std::istream& is, Database& db) {
    return is;
}