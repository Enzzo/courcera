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
    if (std::binary_search(fn.begin(), fn.end(), year)) {
        first_name = fn.at(year);
    }

    std::string last_name;
    if (std::binary_search(ln.begin(), ln.end(), year)) {
        last_name = ln.at(year);
    }
    return "";
}