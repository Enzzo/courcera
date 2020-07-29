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
			std::string stop;
			std::cin >> stop;			
			bool f = false;

			for (const std::pair<std::string, std::vector<std::string>>& b : bus_line) {
				for (const std::string& s : b.second) {
					if (s == stop) {
						f = true;
						std::cout << b.first << " ";
					}
				}
			}			
			if (!f)std::cout << "No stop";
			std::cout << std::endl;
		}
		else if (mode == "STOPS_FOR_BUS") {
			std::string bus;
			std::cin >> bus;

			if (bus_line[bus].size() == 0) {
				std::cout << "No bus\n";
			}
			else {
				//TODO: “”“ ѕќ—Ћ≈ƒЌ≈≈!!!
				//копируем в вектор все stop этого bus, а потом с ним будем сравнивать остальные стопы бусов
				std::vector<std::string> stops = bus_line[bus];
				for (const std::pair < std::string, std::vector<std::string>>& p : bus_line) {
					
					//скипаем вектор, если он принадлежит контролькному бусу
					if (p.first == bus) break;
				}
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