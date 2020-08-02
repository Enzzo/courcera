#include <fstream>

int main() {

	std::ofstream output("table.txt");

	for (int i = -10; i <= 10; i++) {
		for (int j = -10; j <= 10; j++) {
			if(j != 0)
				output << i << " " << j << "\n";
		}

	}

	return 0;
}