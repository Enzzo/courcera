#include <iostream>
#include <fstream>
#include <iomanip>

int main() {

	std::ofstream ost("output.txt");
	if (ost.is_open()) {
		for (size_t i = 0; i < 1000000; i++) {
			std::right; 
			ost << 100000000 << std::endl;
		}
	}

	return 0;
}