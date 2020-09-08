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

//УДАЛИТЬ ДВОЙКУ В НАЗВАНИИ ФУНКЦИИ И ВНУТРИ ФУНКЦИИ!!!
template<typename RandomIt>
void MergeSort2(RandomIt begin, RandomIt end) {
	if (begin == end || begin + 1 == end || begin + 2 == end)return;

	//Создать вектор, содержащий все элементы текущего диапазона
	std::vector<RandomIt::value_type> elements(begin, end);

	//Разбить вектор на три равные части
	size_t step = elements.size() / 3;
	RandomIt mid1 = begin + step;
	RandomIt mid2 = mid1  + step;

	//Вызвать функцию MergeSort от каждой половины вектора
	MergeSort2(begin, mid1);
	MergeSort2(mid1, mid2);
	MergeSort2(mid2, end);

	elements.clear();

	//???
	std::sort(begin, end);
	//std::sort(mid, end);

	//С помощью алгоритма merge слить отсортированные половины, записав полученный отсортированный диапазон вместо исходного
	std::merge(begin, mid1, mid1, mid2, std::back_inserter(elements));
	
	elements.clear();
	std::merge(mid1, mid2, mid2, end, std::back_inserter(elements));

}

int main() {
	std::vector<int> v = { 6, 4, 7, 6, 4, 4, 0, 1, 5 };
	MergeSort2(begin(v), end(v));
	for (int x : v) {
		std::cout << x << " ";
	}
	std::cout << std::endl;

	return 0;
}