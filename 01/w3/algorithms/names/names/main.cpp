#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

class Person {
public:

	Person(const std::string& fn, const std::string& ln, const int year) {
		m[year].first_name = fn;
		m[year].last_name = ln;
	};

	void ChangeFirstName(const int year, const std::string& fn) {
		if(_year <= year)
			m[year].first_name = fn;
	};
	void ChangeLastName(const int year, const std::string& ln) {
		if(_year <= year)
			m[year].last_name = ln;
	};
	const std::string GetFullName(const int year)const {
		if (_year > year) return "No person";
		std::string fn, ln;

		if (m.size() > 0) {
			for (const auto& i : m) {
				if (i.first <= year) {
					if (i.second.first_name.size() > 0) {
						fn = i.second.first_name;
					}
					if (i.second.last_name.size() > 0) {
						ln = i.second.last_name;
					}
				}
			}
		}

		if (fn.size() == 0 && ln.size() == 0) {
			return "No person";
		}
		if (fn.size() == 0)
			return ln + " with unknown first name";
		if (ln.size() == 0) {
			return fn + " with unknown last name";
		}
		return fn + " " + ln;
	}
	const std::string GetFullNameWithHistory(const int year)const {
		if (_year > year) return "No person";
		std::string fn, ln;
		std::vector<std::string> first_names;
		std::vector<std::string> last_names;

		if (m.size() > 0) {
			for (const auto& i : m) {
				if (i.first <= year) {
					if (i.second.first_name.size() > 0) {
						fn = i.second.first_name;
						if (first_names.size() == 0) {
							first_names.push_back(fn);
						}
						else if (first_names.back() != fn)
							first_names.push_back(fn);
					}
					if (i.second.last_name.size() > 0) {
						ln = i.second.last_name;
						if (last_names.size() == 0) {
							last_names.push_back(ln);
						}
						else if (last_names.back() != ln)
							last_names.push_back(ln);
					}
				}
			}
			if(first_names.size() > 0)
				first_names.pop_back();
			if(last_names.size() > 0)
				last_names.pop_back();
		}

		if (fn.size() == 0 && ln.size() == 0) {
			return "No person";
		}
		if (fn.size() == 0) {
			return ln + history(last_names)+ " with unknown first name";
		}
		if (ln.size() == 0) {
			return fn + history(first_names)+ " with unknown last name";
		}
		return fn + history(first_names)+" " + ln + history(last_names);
	}
private:
	
	const std::string history(const std::vector<std::string>& v) const{
		std::string res;
		for (int i = v.size()-1; i >= 0; i--) {
			if (i == v.size()-1)
				res += " (";
			res += v[i];
			if (i == 0)
				res += ")";
			else
				res += ", ";
		}
		return res;
	}

	struct fl {
		std::string first_name;
		std::string last_name;
	};
	std::map<int, fl> m;
	int _year;
};
/*
int main() {
	Person person("Polina", "Sergeeva", 1960);
	for (int year : {1959, 1960}) {
		std::cout << person.GetFullNameWithHistory(year) << std::endl;
	}

	person.ChangeFirstName(1965, "Appolinaria");
	person.ChangeLastName(1967, "Ivanova");
	for (int year : {1965, 1967}) {
		std::cout << person.GetFullNameWithHistory(year) << std::endl;
	}
	return 0;
}*/
//Compile error : b'/tmp/submissionm3p8275g/main.cpp:164:24: fatal error: 
//\'this\' argument to member function \'GetFullNameWithHistory\' has type \'const Person\', 
//but function is not marked const\n        
//cout << \'"\' << person_ref.GetFullNameWithHistory(year) << \'"\' << endl;\n 