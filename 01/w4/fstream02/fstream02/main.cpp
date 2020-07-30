#include <iostream>
#include <fstream>
#include <string>

void FileToConsole(const std::string& path) {
	std::ifstream input(path);
	std::string line;

	if (input.is_open()) {
		while (std::getline(input, line))
			std::cout << line << "\n";
	}
}
void FileToFile(const std::string& source, const std::string& destination) {
	std::ifstream input(source);
	std::ofstream output(destination);
	std::string line;
	if (input.is_open())
		while (std::getline(input, line))
			output << line << "\n";
}

int main() {
	FileToConsole("input.txt");
	FileToFile("input.txt", "output.txt");
	return 0;
}