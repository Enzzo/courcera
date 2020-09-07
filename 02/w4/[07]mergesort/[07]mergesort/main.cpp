#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>

/*
Если диапазон содержит меньше 2 элементов, выйти из функции.
Создать вектор, содержащий все элементы текущего диапазона.
Разбить вектор на две равные части. (В этой задаче гарантируется, что длина передаваемого диапазона является степенью двойки, так что вектор всегда можно разбить на две равные части.)
Вызвать функцию MergeSort от каждой половины вектора.
С помощью алгоритма merge слить отсортированные половины, записав полученный отсортированный диапазон вместо исходного.
*/

//сортирует заданный диапазон с помощью сортировки слиянием
template<typename RandomIt>
void MergeSort(RandomIt begin, RandomIt end) {
	if (begin == end || begin + 1 == end)return;

	std::vector<RandomIt::value_type> elements(begin, end);
	//std::sort(elements.begin(), elements.end());
	std::vector<RandomIt::value_type> v1(elements.begin(), elements.begin() + elements.size() / 2);
	std::vector<RandomIt::value_type> v2(elements.begin() + elements.size() / 2, elements.end());
	std::sort(v1.begin(), v1.end());
	std::sort(v2.begin(), v2.end());
	std::vector<RandomIt::value_type> res;
	std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(res));
	begin = res.begin();
	end = res.end();
}

int main() {
	std::vector<int> v{ 10, 8, 3 , 7, 7, 2, 1, 9, 2, 3};
	MergeSort(v.begin(), v.end());

	for (const int i : v)
		std::cout << i << " ";

	return 0;
}