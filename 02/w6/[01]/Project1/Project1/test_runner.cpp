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

void Assert(bool l, bool r, const std::string& hint) {
	AssertEqual(l, r, hint);
}