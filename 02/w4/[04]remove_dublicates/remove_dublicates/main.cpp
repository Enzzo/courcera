#include<algorithm>
#include<vector>
#include <iostream>
#include <set>

template<typename T>
void RemoveDuplicates(std::vector<T>&);

int main() {

	std::vector<int> v = { 5, 5, 1, 1, 2, 3, 4, 4 };

	RemoveDuplicates(v);

	for (const int i : v) {
		std::cout << i << ",  ";
	}

	return 0;
}

template<typename T>
void RemoveDuplicates(std::vector<T>& elements) {
	std::set<T> s(elements.begin(), elements.end());
	elements.assign(s.begin(), s.end());
};