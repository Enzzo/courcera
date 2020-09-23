#pragma once
#include "date.h"

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

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
    void Add(const Date&, const std::string&);
    bool DeleteEvent(const Date&, const std::string&);
    int  DeleteDate(const Date&);
    void Find(const Date&)const;

    void Print(std::ostream&) const;

private:
    std::map<Date, std::vector<std::string>> table;
};