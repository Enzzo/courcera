#include <iterator>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void PrintVector(const std::vector<T>& t) {
	for(const T & i : t) {
		std::cout << i << " ";
	}
};

int main() {

	std::vector<int> v1 = { 1, 2, 3, 4 };
	std::vector<int> v2(5);
	std::copy(v1.begin(), v1.end(), v2.begin());

	PrintVector(v2);

	return 0;
}