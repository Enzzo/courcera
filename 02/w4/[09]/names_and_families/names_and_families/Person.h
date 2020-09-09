#pragma once
#include <string>
#include <map>
#include <vector>

class Person {
public:
    void ChangeFirstName(int, const std::string&);
    void ChangeLastName(int, const std::string&);
    std::string GetFullName(int);
private:
    std::string GetNameByYear(const std::map<int, std::string>&, int);
    std::map<int, std::string>fn;
    std::map<int, std::string>ln;
    std::vector<int>keys;
};