#include <iostream>
#include <string>
#include <vector>
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
		if (m.size() > 0) {
			for (std::map<int, fl>::iterator it = --m.end(); it != m.end(); --it) {
				if (it->first <= year) {
					if (fn.size() == 0) fn = it->second.first_name;
					if (sn.size() == 0) sn = it->second.last_name;
					if (fn.size() != 0 && sn.size() != 0) break;
				}
			}
		}
		return result(fn, sn);
	}
	
private:
	struct fl {
		std::string first_name = "";
		std::string last_name = "";
	};
	std::map<int, fl> m;
	fl e;
	std::map<int, fl>::iterator it;

	const std::string result(const std::string& s1, const std::string& s2) const {
		if (s1.size() == 0 && s2.size() == 0) return "Incognito";
		if (s1.size() == 0) return s2 + " with unknown last name";
		if (s2.size() == 0) return s1 + " with unknown first name";
		return s1 + " " + s2;
	}
};
int main() {
	return 0;
}