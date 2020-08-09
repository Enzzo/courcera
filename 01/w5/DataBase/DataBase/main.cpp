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

class WrongCommandException {
public:
    WrongCommandException(const std::string& m) {
        message += m;
    }
    const std::string what()const {
        return message;
    }
private:
    std::string message = "Unknown command: ";
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

    //std::ifstream fs("input.txt");

    //while (std::getline(fs, line)) {
    while(std::getline(std::cin, line)){
        if (line.size() == 0) continue;        

        iss.str(line);
        iss >> command;
        
        // Считайте команды с потока ввода и обработайте каждую
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
            throw WrongCommandException(command);
        }
        iss.clear();
    }
    
    return 0;
}
catch (WrongDateException d) {
    std::cout << d.what() << std::endl;
}
catch (WrongCommandException c) {
    std::cout << c.what() << std::endl;
}
catch (...) {
    
}

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

void Database::AddEvent(const Date& date, const std::string& event) {
    for (const std::string& s : table[date]) {
        if (s == event) return;
    }
    table[date].push_back(event);
    std::sort(table[date].begin(), table[date].end());
}

bool Database::DeleteEvent(const Date& date, const std::string& event) {
    try {
        std::vector<std::string>& v = table.at(date);
        if (v.size() > 0) {
            std::vector<std::string>::iterator it = v.begin();
            for (; it != v.end(); it++) {
                if (*it == event) {
                    v.erase(it);
                    return true;
                }
            }
        }
    }
    catch (std::out_of_range) {};
    /*
    for (auto& p : table) {
        std::vector<std::string>::iterator it = p.second.begin();
        for (; it != p.second.end(); it++) {
            if (*it == event) {
                p.second.erase(it);
                return true;
            }
        }
    }*/
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
    throw WrongDateException("Wrong date format: "+s_date);
}

std::ostream& operator<<(std::ostream& os, const Date& d) {
    if(d.GetYear() >= 0)
        os << std::setfill('0') << std::setw(4) << d.GetYear() << "-" << std::setw(2) << d.GetMonth() << "-" << std::setw(2) << d.GetDay();
    return os;
}