#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
	std::vector<std::string> vs = { "Python", "C#", "C++" };
	auto result = std::find_if(vs.begin(), vs.end(), [](const std::string& s) {
		return s[0] == 'C';
		});
	std::cout << *result << std::endl;
	return 0;
}