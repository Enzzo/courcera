#include "phone_number.h"

#include <string>
#include <exception>
#include <sstream>

PhoneNumber::PhoneNumber(const std::string& international_number) {
    std::stringstream is(international_number);
    if (is.peek() == '+') {
        is.ignore(1);
        if (std::getline(is, country_code_, '-')) {
            if (std::getline(is, city_code_, '-')) {
                if (std::getline(is, local_number_))
                    return;
            }
        }
    }
    throw std::invalid_argument("wrong number");
};

std::string PhoneNumber::GetCountryCode() const {
	return country_code_;
};

std::string PhoneNumber::GetCityCode() const {
	return city_code_;
};

std::string PhoneNumber::GetLocalNumber() const {
	return local_number_;
};

std::string PhoneNumber::GetInternationalNumber() const {	
	return "+" + country_code_ + "-" + city_code_ + "-" + local_number_;
};