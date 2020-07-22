#include <iostream>
#include <map>
#include <vector>

int main(int args, char* argv) {

	int n;
	std::cin >> n;
	std::string mode;

	std::map<std::string, std::vector<std::string>> bus_line;

	while (n-- > 0) {
		std::cin >> mode;

		if (mode == "NEW_BUS") {
			std::string bus;
			int count;
			std::cin >> bus >> count;
			std::vector<std::string>names(count);

			for (std::string& s : names) std::cin >> s;
			bus_line[bus] = names;

		}
		else if (mode == "BUSES_FOR_STOP") {
			//OUTPUT
				//NO STOP
				//[bus_1] [bus_n] 
		}
		else if (mode == "STOPS_FOR_BUS") {
			//OUTPUT:
				//NO BUS
				//ÑÏÈÑÎÊ
					//Stop [stop]: [bus_1] [bus_n] ...
					//Stop [stop]: no interchange
		}
		else if (mode == "ALL_BUSES") {
			if (bus_line.size() > 0) {
				for (const std::pair<std::string, std::vector<std::string>>& p : bus_line) {
					std::cout << "Bus " << p.first << ": ";
					for (const std::string& s : p.second) {
						std::cout << s << " ";
					}					
				}
			}
			else {
				std::cout << "No buses";
			}
			std::cout << std::endl;
		}
		//WRONG MODE:
		else {
			n++;
		}
	}

	return 0;
}