#include <iostream>
#include <string>
#include <algorithm>
#include <map>

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

		///////////////////////////////////////////////////////////////////////////////////
		
		if (m.size() > 0 ) {
			
			for (std::map<int, fl>::iterator it = m.begin(); it != m.end(); ++it) {
				if (it->first <= year) {
					if (it->second.first_name.size() != 0) fn = it->second.first_name;
					if (it->second.last_name.size()  != 0) sn = it->second.last_name;
				}
			}
		}
		///////////////////////////////////////////////////////////////////////////////////

		return result(fn, sn);
	}

private:
	struct fl {
		std::string first_name = "";
		std::string last_name = "";
	};
	std::map<int, fl> m;

	const std::string result(const std::string& s1, const std::string& s2) const {
		if (s1.size() == 0 && s2.size() == 0) return "Incognito";
		if (s1.size() == 0) return s2 + " with unknown first name";
		if (s2.size() == 0) return s1 + " with unknown last name";
		return s1 + " " + s2;
	}
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