#include "test_runner.h"

template<typename TestFunc>
void TestRunner::RunTest(const TestFunc& foo, const std::string& test_name) {
	try {
		foo();
		std::cerr << test_name<<" OK\n";
	}
	catch (std::exception& e) {
		++error_count;
		std::cerr << test_name << " fail: " << e.what() << std::endl;
	}
	catch (...) {
		++error_count;
		std::cerr << "Unknown exception caught" << std::endl;
	}
}

TestRunner::TestRunner() {};

TestRunner::~TestRunner() {
	if (error_count > 0) {
		std::cerr << error_count << " tests failed. Terminate\n";
	}
}

template<typename TestFunc, typename Result>
void AssertEqual(const TestFunc& foo, const Result& result, const std::string& hint = {}) {
	if (foo != result) {
		std::ostringstream os(hint);
		os << "Assertion failed: " << foo << " != " << result;
		if (!hint.empty())
			os << " " << hint;
		throw std::runtime_error(os.str());
	}
}

void Assert(bool b, const std::string& hint = {}) {
	AssertEqual(b, true, hint);
}

template<typename K, typename V>
std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m) {
	for (const std::pair<K, V>& p : m) {
		os << p.first << " " << p.second << std::endl;
	}
	return os;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
	for (const T& t : v)
		os << t << std::endl;;
	return os;
}

template<typename K, typename V>
std::ostream& operator<<(std::ostream& os, const std::pair<K, V>& p) {
	os << p.first << " " << p.second << std::endl;
	return os;
}