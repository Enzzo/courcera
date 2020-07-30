#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

int main() {

	std::ifstream input("input.txt");
	
	if (input.is_open()) {
		int n, m;
		input >> n >> m;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int x; 
				input >> x;
				input.ignore(1);
				if (j != 0)std::cout << " ";
				std::cout << std::setw(2) << x;
			}
			if (i != n - 1)std::cout << std::endl;
		}
	}
	return 0;
}