#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

std::string lower(const std::string&);

int main() {
	int n;
	std::cin >> n;
	std::vector<std::string> v(n);

	for (auto& i : v) {
		std::cin >> i;
	}
	std::sort(v.begin(), v.end(), [](std::string l, std::string r) {return lower(l) < lower(r); });
	for (const auto& i : v) {
		std::cout << i << " ";
	}
	return 0;
}

std::string lower(const std::string& s) {
	std::string res;
	for (const char& c : s) {
		res += tolower(c);
	}
	return res;
}