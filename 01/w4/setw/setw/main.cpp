#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

int main() {

	std::ifstream input("input.txt");

	int N;
	int M;
	std::string table;
	std::vector<std::string> data;

	input >> N;
	input >> M;

	if(input.is_open()){
		while (std::getline(input, table, ',')) {
			std::string temp = "";
			for (const char c : table) {
				if (c == '\n') {
					if(temp.size() > 0)data.push_back(temp);
					temp = "";
				}
				else temp += c;
			}
			if (temp.size() != 0)data.push_back(temp);
		}
	}
	for (int x = 0, i = 0; i < N; i++) {
		for (int j = 0; j < M; j++, x++) {
			std::cout << std::setw(10) << data[x];
		}
		std::cout<<std::endl;
	}
	return 0;
}