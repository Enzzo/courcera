#include <iostream>
#include <string>
#include <vector>
#include <fstream>

struct Student {
	std::string first_name;
	std::string second_name;
	long day;
	long month;
	long year;

	void FillProfile(std::ifstream& ist) {
		ist >> first_name >> second_name >> day >> month >> year;
	}

	void ShowName()const {
		std::cout << first_name << " " << second_name << std::endl;
	}
	void ShowDate()const {
		std::cout << day << "." << month << "." << year << std::endl;
	}
};

int main() {
	long n;
	std::ifstream ist("input.txt");

	ist >> n;
	std::vector<Student> st(n);

	for (long i = 0; i < n; i++) {
		st[i].FillProfile(ist);
	}
	ist >> n;

	std::string request;
	long s;
	for (long i = 0; i < n; i++) {
		ist >> request >> s;
		if (s > st.size() || s <= 0) std::cout << "bad request\n";
		else if (request == "name") {
			st[s - 1].ShowName();
		}
		else if (request == "date") {
			st[s - 1].ShowDate();
		}
		else {
			std::cout << "bad request\n";
		}
	}
	return 0;
}