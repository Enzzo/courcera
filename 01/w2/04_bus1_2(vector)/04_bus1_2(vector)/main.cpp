/*
	NEW_BUS bus stop_count stop1 stop2 ... — добавить маршрут автобуса с названием bus и stop_count остановками с названиями stop1, stop2, ...
	BUSES_FOR_STOP stop — вывести названия всех маршрутов автобуса, проходящих через остановку stop.
	STOPS_FOR_BUS bus — вывести названия всех остановок маршрута bus со списком автобусов, на которые можно пересесть на каждой из остановок.
	ALL_BUSES — вывести список всех маршрутов с остановками.
*/

#include <iostream>
#include <vector>
#include <map>
#include <string>

int main() {

	int n;
	std::cin >> n;

	std::vector<std::map<std::string, std::string>>bus_map;
	while (n-- > 0) {
		std::string mode;
		std::cin >> mode;

		if (mode == "NEW_BUS") {
			std::string bus;
			std::cin >> bus;

			int c;
			std::cin >> c;

			//bus_map.push_back(bus);
		}
		else if (mode == "BUSES_FOR_STOP") {

		}
		else if (mode == "STOPS_FOR_BUS") {

		}
		else if (mode == "ALL_BUSES") {

		}
	}


	return 0;
}