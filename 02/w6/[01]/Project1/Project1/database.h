#pragma once

#include <string>
#include <map>
#include <vector>

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