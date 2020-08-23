#include <iostream>
#include <set>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

template<typename T>
std::vector<T> FindGreaterElements(const std::set<T>& elements, const T& border) {
	auto it = std::find_if(elements.begin(), elements.end(), [&](const T& e) {return e > border; });
	
	std::vector<T> res;
	while (it != elements.end()) {
		res.push_back(*it++);
	}
	return res;
}
template<typename T>
void Show(const std::vector<T>& v) {
	for (const T t : v)
		std::cout << t << " ";
}

int main() {

	Show(FindGreaterElements({ 3, 2, 6, 2, 3, 4 }, 3));
	return 0;
}