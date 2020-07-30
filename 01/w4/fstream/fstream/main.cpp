#include <iostream>
#include <fstream>
#include <string>

void ReadAllFile(const std::string& path) {
	std::ifstream inp(path);
	
	if (inp) {
		std::string line;
		while (std::getline(inp, line))
			std::cout << line << std::endl;
		std::cout << "done\n";
	}
	else {
		std::cout << "Can't open file " << path << std::endl;
	}
}

int main() {

	const std::string path = "output.txt";
	std::ofstream out(path, std::ios::app);
	out << "first\n";
	out << "second\n";
	
	ReadAllFile(path);

	return 0;
}