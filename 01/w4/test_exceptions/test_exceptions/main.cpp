#include <iostream>
#include <exception>

class testClass {
public:
	testClass(int x) {
		if (x == 0)throw std::invalid_argument("x == 0");
		if (x == 1)throw std::domain_error("x == 1");
	}
};

int main(){
	try {
		testClass t(0);
		return 1;
	}
	catch (std::invalid_argument e) {
		std::cout << e.what();

	}
	catch (std::domain_error e) {
		std::cout << e.what();
	}
	testClass t(1);
	return 0;
}
