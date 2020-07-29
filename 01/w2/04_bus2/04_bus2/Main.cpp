//Необходимо присвоить номера автобусным маршрутам.

#include <iostream>
#include <vector>
#include <string>
#include <map>

int main() {
	
	int q;
	std::cin >> q;
	std::map<std::vector<std::string>, int> bus_line;

	while (q-- > 0) {
		//cin >> (int)n >> (string) stops

		int n;
		std::cin >> n;
		std::string stop;
		std::vector<std::string> stops;

		for (int i = 0; i < n; i++) {
			std::cin >> stop;
			stops.push_back(stop);
		}
		int size = bus_line.size()+1;
		int contr = bus_line[stops];
		if (contr == 0) {
			bus_line[stops] = size;
			std::cout << "New bus " << bus_line.size() << std::endl;
		}
		else {
			std::cout << "Already exists for " << bus_line[stops] << std::endl;		
		}
	}
	
	return 0;
}