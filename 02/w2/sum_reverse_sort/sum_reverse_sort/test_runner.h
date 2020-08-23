#pragma once
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <exception>
#include <sstream>

void Assert(bool, const std::string&);

class TestRunner {
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const std::string& test_name) {
        try {
            func();
            std::cerr << test_name << " OK" << std::endl;
        }
        catch (std::exception & e) {
            ++fail_count;
            std::cerr << test_name << " fail: " << e.what() << std::endl;
        }
        catch (...) {
            ++fail_count;
            std::cerr << "Unknown exception caught" << std::endl;
        }
    };

    ~TestRunner();

private:
    int fail_count = 0;
};