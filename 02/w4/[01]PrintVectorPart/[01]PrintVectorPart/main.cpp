#include <iostream>
#include <vector>
#include <algorithm>

void PrintVectorPart(const std::vector<int>& numbers) {

	//находим указатель на отрицательное число:
	auto it = std::find_if(numbers.begin(), numbers.end(), [](const int n) { return n < 0; });
	
	//выводим последовательность в обратном порядке:
	
	while (it != numbers.begin()) {
		--it;
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int main() {
	PrintVectorPart({ 1, 3, 5, -2 });
	PrintVectorPart({ -1, 2, 5 });
	PrintVectorPart({ 1, 6, 2, 4 });
	return 0;
}