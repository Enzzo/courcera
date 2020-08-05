// Реализуйте функции и методы классов и при необходимости добавьте свои

/*
- добавление события:                        Add Дата Событие
- удаление события:                          Del Дата Событие
- удаление всех событий за конкретную дату:  Del Дата
- поиск событий за конкретную дату:          Find Дата
- печать всех событий за все даты:           Print
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <string>

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

std::istream& operator>>(std::istream& is, Database& db);

//Функция для перевода строки в верхний регистр
//применяется для сравнения введённой команды
void upper(std::string&);

int main() {
    Database db;

    std::string command;
    std::string line;
    while (std::getline(std::cin, line)) {
        
        command = 

        //Если пустая строка, то скипаем
        if (command.size() == 0) continue;



        // Считайте команды с потока ввода и обработайте каждую
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