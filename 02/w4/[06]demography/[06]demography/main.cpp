#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

enum class Gender {
	FEMALE,
	MALE
};

struct Person {
	int age;
	Gender gender;
	bool is_employed;
};

std::ostream& operator<<(std::ostream& os, const Person& p) {
	os << "Age: " << p.age;
	os << std::endl;
	std::string gnd = (p.gender == Gender::FEMALE) ? "FEMALE" : "MALE";
	os << gnd;
	os << std::endl;
	std::string emp = (p.is_employed) ? "employed" : "not employed";
	os << emp;
	os << std::endl;
	return os;
}

void PrintStats(std::vector<Person>);

template<typename T>
void PrintVector(const std::vector<T>& v) {
	std::cout << "\n/////////////////////////////////////////////////////////////////////\n";
	for (const T& t : v)
		std::cout << t << std::endl;
}

template<typename InputIt>
int computeMedianAge(InputIt range_begin, InputIt range_end) {
	if (range_begin == range_end)
		return 0;
	return 1;
}

int main() {
	std::vector<Person> persons = {
		{31, Gender::MALE, false},
		{40, Gender::FEMALE, true},
		{24, Gender::MALE, true},
		{20, Gender::FEMALE, true},
		{80, Gender::FEMALE, false},
		{78, Gender::MALE, false},
		{10, Gender::FEMALE, false},
		{55, Gender::MALE, true},
	};
	PrintStats(persons);

	return 0;
} 

void PrintStats(std::vector<Person> persons) {
	auto fem_end = std::partition(persons.begin(), persons.end(), [](const Person& p) {return p.gender == Gender::FEMALE; });
	auto emp_fem_end = std::partition(persons.begin(), fem_end, [](const Person& p) {return p.is_employed; });
	auto emp_ml_end = std::partition(fem_end, persons.end(), [](const Person& p) {return p.is_employed; });
	//general:
	std::cout << "\nMedian age = " << computeMedianAge(persons.begin(), persons.end());
	
	//females:
	std::cout << "\nMedian age for females = "<<computeMedianAge(persons.begin(), fem_end);

	//males:
	std::cout << "\nMedian age for males = " << computeMedianAge(fem_end, persons.end());

	//employed females:
	std::cout << "\nMedian age for employed females = " << computeMedianAge(persons.begin(), emp_fem_end);

	//unemployed females:
	std::cout << "\nMedian age for unemployed females = " << computeMedianAge(emp_fem_end, fem_end);

	//employed males:
	std::cout << "\nMedian age for employed males = " << computeMedianAge(fem_end, emp_ml_end);

	//unemployed males:
	std::cout << "\nMedian age for unemployed males = " << computeMedianAge(emp_ml_end, persons.end());
}
/*
Median age = 40
Median age for females = 40
Median age for males = 55
Median age for employed females = 40
Median age for unemployed females = 80
Median age for employed males = 55
Median age for unemployed males = 78
*/