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
    void Print(std::ostream&) const;

    template<typename UnaryPredicate>
    int RemoveIf(UnaryPredicate);

    template<typename UnaryPredicate>
    std::map<Date, std::vector<std::string>> FindIf(UnaryPredicate);
    Last();

private:
    std::map<Date, std::vector<std::string>> table;
};