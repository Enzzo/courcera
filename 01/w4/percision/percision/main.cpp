#include <iostream>
#include <fstream>
#include <iomanip>

int main() {

	const std::string& path = "input.txt";
	std::ifstream input(path);
	double d;
	

	if (input)
		while (input >> d)
			std::cout << std::setprecision(100) << d << std::endl;

	double x;

	return 0;
}