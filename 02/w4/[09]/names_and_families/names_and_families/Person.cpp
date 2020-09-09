#include "Person.h"
#include <algorithm>

void Person::ChangeFirstName(int year, const std::string& first_name) {
    fn[year] = first_name;
}
void Person::ChangeLastName(int year, const std::string& last_name) {
    ln[year] = last_name;
}
std::string Person::GetFullName(int year) {
    
    std::string first_name = GetNameByYear(fn, year);
    std::string last_name = GetNameByYear(ln, year);
    std::string result;

    if (first_name.empty() && last_name.empty())
        result = "Incognito";
    else if (last_name.empty())
        result = first_name + " with unknown last name";
    else if (first_name.empty())
        result = last_name + " with unknown first name";
    else
        result = first_name + " " + last_name;
    return result;
}

std::string Person::GetNameByYear(const std::map<int, std::string>& m, int year) {
    auto it = m.upper_bound(year);
    if (std::prev(it) != m.end())return std::prev(it)->second;
    return "";
}