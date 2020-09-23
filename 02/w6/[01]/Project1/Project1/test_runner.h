#pragma once
#include <string>
#include <iostream>

class TestRunner {
public:
	TestRunner();

	template<typename TestFunc>
	void RunTest(const TestFunc&, const std::string&);

	~TestRunner();
private:
	int error_count = 0;
};

template<typename TestFunc, typename Result>
void AssertEqual(const TestFunc&, const Result&, const std::string&);
void Assert(bool, bool, const std::string&);