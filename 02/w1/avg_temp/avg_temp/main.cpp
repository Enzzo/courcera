﻿/*
Даны значения температуры, наблюдавшиеся в течение N подряд идущих дней. Найдите номера дней
(в нумерации с нуля) со значением температуры выше среднего арифметического за все N дней.

Гарантируется, что среднее арифметическое значений температуры является целым числом.
Формат ввода

Вводится число N, затем N целых чисел — значения температуры в 0-й, 1-й, ... (N−1)-й день. Гарантируется, что N не превышает миллиона (10^6), 
а значения температуры, измеряющиеся в миллионных долях градусов по Цельсию, лежат в диапазоне от −10^8 до 10^8. Проверять соблюдение этих ограничений не нужно: 
вы можете ориентироваться на них при выборе наиболее подходящих типов для переменных.
Формат вывода

Первое число K — количество дней, значение температуры в которых выше среднего арифметического. Затем K целых чисел — номера этих дней.
Пример
Ввод

->
5
5 4 1 -2 7

<-
3
0 1 4
*/

#include <iostream>
#include <vector>
#include <fstream>

int main() {

	bool debug = false;
	std::ifstream ist("input.txt");

	unsigned int n;
	
	if(debug)
		ist >> n;
	else
		std::cin >> n;

	std::vector<int> temps(n);
	int t;
	int32_t avg;
	int64_t sum = 0;

	for (size_t i = 0; i < n; i++) {
		
		if(debug)
			ist >> t;
		else
			std::cin >> t;

		temps.at(i) = t;
		sum += static_cast<int64_t>(temps.at(i));
	}
	avg = static_cast<int32_t>(sum / static_cast<int64_t>(temps.size()));
	unsigned int c = 0;
	std::vector<int>res;
	for (size_t i = 0; i < temps.size(); i++) {
		if (temps.at(i) > avg) {
			c++;
			res.push_back(i);
		}
	}

	if (c > 0) {
		std::cout << c << std::endl;
		for (size_t i = 0; i < res.size(); i++) {
			std::cout << res.at(i)<<" ";
		}
	}
	return 0;
}