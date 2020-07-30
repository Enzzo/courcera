#include <iostream>
#include <fstream>
#include <iomanip>

int main() {

	const std::string& path = "input.txt";
	std::ifstream input(path);
	double d;
	std::cout<<std::fixed;
	if (input)
		while (input >> d) {
			std::cout << std::setprecision(3)<<d << std::endl;
		}

	return 0;
}