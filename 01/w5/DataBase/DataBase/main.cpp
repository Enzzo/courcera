// Реализуйте функции и методы классов и при необходимости добавьте свои

/*
- добавление события:                        Add Дата Событие
- удаление события:                          Del Дата Событие
- удаление всех событий за конкретную дату:  Del Дата
- поиск событий за конкретную дату:          Find Дата
- печать всех событий за все даты:           Print
*/

#include <iostream>
#include <fstream>
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

//Функция для перевода строки в верхний регистр
//применяется для сравнения введённой команды
void upper(std::string&);
void ShowMap(const std::map<Date, std::vector<std::string>>&);

int main() {
    Database db;

    std::string line;
    std::istringstream iss;

    std::string command;
    Date date;

    std::ifstream fs("input.txt");

    while (std::getline(fs, line)) {
        if (line.size() == 0) continue;        

        iss.str(line);
        iss >> command;
        
        // Считайте команды с потока ввода и обработайте каждую
        if (command == "ADD") {
            std::string event;
            iss >> date;
            iss.ignore(1);
            std::getline(iss, event);

            db.AddEvent(date, event);
        }
        else if (command == "DEL") {
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
        else if (command == "FIND") {
            Date date;
            iss >> date;

        }
        else if (command == "PRINT") {
            db.Print();
        }
        else {
            std::cout << "Unknown command: " << command;
        }
        iss.clear();
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

void ShowMap(const std::map<Date, std::vector<std::string>>& t) {
    for (const auto& i : t) {
        std::cout << i.first << std::endl;
        for (const auto& s : i.second) {
            std::cout << "\t" << s << std::endl;
        }
    }
}