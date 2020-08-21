#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <utility>
#include <exception>
#include <sstream>
#include <set>
#include <map>

class TesterFramework {
public:
	template<typename Function>
	void RunTest(Function f, const std::string& test_name) try {
		f();
		std::cerr << test_name << " OK" << std::endl;
	}
	catch (std::runtime_error e) {
		std::cerr << test_name << " fail: " << e.what() << std::endl;
		error_count++;
	}
	catch (...) {
		error_count++;
	}
	~TesterFramework() {
		if (error_count > 0) {
			std::cerr << "ERROR COUNT: " << error_count << " \nPROGRAM TERMINATED\n";
			std::exit(1);
		}
	}
public:
	size_t error_count = 0;
};

template<typename T, typename U>
void AssertEqual(const T& t, const U& u, const std::string& hint = {}) {
	if (t != u) {
		std::ostringstream os;
		os << "Assertion failed: " << t << " != " << u;
		if (!hint.empty())
			os << " hint: " << hint;
		throw std::runtime_error(os.str());
	}
}

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

void EmptyPerson() {
	Person p;
	AssertEqual(p.GetFullName(0), "Incognito");
	AssertEqual(p.GetFullName(1000), "Incognito");
	AssertEqual(p.GetFullName(2000), "Incognito");
}

void OnlyFirstName() {
	Person p;
	p.ChangeFirstName(1000, "FirstName1");
	AssertEqual(p.GetFullName(0), "Incognito");
	AssertEqual(p.GetFullName(1000), "FirstName1 with unknown last name");
	AssertEqual(p.GetFullName(2000), "FirstName1 with unknown last name");

	p.ChangeFirstName(1500, "FirstName2");
	AssertEqual(p.GetFullName(0), "Incognito");
	AssertEqual(p.GetFullName(1000), "FirstName1 with unknown last name");
	AssertEqual(p.GetFullName(2000), "FirstName2 with unknown last name");

	p.ChangeFirstName(500, "FirstName3");
	AssertEqual(p.GetFullName(0), "Incognito");
	AssertEqual(p.GetFullName(900), "FirstName3 with unknown last name");
	AssertEqual(p.GetFullName(1000), "FirstName1 with unknown last name");
	AssertEqual(p.GetFullName(2000), "FirstName2 with unknown last name");

}

void OnlyLastName() {
	Person p;
	p.ChangeLastName(1000, "LastName1");
	AssertEqual(p.GetFullName(0), "Incognito");
	AssertEqual(p.GetFullName(1000), "LastName1 with unknown first name");
	AssertEqual(p.GetFullName(2000), "LastName1 with unknown first name");

	p.ChangeLastName(1500, "LastName2");
	AssertEqual(p.GetFullName(0), "Incognito");
	AssertEqual(p.GetFullName(1000), "LastName1 with unknown first name");
	AssertEqual(p.GetFullName(2000), "LastName2 with unknown first name");

	p.ChangeLastName(500, "LastName3");
	AssertEqual(p.GetFullName(0), "Incognito");
	AssertEqual(p.GetFullName(900), "LastName3 with unknown first name");
	AssertEqual(p.GetFullName(1000), "LastName1 with unknown first name");
	AssertEqual(p.GetFullName(2000), "LastName2 with unknown first name");
}

void FirstAndLastNames() {
	Person p;
	p.ChangeFirstName(1000, "FirstName1");
	p.ChangeLastName(1100, "LastName1");

	AssertEqual(p.GetFullName(0), "Incognito");
	AssertEqual(p.GetFullName(1000), "FirstName1 with unknown last name");
	AssertEqual(p.GetFullName(2000), "FirstName1 LastName1");

	p.ChangeFirstName(1500, "FirstName2");
	p.ChangeLastName(500, "LastName2");
	AssertEqual(p.GetFullName(0), "Incognito");
	AssertEqual(p.GetFullName(1000), "FirstName1 LastName2");
	AssertEqual(p.GetFullName(2000), "FirstName2 LastName1");
}

int main() {
	TesterFramework t;
	
	t.RunTest(EmptyPerson, "EmptyPerson");
	t.RunTest(OnlyFirstName, "OnlyFirstName");
	t.RunTest(OnlyLastName, "OnlyLastName");
	t.RunTest(FirstAndLastNames, "FirstAndLastNames");

	std::cout << std::endl;
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