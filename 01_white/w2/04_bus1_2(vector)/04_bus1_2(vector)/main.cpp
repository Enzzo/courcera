/*
	NEW_BUS bus stop_count stop1 stop2 ... � �������� ������� �������� � ��������� bus � stop_count ����������� � ���������� stop1, stop2, ...
	BUSES_FOR_STOP stop � ������� �������� ���� ��������� ��������, ���������� ����� ��������� stop.
	STOPS_FOR_BUS bus � ������� �������� ���� ��������� �������� bus �� ������� ���������, �� ������� ����� ��������� �� ������ �� ���������.
	ALL_BUSES � ������� ������ ���� ��������� � �����������.
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