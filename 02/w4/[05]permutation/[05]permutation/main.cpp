#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

int main() {
	std::vector<std::string> v{ "A", "B", "C"};
	
	while (std::next_permutation(v.begin(), v.end())) {
		for (const std::string& i : v)
			std::cout << i << " ";
		std::cout << std::endl;
	}


	return 0;
}