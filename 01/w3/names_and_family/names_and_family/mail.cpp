#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

class Person {
public:
	void ChangeFirstName(int year, const std::string& first_name) {
		m[year].first_name = first_name;
	}
	void ChangeLastName(int year, const std::string& last_name) {
		m[year].last_name = last_name;
	}
	std::string GetFullName(int year) {
		std::string fn, sn;
		if (m.size() > 0) {
			for (std::map<int, fl>::iterator it = m.begin(); it != m.end(); ++it) {
				if (it->first <= year) {
					if (it->second.first_name.size() != 0) fn = it->second.first_name;
					if (it->second.last_name.size() != 0) sn = it->second.last_name;
				}
			}
		}
		if (fn.size() == 0 && sn.size() == 0) return "Incognito";
		if (fn.size() == 0) return sn + " with unknown first name";
		if (sn.size() == 0) return fn + " with unknown last name";
		return fn + " " + sn;
	}
	std::string GetFullNameWithHistory(int year) {
		std::string fn, sn;
		std::vector<std::string> first_names;
		std::vector<std::string> last_names;

		if (m.size() > 0) {
			for (std::map<int, fl>::iterator it = m.begin(); it != m.end(); ++it) {
				if (it->first <= year) {
					if (it->second.first_name.size() != 0) fn = it->second.first_name;
					if (it->second.last_name.size() != 0) sn = it->second.last_name;
				}
			}
		}
	}

private:
	struct fl {
		std::string first_name = "";
		std::string last_name = "";
	};
	std::map<int, fl> m;
};

int main() {
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		std::cout << person.GetFullName(year) << std::endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		std::cout << person.GetFullName(year) << std::endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		std::cout << person.GetFullName(year) << std::endl;
	}
	return 0;
}