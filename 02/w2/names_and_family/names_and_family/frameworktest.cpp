#include <iostream>
#include <vector>
#include <utility>
#include <exception>
#include <sstream>
#include <set>
#include <map>

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& t) {
	os << "{";
	bool first = true;
	for (const T& i : t) {
		if (!first) os << ", ";
		os << i;
		first = false;
	}
	os << "}";
	return os;
}

template<typename First, typename Second>
std::ostream& operator<<(std::ostream& os, const std::pair<First, Second>& p) {
	os << "{" << p.first << ", " << p.second << "}";
	return os;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& s) {
	os << "{";
	bool first = true;
	for (const T& t : s) {
		if (!first) os << ", ";
		os << t;
		first = false;
	}
	os << "}";
	return os;
}

template<typename First, typename Second>
std::ostream& operator<<(std::ostream& os, const std::map<First, Second> m) {
	os << "{";
	bool first = true;
	for (const std::pair<First, Second>& p : m) {
		if (!first) os << ", ";
		os << p.first<<": "<<p.second;
		first = false;
	}
	os << "}";
	return os;
}

class TesterFramework {
public:
	template<typename Function>
	void RunTest(Function f, const std::string& test_name) try{
		f();
		std::cerr << test_name << " OK" << std::endl;
	}
	catch (std::runtime_error e) {
		std::cerr << test_name << " fail: "<< e.what() << std::endl;
		error_count++;
	}
	catch (...) {
		error_count++;
	}
	~TesterFramework() {
		if (error_count > 0) {
			std::cerr << "ERROR COUNT: " << error_count<<" \nPROGRAM TERMINATED\n";
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