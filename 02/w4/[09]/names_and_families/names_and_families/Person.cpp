#include "Person.h"
#include <algorithm>

void Person::ChangeFirstName(int year, const std::string& first_name) {
    fn[year] = first_name;
}
void Person::ChangeLastName(int year, const std::string& last_name) {
    ln[year] = last_name;
}
std::string Person::GetFullName(int year) {
    
    std::string first_name;
    std::string last_name;
    std::string result;

    if (first_name.size() == 0 && last_name.size() == 0)
        result = "Incognito";
    else if (last_name.size() == 0)
        result = first_name + " with unknown last name";
    else if (first_name.size() == 0)
        result = last_name + " with unknown first name";
    else
        result = first_name + " " + last_name;
    return result;
}