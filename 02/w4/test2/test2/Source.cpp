#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <functional>
#include <iostream>

int main() {
	
	const std::istream_iterator<std::string> start(std::cin);
	const std::istream_iterator<std::string> end;
	std::vector<std::string> strings(start, end);
	std::vector<std::string> more_strings(start, end);
	auto start_copy = start;
	++start_copy;
	std::cout << (start == start_copy) << std::endl;
	return 0;
}