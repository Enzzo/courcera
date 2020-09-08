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