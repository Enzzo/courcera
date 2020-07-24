#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main() {

	int n;
	std::cin >> n;
	std::string mode;

	std::map<std::string, std::vector<std::string>> bus_line;
	std::vector<std::string> buses;

	while (n-- > 0) {
		std::cin >> mode;

		if (mode == "NEW_BUS") {
			std::string bus;
			int count;
			std::cin >> bus >> count;
			std::vector<std::string>names(count);

			buses.push_back(bus);

			for (std::string& s : names) std::cin >> s;
			bus_line[bus] = names;

		}
		else if (mode == "BUSES_FOR_STOP") {
			std::string stop;
			std::cin >> stop;
			std::vector<std::string> output;

			for (const auto& b : buses) {
				for (const auto& s : bus_line[b]) {
					if (s == stop) {
						output.push_back(b);
						break;
					}
				}
			}
			if (output.size() == 0)
				std::cout << "No stop\n";
			else {
				for (const std::string& s : output) {
					std::cout << s << " ";
				}
				std::cout << std::endl;
			}
		}
		else if (mode == "STOPS_FOR_BUS") {
			std::string bus;
			std::cin >> bus;
			std::vector<std::string> output;
			//Если bus не найден
			if (bus_line.find(bus) == bus_line.end())
				std::cout << "No bus\n";
			else {
				//const std::vector<std::string>& stops = bus_line[bus];
				for (const auto& st : bus_line[bus]) {
					//костыли
					int count = 0;
					bool f = false;
					for (const auto& bl : buses) {

						//Если это первый элемент, то пишем Stop:
						if (!f) {
							f = true;
							std::cout << "Stop "<<st<<": ";
						} 
						if (std::count(bus_line[bl].begin(), bus_line[bl].end(), st) > 0 && bl != bus) {
							count++;
							std::cout << bl << " ";
						}
					}
					if (f == true && count == 0)std::cout << "no interchange";
					std::cout << std::endl;
				}
				//Stop [stop]: [bus_1] [bus_n] ...
				//Stop [stop]: no interchange
			}
		}
		else if (mode == "ALL_BUSES") {
			if (bus_line.size() > 0) {
				for (const std::pair<std::string, std::vector<std::string>>& p : bus_line) {
					std::cout << "Bus " << p.first << ": ";
					for (const std::string& s : p.second) {
						std::cout << s << " ";
					}
					std::cout << std::endl;
				}
			}
			else {
				std::cout << "No buses\n";
			}
		}
		//WRONG MODE:
		else {
			std::cout << "Wrong mode\n";
			n++;
		}
	}

	return 0;
}