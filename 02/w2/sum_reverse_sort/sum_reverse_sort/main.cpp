#include <iostream>
#include "sum_reverse_sort.h"
#include "test_runner.h"

void TestSum();
void TestReverseString();

int main() {

	TestRunner tr;
	tr.RunTest(TestSum, "TestSum");
	tr.RunTest(TestReverseString, "ReverseString");

	std::string Reverse(std::string s);

	void Sort(std::vector<int> & nums);

	return 0;
}

void TestSum() {
	Assert(Sum(3, 4) == 7, "sum = 7");
	Assert(Sum(0, 0) == 0, "sum = 0");
	Assert(Sum(-1, 3) == 2, "sum = 2");
}

void TestReverseString() {
	Assert(Reverse("hello") == "olleh", "olleh");
	Assert(Reverse("") == "", "EMPTY STRING");
	Assert(Reverse("  ") == "  ", "TWO SPACES");
}