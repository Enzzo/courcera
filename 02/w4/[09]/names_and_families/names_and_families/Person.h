#pragma once
#include <string>
#include <map>

class Person {
public:
    void ChangeFirstName(int, const std::string&);
    void ChangeLastName(int, const std::string&);
    std::string GetFullName(int);
private:
    std::map<int, std::string>fn;
    std::map<int, std::string>ln;
};