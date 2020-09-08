#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>

/*
���� �������� �������� ������ 2 ���������, ����� �� �������.
������� ������, ���������� ��� �������� �������� ���������.
������� ������ �� ��� ������ �����. 
(� ���� ������ �������������, ��� ����� ������������� ��������� �������� �������� ������, ��� ��� ������ ������ ����� ������� �� ��� ������ �����.)
������� ������� MergeSort �� ������ �������� �������.
� ������� ��������� merge ����� ��������������� ��������, ������� ���������� ��������������� �������� ������ ���������.
*/

//��������� �������� �������� � ������� ���������� ��������
template<typename RandomIt>
void MergeSort(RandomIt begin, RandomIt end) {
	if (begin == end || begin + 1 == end)return;
	
	//������� ������, ���������� ��� �������� �������� ���������
	std::vector<RandomIt::value_type> elements(begin, end);

	//������� ������ �� ��� ������ �����
	RandomIt mid = begin + elements.size() / 2;

	//������� ������� MergeSort �� ������ �������� �������
	MergeSort(begin, mid);
	MergeSort(mid, end);

	elements.clear();

	//???
	std::sort(begin, end);
	//std::sort(mid, end);

	//� ������� ��������� merge ����� ��������������� ��������, ������� ���������� ��������������� �������� ������ ���������
	std::merge(begin, mid, mid, end, std::back_inserter(elements));

}

//������� ������ � �������� ������� � ������ �������!!!
template<typename RandomIt>
void MergeSort2(RandomIt begin, RandomIt end) {
	if (begin == end || begin + 1 == end || begin + 2 == end)return;

	//������� ������, ���������� ��� �������� �������� ���������
	std::vector<RandomIt::value_type> elements(begin, end);

	//������� ������ �� ��� ������ �����
	size_t step = elements.size() / 3;
	RandomIt mid1 = begin + step;
	RandomIt mid2 = mid1  + step;

	//������� ������� MergeSort �� ������ �������� �������
	MergeSort2(begin, mid1);
	MergeSort2(mid1, mid2);
	MergeSort2(mid2, end);

	elements.clear();

	//???
	std::sort(begin, end);
	//std::sort(mid, end);

	//� ������� ��������� merge ����� ��������������� ��������, ������� ���������� ��������������� �������� ������ ���������
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