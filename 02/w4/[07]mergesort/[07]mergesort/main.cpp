#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>

/*
Если диапазон содержит меньше 2 элементов, выйти из функции.
Создать вектор, содержащий все элементы текущего диапазона.
Разбить вектор на две равные части. 
(В этой задаче гарантируется, что длина передаваемого диапазона является степенью двойки, так что вектор всегда можно разбить на две равные части.)
Вызвать функцию MergeSort от каждой половины вектора.
С помощью алгоритма merge слить отсортированные половины, записав полученный отсортированный диапазон вместо исходного.
*/

//сортирует заданный диапазон с помощью сортировки слиянием
template<typename RandomIt>
void MergeSort(RandomIt begin, RandomIt end) {
	if (begin == end || begin + 1 == end)return;
	
	//Создать вектор, содержащий все элементы текущего диапазона
	std::vector<RandomIt::value_type> elements(begin, end);

	//Разбить вектор на две равные части
	RandomIt mid = begin + elements.size() / 2;

	//Вызвать функцию MergeSort от каждой половины вектора
	MergeSort(begin, mid);
	MergeSort(mid, end);

	elements.clear();

	//???
	std::sort(begin, end);
	//std::sort(mid, end);

	//С помощью алгоритма merge слить отсортированные половины, записав полученный отсортированный диапазон вместо исходного
	std::merge(begin, mid, mid, end, std::back_inserter(elements));

}

template<typename RandomIt>
void Test(RandomIt i) {
	std::advance(i);
}
int main() {
	std::vector<int> v{ 6, 4, 7, 6, 4, 4, 0, 1 };
	
	MergeSort(v.begin(), v.end());

	for (const int i : v)
		std::cout << i << " ";

	return 0;
}