#pragma once
#include <string>
#include <iostream>
#include <map>
#include <vector>

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
void Assert(bool, const std::string&);

template<typename K, typename V>
std::ostream& operator<<(std::ostream&, const std::map<K, V>&);

template<typename T>
std::ostream& operator<<(std::ostream&, const std::vector<T>&);

template<typename K, typename V>
std::ostream& operator<<(std::ostream&, const std::pair<K, V>&);