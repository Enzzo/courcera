#pragma once

#include "database.h"

void Database::Add(const Date& date, const std::string& event) {
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
    return false;
}

int Database::DeleteDate(const Date& date) {
    int s = table[date].size();
    table.erase(date);
    return s;
}

void Database::Find(const Date& date) const {
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

void Database::Print(std::ostream& os)const {

    for (const std::pair<Date, std::vector<std::string>>& p : table) {
        if (p.first.GetYear() >= 0) {
            for (const std::string& s : p.second) {
                os << p.first << " " << s << std::endl;
            }
        }
    }
}