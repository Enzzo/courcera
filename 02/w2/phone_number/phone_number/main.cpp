#include <iostream>
#include "phone_number.h"
#include "test_runner.h"

void Test1() {
	PhoneNumber n1("+7-111-11111111");
	Assert(n1.GetCountryCode() == "7", "001");
	Assert(n1.GetCityCode() == "111", "001");
	Assert(n1.GetLocalNumber() == "11111111", "001");

}

int main() {

	TestRunner r;
	r.RunTest(Test1, "Test1");
	return 0;
}